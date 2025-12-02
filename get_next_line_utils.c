/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:19:27 by dbobrov           #+#    #+#             */
/*   Updated: 2025/12/02 14:24:31 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_realloc:
** Перераспределяет блок памяти, на который указывает ptr.
**
** 1. Если ptr == NULL, функция работает как malloc(new_size).
** 2. Если new_size == 0, функция работает как free(ptr) и возвращает NULL.
** 3. В остальных случаях она выделяет новую память, копирует данные
** (с учетом меньшего из двух размеров) и освобождает старый блок.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_len;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (old_size < new_size)
		copy_len = old_size;
	else
		copy_len = new_size;
	ft_memcpy(new_ptr, ptr, copy_len);
	free(ptr);
	return (new_ptr);
}
