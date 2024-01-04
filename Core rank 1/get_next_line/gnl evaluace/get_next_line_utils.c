/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:44:19 by mmakagon          #+#    #+#             */
/*   Updated: 2023/09/15 11:32:41 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	b;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		p = malloc(0);
		return (p);
	}
	else
	{
		b = nmemb * size;
		if (b / nmemb != size)
			return (NULL);
		p = malloc(nmemb * size);
		if (!p)
			return (NULL);
		while (i < b)
			p[i++] = '\0';
		return (p);
	}
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (char)c;
	while (*s != ch && *s != '\0')
		s++;
	if (*s == ch)
		return ((char *)s);
	else
		return (0);
}

char	*gnl_strcpy(char *dest, const char *src)
{
	char	*new_dest;

	if (!dest && !src)
		return (NULL);
	new_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (new_dest);
}

char	*gnl_strcat(char *dest, const char *src)
{
	char	*new_dest;

	if (!dest && !src)
		return (NULL);
	new_dest = dest;
	while (*new_dest != '\0')
		new_dest++;
	while (*src != '\0')
		*new_dest++ = *src++;
	*new_dest = '\0';
	return (dest);
}
