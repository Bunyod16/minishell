/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:29:32 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/06/21 00:58:26 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "minishell.h"
#include "libft/libft.h"
#include <fcntl.h>

int	g_errno = 0;

static void	action(int sig)
{
	if (sig == SIGINT)
		ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	update_prompt(t_shell_info *info)
{
	char	*buf;
	char	*pwd;
	char	*user;
	char	*prompt;
	size_t	size;

	buf = 0;
	size = 0;
	pwd = getcwd(buf, size);
	user = get_env(&info->env, "USER");
	prompt = ft_strdup(user);
	add_substr(&prompt, ft_strlen(prompt), "@minishell ");
	add_substr(&prompt, ft_strlen(prompt), ft_strrchr(pwd, '/') + 1);
	free(pwd);
	add_substr(&prompt, ft_strlen(prompt), " $> ");
	info->prompt = prompt;
	info->infile = 0;
	info->outfile = 0;
	info->here_doc = 0;
	info->simple_commands = NULL;
}

void	free_mem(t_shell_info *info)
{
	int		i;
	int		j;

	if (info->outfile)
		free(info->outfile);
	if (info->infile)
		free(info->infile);
	if (info->here_doc)
		free(info->here_doc);
	i = 0;
	while (info->simple_commands && info->simple_commands[i].argv)
	{
		j = 0;
		while (info->simple_commands[i].argv \
			&& info->simple_commands[i].argv[j])
			free(info->simple_commands[i].argv[j++]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int				i;
	char			*line;
	t_list			*token_lst;
	t_shell_info	info;

	(void)argv;
	if (argc != 1)
		return (1);
	if (signal(SIGINT, action) == SIG_ERR || signal(SIGQUIT, action) == SIG_ERR)
		perror("signal error");
	info.env = init_env(envp);
	info.envp = set_envp(info.env);
	while (1)
	{
		update_prompt(&info);
		line = readline(info.prompt);
		free(info.prompt);
		if (!line || (ft_strlen(line) == 4 && !ft_strncmp(line, "exit", 4)))
			break ;
		if (!ft_strlen(line))
			continue ;
		quoter(&line);
		piper(&line);
		if (!line)
		{
			ft_putendl_fd("minishell: syntax error: unexpected end of file", 2);
			continue ;
		}
		add_history(line);
		spacer(&line);
		token_lst = lexer(&info.env, line);
		if (!is_syntax_cmd(token_lst)) // TODO: errno stuff here
			continue ;
		parser(&token_lst, &info);
		ft_lstclear(&token_lst, free);
		executor(&info); // TODO: handle builtins
		free(line);
	}
	rl_clear_history();
	env_clear(&info.env, free);
	i = 0;
	while (info.envp[i])
		free(info.envp[i++]);
	free(info.envp);
	free_mem(&info);
	ft_putendl_fd("exit", 1);
	return (0);
}
