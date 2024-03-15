/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:17:48 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/15 09:37:02 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif //buffer_size

# ifndef FD_OPEN
#  define FD_OPEN 256
# endif //fd_open

char	*get_next_line(int fd);
char	*read_document(char *buffer, char *saved, int fd);
char	*prepare_new_line(char *saved);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s1);
char	*ft_strchr(char *s, char c);
void	ft_memcpy(char *dest, char *src, size_t n);

#endif //library