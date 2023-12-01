/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:27:47 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/01 14:27:49 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	arg;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}
