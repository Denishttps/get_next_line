/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:55:58 by dbobrov           #+#    #+#             */
/*   Updated: 2025/12/03 00:55:58 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stash(char *stash)
{
	char	*newline;
	char	*new_stash;
	size_t	start;

	newline = ft_strchr(stash, '\n');
	if (!newline || !*(newline + 1))
	{
		free(stash);
		return (NULL);
	}
	start = (newline - stash) + 1;
	new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
	free(stash);
	return (new_stash);
}

static char	*create_line(char *stash)
{
	char	*newline;
	char	*line;
	size_t	len;

	if (!stash || !*stash)
		return (NULL);
	newline = ft_strchr(stash, '\n');
	if (newline)
		len = (newline - stash) + 2;
	else
		len = ft_strlen(stash) + 1;
	line = (char *)malloc(len);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len - 1);
	line[len - 1] = '\0';
	return (line);
}

static char	*read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	n;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free(buffer), free(stash), NULL);
		if (n == 0)
			break ;
		buffer[n] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = create_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}
