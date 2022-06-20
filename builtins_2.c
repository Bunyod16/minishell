/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyodshams <bunyodshams@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:01:47 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/06/21 01:13:21 by bunyodshams      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	env(t_shell_info *info)
{
	int	i;

	i = 0;
	while (info->envp[i])
	{
		printf("%s\n", info->envp[i++]);
	}
}
