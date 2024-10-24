/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:21 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 17:36:32 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_checkline(char *buffer, int fd);

int		ft_strlen(char *c);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strchr(char c, char *s);

char	*ft_strdup(char *s);

char	*get_next_line(int fd);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
