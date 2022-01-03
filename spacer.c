/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:44:21 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/01/03 12:39:55 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft/libft.h"

static int	is_metachar(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

void	spacer_before(char **line)
{
	int		i;
	char	quote;

	quote = 0;
	i = -1;
	while ((*line)[++i])
	{
		set_quote(&quote, (*line)[i]);
		if (!quote && i > 0 && is_metachar((*line)[i]) \
				&& (*line)[i - 1] != (*line)[i] && (*line)[i - 1] != ' ')
			add_substr(line, i++, " ");
	}
}

void	spacer_after(char **line)
{
	int		i;
	char	quote;

	quote = 0;
	i = -1;
	while ((*line)[++i])
	{
		set_quote(&quote, (*line)[i]);
		if (!quote && is_metachar((*line)[i]) && (*line)[i + 1] != (*line)[i] \
				&& (*line)[i + 1] != ' ')
		{
			add_substr(line, i + 1, " ");
			i += 2;
		}
	}
}

void	spacer(char **line)
{
	spacer_before(line);
	spacer_after(line);
}