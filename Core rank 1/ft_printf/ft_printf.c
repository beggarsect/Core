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

#include "ft_printf.h"

int	printf_operator(va_list arg, const char operator)
{
	int		len;

	len = 0;
	if (operator == 'c')
		len += ft_character(va_arg(arg, int));
	else if (operator == 's')
		len += ft_string(va_arg(arg, char *));
	else if (operator == 'p')
		len += ft_pointer(va_arg(arg, size_t));
	else if (operator == 'd' || operator == 'i')
		len += ft_number(va_arg(arg, int));
	else if (operator == 'u')
		len += ft_unsigned(va_arg(arg, unsigned int));
	else if (operator == 'x' || operator == 'X')
		len += ft_hexadecimal(va_arg(arg, int));
	else if (operator == '%')
		len += ft_percentage();
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
			print_len += ft_character(str[i]);
		i++;
	}
	va_end(arg);
	return (print_len);
}

int	main(void)
{
	char	c = 'a';
	char	*string = "324";
	char	*ptr;
	int		num = -2147483648;

	ft_printf("strn: %s\n", string);
	printf("orig: %s\n\n", string);

	ft_printf("char: %c\n", c);
	printf("orig: %c\n\n", c);

	ft_printf("pntr: %p\n", ptr);
	printf("orig: %p\n\n", ptr);

	ft_printf("nmbr: %i\n", num);
	printf("orig: %i\n\n", num);
}