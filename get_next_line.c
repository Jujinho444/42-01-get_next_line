/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aganz <aganz@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:28:28 by aganz             #+#    #+#             */
/*   Updated: 2025/12/08 22:38:24 by aganz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_stash(int fd, char *stash)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (stash && ft_strchr(stash, '\n'))
	{
		free(buffer);
		return (stash);
	}
	stash = ft_read_and_join(fd, stash, buffer);
	free(buffer);
	return (stash);
}

char	*ft_extract_line(char *stash)
{
	int		i;
	int		j;
	int		len_line;
	char	*line;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		len_line = i + 1;
	else
		len_line = i;
	line = malloc(len_line + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < len_line)
	{
		line[j] = stash[j];
		j++;
	}
	line[len_line] = '\0';
	return (line);
}

char	*ft_extract_remainder(char *stash)
{
	int		i;
	int		len_remainder;
	char	*new_stash;

	if (!stash || !ft_strchr(stash, '\n'))
	{
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\n')
		i++;
	len_remainder = ft_strlen(stash) - (i + 1);
	if (len_remainder <= 0)
	{
		return (NULL);
	}
	new_stash = malloc(len_remainder + 1);
	if (!new_stash)
		return (NULL);
	ft_memcpy(new_stash, stash + i + 1, len_remainder);
	new_stash[len_remainder] = '\0';
	free (stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*new_stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_fill_stash(fd, stash);
	if (!stash)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_extract_line(stash);
	if (!line)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	new_stash = ft_extract_remainder(stash);
	stash = new_stash;
	return (line);
}
