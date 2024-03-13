/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:37:29 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/12 16:13:07 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*read_document(char *buffer, char *saved, int fd);
char	*prepare_new_line(char *saved);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s1);
char	*ft_strchr(char *s, char c);
void	ft_memcpy(char *dest, char *src, size_t n);
