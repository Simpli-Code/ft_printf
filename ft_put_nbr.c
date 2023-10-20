/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:36:03 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/14 13:45:09 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_negative(int num, int count)
{
	int				i;
	char			str[10];
	unsigned int	temp;

	i = 0;
	if (num == 0)
		count = count + write (1, "0", 1);
	if (num < 0)
	{
		count = count + write (1, "-", 1);
		num = -num;
		temp = num;
		while (temp)
		{
			str[i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}
		while (i > 0)
		{
			i--;
			count = count + write (1, &str[i], 1);
		}
	}
	return (count);
}

int	ft_put_nbr(va_list args)
{
	char	str[10];
	int		count;
	int		num;
	int		i;

	i = 0;
	count = 0;
	num = va_arg(args, int);
	if (num == 0 || num < 0)
		count = ft_num_negative(num, count);
	if (num > 0)
	{
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
	}
	return (count);
}

/*
https://www.techiedelight.com/return-multiple-values-function-c/
*/