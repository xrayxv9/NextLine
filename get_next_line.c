/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/21 12:54:40 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

static char *read_line(int fd, char *buffer)
{
	int		run;
	int		check;
	char	*line;

	run = 1;
	line = "\0";
	while (run)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buffer);
		if (ft_strchr('\n', line))
			break ;
	}
	return(line);
}

static char *check_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line)
		i++;
	new_line = malloc(i + 1);
	ft_strcpy(new_line, line);
	free(line);
	return (new_line);
}

void clean_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	while (buffer[i + j])
	{
		buffer[j] = buffer [i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*line;

	line = NULL;
	line = read_line(fd, buffer);
	line = check_line(line);
	clean_buffer(buffer);
	return (line);
}

#include <stdio.h>
int main ()
{
	const char	*PATH = "test.txt";
	int			fd = open(PATH, O_RDONLY);
	char		*line =  get_next_line(fd);
	int			i = 0;

	while (i <= 10)
	{
		printf("ligne %d --> %s", i, line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
