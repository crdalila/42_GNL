/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:29:17 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/04 10:55:41 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	buf[256];
	int		chars_read;

	fd = open("el_x_venir.txt", O_RDONLY);
	while ((chars_read = read(fd, buf, 25)))
	{
		buf[chars_read] = '\0';
		printf("buf %s\n", buf);
		//return (0) no se pone porque sino ENTIENDE QUE EL PROGRAMA SE HA TERMINADO Y SOLO TE LO HACE UNA VEZ!!! INCREÍBLE
	}
}
