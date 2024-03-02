/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 09:07:31 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/13 09:08:07 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(va_list args)
{
	char	*s;
	int		i;
	int		count;

	i = 0;
	count = 0;
	s = va_arg(args, char *);
	if (s == NULL)
		count = count + write (1, "(null)", 6);
	else
	{
		while (s[i])
		{
			count = count + write (1, &s[i], 1);
			i++;
		}
	}
	return (count);
}
