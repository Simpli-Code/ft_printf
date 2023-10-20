/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:40:25 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/13 09:05:10 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_addres(va_list args)
{
	int				i;
	int				arr[16];
	int				count;
	char			*hex;
	unsigned long	num;

	i = 0;
	count = 0;
	hex = "0123456789abcdef";
	num = (unsigned long)va_arg(args, void *);
	if (num == 0)
		count = count + write (1, "(nil)", 5);
	else
	{
		count = count + write (1, "0x", 2);
		while (num)
		{
			arr[i] = hex[num % 16];
			num = num / 16;
			i++;
		}
		while (i > 0)
			count = count + write (1, &arr[--i], 1);
	}
	return (count);
}
