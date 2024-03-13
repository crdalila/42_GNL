//imprimir las 3 primeras letras

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*saved;
	char	buffer[BUFFER_SIZE + 1];
	int		chars_read;
	int		i;

	chars_read = read(fd, buffer, BUFFER_SIZE);
	buffer[chars_read] = '\0';
	saved = malloc((BUFFER_SIZE) * sizeof(char));
	i = 0;
	while (buffer[i])
	{	
		saved[i] = buffer[i];
		i++;
	}
	saved[i] = '\0';
	return (saved);
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
	printf("%s\n", line);
	close (fd);
	return (0);
}