/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hienguye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:02 by hienguye          #+#    #+#             */
/*   Updated: 2023/12/05 14:48:04 by hienguye         ###   ########.fr       */
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

int	ft_unsigned(unsigned int num)
{
	if (num == 0)
	{
		return (ft_character('0'));
	}
	else
		return (ft_recursion(num));
}
