/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:26:10 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/07 16:38:38 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*saved; //el contenido de la caja
	static char		buffer[BUFFER_SIZE + 1]; //la caja
	int				chars_read; //número de characters leídos, donde guardamos el read
	char			*line;

	saved = malloc(1000 * sizeof(char));//todavía no sé de cuánto hacer el malloc
	if (!saved)
		return (NULL);
	chars_read = 1;
	while (chars_read > 0 && !ft_strchr(buffer, '\n')) //si no encuentra salto de línea
	{//si es 0 es que ya no hay archivo, así que es hasta que termine
		chars_read = read(fd, buffer, BUFFER_SIZE); //3
		if (chars_read < 0)
		{
			free(saved);
			return (NULL);
		}
		buffer[chars_read] = '\0'; //le añadimos nulo al final porque es algo que necesita
	// printf("Buffer: %s\n", buffer);
		saved = ft_strjoin(saved, buffer);
		if (!saved)
			return (NULL);
	}
	if (ft_strchr(saved, '\n')) //si saved tiene algo más que \n hay que reservar memoria para line
	{//tiene el tamaño del saved total MENOS un nuevo string que empieza desde que encuentra \n (lo que devuelve strchr)
		line = malloc((ft_strlen(saved) - ft_strlen(ft_strchr(saved, '\n'))) * sizeof(char));
		ft_memcpy(line, saved, (ft_strlen(saved) - ft_strlen(ft_strchr(saved, '\n'))));
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY); //abrimos documento
	if (fd == -1) //si no hay fd, error
	{
		write(2, "Can't open the file\n", 20);
		return (1);
	}
	/*while ((line = get_next_line(fd)) != NULL) //siempre que la línea tenga algo y no sea nula, o sea no se termine.
	{//esto hará que en cada while vayamos a una línea distinta. si lo declarámos arriba, tendríamos que poner abajo que vuelva a hacerlo cada vez que entra al while
		printf("%s\n", line);
		free(line);
	}*/
	line = get_next_line(fd);
	if (line)
	{
		printf("%s\n", line);
		free(line);
	}
	close (fd);
	return (0);
}