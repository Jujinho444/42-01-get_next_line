/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganz <aganz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:34:05 by aganz             #+#    #+#             */
/*   Updated: 2025/12/09 23:24:02 by aganz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdst;
	const unsigned char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;

	if (!s2)
		return (NULL);
	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(joined, s1, len_s1);
	ft_memcpy(joined + len_s1, s2, len_s2);
	joined[len_s1 + len_s2] = '\0';
	return (joined);
}

char	*ft_read_and_join(int fd, char *stash, char *buffer)
{
	int		bytes_read;
	char	*tmp;

	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
		{
			free(stash);
			return (NULL);
		}
		free (stash);
		stash = tmp;
	}
	return (stash);
}
