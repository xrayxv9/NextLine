/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:46 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/17 16:02:14 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*t;
	int		len;
	int		len2;
	int		i;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	t = malloc(len + len2 + 1);
	if (!t)
		return (NULL);
	i = 0;
	while (len > i)
	{
		t[i] = s1[i];
		i++;
	}
	while (len2 + len > i)
	{
		t[i] = (*s2)++;
		i++;
	}
	t[len + len2] = '\0';
	return (t);
}

int ft_strchr(char c, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_checkline(char *buffer, int fd)
{
	int		i;
	char	*line;

	
	i = 0;
	line = "\0";
	while (ft_strchr('\n', line) && ft_strchr('\0', buffer))
	{
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(buffer, line);
		printf("i --> %d\nline --> %s\n", i, line);
		i++;
	}	
	printf("yfgevwsjhfbesifn\n");
	return (line);
}

