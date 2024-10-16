/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:46 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/16 16:55:33 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_reset(int len, char *buffer)
{
	int	i;
	int cpy;

	i = 0;
	cpy = len;
	while (len >= i && buffer[i])
	{
		buffer[i] = buffer[cpy];
		cpy++;
		i++;
	}
	buffer[i] = '\0';
}

void	ft_check_line(char *buffer, char *line)
{
	int	i;

	i = 0;
	while (buffer[i] || buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	ft_reset(i, buffer);
}
