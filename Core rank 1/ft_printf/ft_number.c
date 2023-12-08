/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:03:28 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/04 12:03:34 by hienguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_recursion(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (i);
	i += ft_recursion(num / 10);
	ft_character((num % 10) + '0');
	return (i + 1);
}

int	ft_number(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
	{
		return (ft_string("-2147483648"));
	}
	else if (num == 0)
	{
		return (ft_character('0'));
	}
	else if (num < 0)
	{
		ft_character('-');
		num = -num;
		return (ft_recursion(num) + 1);
	}
	else
		return (ft_recursion(num));
}
