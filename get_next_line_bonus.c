/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:17:50 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/15 10:32:51 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_document(char *buffer, char *saved, int fd)
{
	int	chars_read;

	chars_read = BUFFER_SIZE;
	if (ft_strlen(buffer) > 0)
		saved = ft_strjoin(saved, buffer);
	while (!ft_strchr(buffer, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
		{
			buffer[0] = '\0';
			free(saved);
			return (NULL);
		}
		buffer[chars_read] = '\0';
		saved = ft_strjoin(saved, buffer);
		if (!saved)
		{
			free(saved);
			return (NULL);
		}
	}
	return (saved);
}

char	*prepare_line(char *saved)
{
	char	*new_line;
	int		length;

	if (ft_strchr(saved, '\n'))
		length = ft_strchr(saved, '\n') - saved + 1;
	else
		length = ft_strlen(saved);
	if (length == 0)
	{
		free(saved);
		return (NULL);
	}
	new_line = (char *)malloc((sizeof(char) * length) + 1);
	if (!new_line)
	{
		free(saved);
		return (NULL);
	}
	ft_memcpy (new_line, saved, length);
	new_line[length] = '\0';
	free(saved);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char		buffer[FD_OPEN][BUFFER_SIZE + 1];
	char			*saved;

	saved = malloc(sizeof(char));
	if (!saved)
	{
		free (saved);
		return (NULL);
	}
	saved[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || FD_OPEN < fd)
		return (free(saved), NULL);
	saved = read_document(buffer[fd], saved, fd);
	if (saved == NULL)
		return (NULL);
	saved = prepare_line(saved);
	if (saved == NULL)
		return (NULL);
	if (ft_strchr(buffer[fd], '\n'))
	{
		ft_memcpy(buffer[fd], ft_strchr(buffer[fd], '\n') + 1, \
			ft_strlen(ft_strchr(buffer[fd], '\n') + 1) + 1);
	}
	return (saved);
}

/*int	main(void)
{
	char	*line;
	int		fd;
	char	*file_names[] = {"el_x_venir.txt", "ejemplo.txt", "ejemplo2.txt"};
	int		num_files;
	int		i;

	num_files = sizeof(file_names) / sizeof(file_names[0]);
	i = 0;
	while (i < num_files)
	{
		fd = open(file_names[i], O_RDONLY);
		i++;
		if (fd == -1)
		{
			write(2, "Can't open the file\n", 20);
			continue; move to the other file
		}
		printf("%s's content:\n", file_names[i]);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s\n", line);
			free(line);
		}
		close (fd);
		printf("\n");
	}
	return (0);
}*/