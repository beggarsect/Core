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

static int	printf_operator(va_list arg, const char operator)
{
	int		len;

	len = 0;
	if (operator == 'c')
		len += ft_character(va_arg(arg, int));
	else if (operator == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (operator == 'p')
		len += ft_putptr(va_arg(arg, unsigned long long));
	else if (operator == 'd' || operator == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (operator == 'u')
		len += ft_putunsi(va_arg(arg, unsigned int));
	else if (operator == 'x' || operator == 'X')
		len += ft_puthex(va_arg(arg, int));
	else if (operator == '%')
		len += ft_putper();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	arg;

	i = 0;
	print_len = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_len += printf_operator(arg, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}
