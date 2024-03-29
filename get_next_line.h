/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:29 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/15 10:46:21 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 3
# endif //buffer_size

char	*get_next_line(int fd);
char	*read_document(char *buffer, char *saved, int fd);
char	*prepare_new_line(char *saved);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s1);
char	*ft_strchr(char *s, char c);
void	ft_memcpy(char *dest, char *src, size_t n);

# endif //librería