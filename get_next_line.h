/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbobrov <dbobrov@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:04 by dbobrov           #+#    #+#             */
/*   Updated: 2025/12/03 01:14:13 by dbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strlen(char	*str);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif