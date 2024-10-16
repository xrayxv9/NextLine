/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:27:16 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/16 13:56:00 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int main()
{
	const char *PATH = "test.txt";
	char *buffer;
	int fd = open(PATH, O_RDONLY);
	buffer = malloc(6 *sizeof(char));
	read(fd, buffer, 2);
	printf("%s\n", buffer);
	read(fd, buffer, 2);
	printf("%s\n", buffer);

	free(buffer);
}
