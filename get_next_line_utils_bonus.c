/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalcabre <dalcabre@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 09:17:44 by dalcabre          #+#    #+#             */
/*   Updated: 2024/03/15 09:23:55 by dalcabre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
	{
		free (s3);
		free (s1);
		return (NULL);
	}
	ft_memcpy(s3, s1, s1_len);
	ft_memcpy((s3 + s1_len), s2, s2_len);
	s3[s1_len + s2_len] = '\0';
	free(s1);
	return (s3);
}

int	ft_strlen(char *s1)
{
	size_t	i;

	i = 0;
	if (!s1 || *s1 == '\0')
		return (0);
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c || c == '\0')
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}
