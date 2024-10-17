/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/16 17:08:43 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


char *get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*line;
	
	if (buffer[0])
	{
		// Il faut verifie que je sois bien a un \n
		while ()




		return (line);

	}
	else 
	{
		read(fd, buffer, BUFFER_SIZE);
		line = malloc(BUFFER_SIZE);
		if (!line)
			return (NULL);
		ft_check_line(buffer, line, fd);
		return (line);
	}
}

int main ()
{
	const char	*PATH = "test.txt";
	int			fd = open(PATH, O_RDONLY);
	char		*line =  get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
