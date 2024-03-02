/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:31:13 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/14 13:41:37 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(va_list args)
{
	unsigned int	num;
	char			str[10];
	int				count;
	int				i;

	i = 0;
	count = 0;
	num = va_arg(args, unsigned int);
	if (num == 0)
		count = count + write (1, "0", 1);
	while (num)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		count = count + write (1, &str[i], 1);
	}
	return (count);
}
