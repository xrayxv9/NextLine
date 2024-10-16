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
	
	if (!buffer[0])
	{

	}
	else 
	{
		read(fd, buffer, BUFFER_SIZE);
		ft_check_line(line, buffer);

		return (line);
	}
	return (line);
}

int main ()
{
	const char *PATH = "test.txt";
	int fd = open(PATH, O_RDONLY);


}
