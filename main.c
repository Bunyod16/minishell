/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:29:32 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/24 16:55:18 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libreadline/history.h"
#include "libreadline/readline.h"

static void	action(int sig)
{
	if (sig == SIGINT)
		return ;
}

static void	eof(void)
{
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("Saving session...", 1);
	ft_putendl_fd("...copying shared history...", 1);
	ft_putendl_fd("...saving history...truncating history files...", 1);
	ft_putendl_fd("...completed.", 1);
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("[Process completed]", 1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argv;
	(void)envp;
	if (argc != 1)
		return (1);
	signal(SIGINT, action);
	signal(SIGQUIT, action);
	while (1)
	{
		line = readline("minishell $> ");
		if (!line || !ft_strncmp(line, "exit", ft_strlen(line)))
			break ;
		printf("%s\n", line);
		free(line);
	}
	eof();
	return (0);
}
