/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:44:15 by mmakagon          #+#    #+#             */
/*   Updated: 2024/01/03 13:49:14 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_next(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	k = gnl_strlen(buffer) - i + 1;
	if (!buffer[i] || !k)
		return (free(buffer), NULL);
	i++;
	line = (char *)malloc((k + 1) * (sizeof(char)));
	while (buffer[i] && j < k)
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*gnl_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)gnl_calloc((i + 2), sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*gnl_join_n_free(char *src, char *buffer, size_t b)
{
	char	*result;
	size_t	a;

	a = gnl_strlen(src);
	if (!a && !b)
		return (free(src), NULL);
	result = (char *)malloc((a + b + 1) * sizeof(char));
	if (result)
	{
		gnl_strcpy(result, src);
		gnl_strcat(result, buffer);
	}
	else
		return (free(src), NULL);
	free(src);
	result[a + b] = '\0';
	return (result);
}

char	*gnl_read_file(int fd, char *src)
{
	char	*buffer;
	int		bytes_read;

	if (!src)
		src = gnl_calloc(1, 1);
	buffer = (char *)gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || !buffer)
		{
			free(buffer);
			return (free(src), NULL);
		}
		buffer[bytes_read] = '\0';
		src = gnl_join_n_free(src, buffer, bytes_read);
		if (!src || gnl_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (src);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = gnl_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = gnl_line(buffer[fd]);
	buffer[fd] = gnl_next(buffer[fd]);
	return (line);
}

// int main(void)
// {
//  int  fd;
//  char *line;

//  fd = open("empty", O_RDONLY);
//  while (1)
//  {
//   line = get_next_line(fd);
//   printf("%s", line);
//   if (line == NULL)
//    break ;
//   free(line);
//  }
//  return (0);
// }