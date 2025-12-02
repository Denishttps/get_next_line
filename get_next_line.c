/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/12/02 15:38:33 by dbobrov           #+#    #+#             */
/*   Updated: 2025/12/02 15:38:33 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: dbobrov <dbobrov@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/12/02 13:09:00 by dbobrov           #+#    #+#             */
/*   Updated: 2025/12/02 13:09:00 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_line(int fd, char *buffer)
{
	ssize_t n;
	size_t j;
	size_t size_tmp;
	char *tmp;
	char *newline_pos;
	int loop;

	j = 0;
	size_tmp = BUFFER_SIZE + 1;
	tmp = malloc(size_tmp);
	if (!tmp)
		return (NULL);
	loop = 1;
	while (loop)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		newline_pos = ft_strchr(buffer, '\n');
		if (j + (size_t)n + 1 >= size_tmp)
		{
			tmp = ft_realloc(tmp, size_tmp, size_tmp + BUFFER_SIZE + n);
			if (!tmp)
				return (NULL);
			size_tmp += BUFFER_SIZE + n;
		}
		ft_memcpy(tmp + j, buffer, n);
		j += n;
		if (newline_pos)
			loop = 0;
	}
	if (j == 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	
}