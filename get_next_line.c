/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/17 15:58:40 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*line;

	line = NULL;
	if (!fd)
		return (NULL);
	if (buffer[0])
	{

		return (line);
	}
	else 
		line = ft_checkline(buffer, fd);
	return (line);
}

int main ()
{
	const char	*PATH = "test.txt";
	int			fd = open(PATH, O_RDONLY);
	char		*line =  get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
