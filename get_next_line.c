/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/16 13:55:58 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char *fill(int len, char *buffer, char *line);

static char *buff(char *buffer, int fd, int buffer_size)
{
	int i;
	char *line;
	static char *last;

	read(fd, buffer, buffer_size);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	last = malloc(buffer_size - i);
	if (!last)
		return (NULL);
	if (*buffer == '\n')
	{
		line = malloc ((i + 1) * sizeof(char));
		fill(buffer_size - i, last, buffer + i + 1);
		fill(i, buffer, line);
	}
	return (buffer);
}

static char *fill(int len, char *buffer, char *line)
{
	int i;

	len = 0;
	while(len >= i)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *r(int fd, int buffer_size)
{
	static char *buffer;
}

int main ()
{
	const char *PATH = "test.txt";
	int fd = open(PATH, O_RDONLY);


}
