/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:49:20 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/05 12:26:47 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*--------------------------------------------------------------------*/
/*Función to append the read buffer data to the partial content (line)*/
/*--------------------------------------------------------------------*/

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

/*-------------------------------------------------------*/
/*Función para convertir e imprimir la nueva línea como ?*/
/*-------------------------------------------------------*/

void	print_newline_helper(char *buffer)
{
	while (*buffer && *buffer != '\0')
	{
		if (*buffer == '\n')
			*buffer = '\\';
		printf("%c", *buffer);
		buffer++;
	}
}

/*-----------------------------------------------------------------*/
/*Función para leer del archivo y que aparezca en contenido parcial*/
/*-----------------------------------------------------------------*/
static char	*read_from_file(char *basin_buffer, int fd)
{
	int			chars_read;
	char		*cup_buffer;

	cup_buffer = ft_calloc (BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(cup_buffer), NULL);
		cup_buffer[chars_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'));
			break;
	}
	free(cup_buffer);
	return (basin_buffer);
}

/*-----------------------------------------------------------------*/
/*Función GNL para conseguir la siguiente línea del file descriptor*/
/*-----------------------------------------------------------------*/

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (basin_buffer);
}
