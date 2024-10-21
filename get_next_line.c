/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/21 18:18:31 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

static char *read_line(int fd, char *buffer)
{
	int		run;
	char	*line;
	char	*tmp;
	
	run = 1;
	if (!buffer)	
		buffer = ft_calloc(1, 1);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (run > 0)
	{
		run = read(fd, line, BUFFER_SIZE);
		if (run == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		tmp = ft_strjoin(buffer, line);
		free(buffer);
		buffer = ft_strdup(tmp);
		free(tmp);
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
	new_line = ft_strdup(line);
	if (!new_line)
		return (NULL);
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
		while (buffer[i + j])
			j++;
	save = malloc((j + 2) * sizeof(char));
	j = -1;
	i++;
	while (buffer[i + (++j)])
		save[j] = buffer [i + j];
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
	if (buffer[0])
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
		free(line);	
		line = get_next_line(fd);
		i++;
	}
	free(line);
}
