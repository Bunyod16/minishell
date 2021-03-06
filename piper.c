/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piper.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:30:37 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/10 22:48:10 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "minishell.h"
#include "libft/libft.h"

static int	pipe_is_last(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '|')
		return (1);
	return (0);
}

static char	*readline_pipe(char **line)
{
	char	*ret;
	char	*tmp;
	char	*line_2;

	line_2 = readline("pipe $> ");
	if (!line_2)
	{
		free(*line);
		*line = 0;
		return (0);
	}
	tmp = ft_strjoin(*line, "\n");
	free(*line);
	ret = ft_strjoin(tmp, line_2);
	free(tmp);
	free(line_2);
	*line = ret;
	return (ret);
}

void	piper(char **line)
{
	char	*str;

	if (!*line)
		return ;
	str = *line;
	while (pipe_is_last(str))
	{
		str = readline_pipe(line);
		if (!*line)
			break ;
		quoter(line);
		str = *line;
	}
}
