/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:46 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/21 12:42:13 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	if (!c)
		return (0);
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
		t[i] = *(s2++);
		i++;
	}
	t[len + len2] = '\0';
	return (t);
}

int	ft_strchr(char c, char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		if (*src == '\n')
			break;
		dest++;
		src++;
	}
	dest++;
	*dest = '\0';
}
