/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:21 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/21 17:00:06 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_checkline(char *buffer, int fd);

int		ft_strlen(char *c);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strchr(char c, char *s);

void	ft_strcpy(char *dest, char *src);

char	*get_next_line(int fd);

#endif
