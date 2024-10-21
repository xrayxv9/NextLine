/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/21 17:16:28 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

static char *read_line(int fd, char *buffer)
{
	int		run;
	char	*line;

	run = 1;
	if (!buffer)
	{	
		buffer = malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	line = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	while (run > 0)
	{
		run = read(fd, line, BUFFER_SIZE);
		if (run == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line[run] = '\0';
		buffer = ft_strjoin(buffer, line);
		if (ft_strchr('\n', line))
			break ;
	}
	free(line);
	return(buffer);
}

static char *check_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	ft_strcpy(new_line, line);
	return (new_line);
}

char *clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	j = 0;
	save = NULL;
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] != '\0')
	{
		while (buffer[i + j])
			j++;
	}
	save = malloc((j + 2) * sizeof(char));
	j = 0;
	i++;
	while (buffer[i + j])
	{
		save[j] = buffer [i + j];
		j++;
	}
	free(buffer);
	save[j] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	line = NULL;
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = check_line(buffer);
	buffer = clean_buffer(buffer);
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
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
