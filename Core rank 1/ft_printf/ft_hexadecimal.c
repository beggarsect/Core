/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:47:56 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/05 14:47:57 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p(size_t num, char x)
{
	const char	*base;
	int			i;

	i = 0;
	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		i += ft_p(num / 16, x);
		i += ft_p(num % 16, x);
	}
	else
		i += write(1, &base[num], 1);
	return (i);
}

int	ft_hexadecimal(unsigned int num, char x)
{
	int	i;

	i = 0;
	if (num == 0)
		return (ft_character('0'));
	i += ft_p(num, x);
	return (i);
}
