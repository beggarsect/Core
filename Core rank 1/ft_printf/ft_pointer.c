/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:46:09 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/05 14:46:12 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_p(size_t num)
{
	const char	*base;
	int			i;

	i = 0;
	base = "0123456789abcdef";
	if (num >= 16)
	{
		i += ft_p(num / 16);
		i += ft_p(num % 16);
	}
	else
		i += write(1, &base[num], 1);
	return (i);
}

int	ft_pointer(size_t num)
{
	int	i;

	i = 0;
	if (!num)
		i += write(1, "(nil)", 5);
	else
	{
		i += write(1, "0x", 2);
		i += ft_p(num);
	}
	return (i);
}
