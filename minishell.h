/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 12:59:53 by bshamsid          #+#    #+#             */
/*   Updated: 2021/12/25 14:08:43 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READLINE_LIBRARY 1

typedef struct s_shell_info
{
	int		envp_len;
	char	*pwd;
	char	*user;
	char	*prompt;
	char	**envp;
	char	**paths;
}	t_shell_info;

/* execute_binary.c */
int	run_binary(char *binary, char **args, t_shell_info *info);

#endif
