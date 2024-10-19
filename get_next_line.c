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

static char	*checked(char *line)
{
	int		i;
	char	*checked_line;

	checked_line = NULL;
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	checked_line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strcpy(checked_line, line, 0);
	free(line);
	return (checked_line);
}

static char	*ft_checkbuffer(char *buffer, int fd)
{
	int		i;
	char	*tmp;
	char	*line;

	line = "\0";
	tmp = "\0";
	i = 0;
	while (buffer[i] != '\n')
		i++;
	line = malloc((ft_strlen(buffer + i) + 1));
	if (!line)
		line = "\0";
	ft_strcpy(line, buffer, i + 1);
	while (!(ft_strchr('\n', line)) && !(ft_strchr('\0', buffer)))
	{
		read(fd, buffer, BUFFER_SIZE);
		tmp = ft_strjoin(line, buffer);
		if (*line)
			free(line);
		line = malloc((ft_strlen(tmp) + 1) * sizeof(char));
		ft_strcpy(line, tmp, 0);
		free(tmp);
	}
	return (checked(line));
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	char			*line;

	line = NULL;
	if (!fd)
		return (NULL);
	if (buffer[0])
		line = ft_checkbuffer(buffer, fd);
	else
		line = ft_checkline(buffer, fd);
	return (line);
}

#include <stdio.h>
int main ()
{
	const char	*PATH = "test.txt";
	int			fd = open(PATH, O_RDONLY);
	char		*line =  get_next_line(fd);
	printf("first line--> %s", line);
	free(line);
	line = get_next_line(fd);
	printf("second line--> %s",line);
	free(line);
}
