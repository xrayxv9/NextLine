/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:21 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/16 16:56:16 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

void	ft_reset(int len, char *buffer);

void	ft_check_line(char *buffer, char *line, int fd);

char	*ft_modify(char *line, int len,char *buffer);

char	*get_next_line(int fd);

#endif
