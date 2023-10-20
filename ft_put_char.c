/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:05:34 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/13 09:06:36 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(va_list args)
{
	char	c;
	int		count;

	count = 0;
	c = (char)va_arg(args, int);
	if (c)
		count = write (1, &c, 1);
	if (c == 0)
		count = write (1, "\0", 1);
	return (count);
}
