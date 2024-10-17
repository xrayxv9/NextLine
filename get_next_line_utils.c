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

void	ft_check_line(char *buffer, char *line, int fd)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && i <= BUFFER_SIZE)
	{
		if (line)
			line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != EOF && buffer[i] != '\n')
	{
		get_next_line(fd);
		return ;
	}
	if (line)
	{
		line[i] = '\0';
		ft_reset(i, buffer);
	}
}

char	*ft_modify(char *line, int len,char *buffer)
{
	char *new_line;
	int i;

	i = 0;
	new_line = malloc(len + 1);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while(buffer[i])
	{
		new_line[i] = buffer[i];
		i++;
	}
	new_line[i] = '\0';
	printf("line --> %s\n new_line --> %s\n", line, new_line);
	free(line);
	return (new_line);
}
