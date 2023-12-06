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

int	ft_number(int n)
{
	if (n == -2147483648)
	{
		ft_string("-2147483648");
		return (0);
	}
	else if (n < 0)
	{
		ft_character('-');
		ft_number(-n);
	}
	else if (n > 9)
	{
		ft_number(n / 10);
		ft_character(n % 10 + '0');
	}
	else
		ft_character(n + '0');
	return (0);
}
