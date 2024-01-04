/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:44:18 by mmakagon          #+#    #+#             */
/*   Updated: 2023/09/18 13:51:31 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*get_next_line(int fd);
char	*gnl_next(char *buffer);
char	*gnl_line(char *buffer);
char	*gnl_join_n_free(char *src, char *buffer, size_t b);
char	*gnl_read_file(int fd, char *src);
size_t	gnl_strlen(const char *str);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strcpy(char *dest, const char *src);
char	*gnl_strcat(char *dest, const char *src);

#endif