/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_upp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:31:30 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/13 10:26:23 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex_upp(va_list args)
{
	unsigned int	num;
	char			*hex;
	int				count;
	int				arr[10];
	int				i;

	i = 0;
	count = 0;
	hex = "0123456789ABCDEF";
	num = va_arg(args, unsigned int);
	if (num == 0)
		count = count + write (1, "0", 1);
	while (num)
	{
		arr[i] = num % 16;
		num = num / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		count = count + write (1, &hex[arr[i] % 16], 1);
	}
	return (count);
}
