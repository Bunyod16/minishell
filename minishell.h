/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:59:53 by bshamsid          #+#    #+#             */
/*   Updated: 2022/01/03 17:54:15 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY 1

# include "libft/libft.h"

typedef struct s_env_list
{
	char				*key;
	char				*value;
	char				*full;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_shell_info
{
	char		*pwd;
	char		*user;
	char		*prompt;
	char		**envp;
	char		**paths;
	t_env_list	*env;
}	t_shell_info;

/* env.c */
t_env_list	*init_env(char **envp);
char		**set_envp(t_env_list **env);
char		*get_env(t_env_list **env, char *key);
void		set_env(t_shell_info *info, char *str);
void		unset_env(t_shell_info *info, char *key);

/* env_utils.c */
t_env_list	*env_new(char *str);
void		env_add_back(t_env_list **env, t_env_list *new);
void		env_del(t_env_list *env, void (*del)(void *));

/* quotes.c */
void		set_quote(char *quote, char c);
void		quoter(char **line);
void		dequoter(char **line);

/* spacer.c */
void		spacer(char **line);

/* lexer.c */
t_list		*lexer(char *line);

/* str_utils.c */
void		add_substr(char **str, int start, char *substr);
void		rm_substr(char **str, int start, int len);

#endif
