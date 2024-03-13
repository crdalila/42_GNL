/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:55 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/01 10:55:58 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int fd;
	char *buffer;
	int size = 0;

	buffer = (char *)malloc(MAX_BUFFER_SIZE);
	if (!buffer)
	{
		write(2, "Memory assigment error", 23);
		return (1);
	}
	fd = open ("el_x_venir.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot open file", 17);
		free (buffer);
		return (1);
	}
	size = read(fd, buffer, MAX_BUFFER_SIZE);
	if (size == -1)
	{
		write(2, "Cannot read file", 17);
		free (buffer);
		close (fd);
		return (1);
	}
	if (write(1, buffer, size) == -1)
	{
		write(2, "Cannot write in standart output", 31);
		free (buffer);
		close (fd);
		return (1);
	}
	free (buffer);
	close (fd);
	return (0);
}
