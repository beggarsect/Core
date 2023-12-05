/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:29:10 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/01 14:29:13 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
void	ft_character(char character, int *len);
void	ft_number(int n, int *len);
void	ft_string(char *args, int *len);
void	ft_pointer(size_t pointer, int *len);
void	ft_unsigned(unsigned int u, int *len);
void	ft_hex(unsigned int x, int *len, char x_or_x);

#endif
