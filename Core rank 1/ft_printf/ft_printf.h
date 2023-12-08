/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:29:10 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/01 14:29:13 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_character(int c);
int		ft_number(int num);
int		ft_string(char *str);
int		ft_pointer(unsigned long num);
int		ft_unsigned(unsigned int num);
int		ft_hexadecimal(unsigned int num, char x);

#endif
