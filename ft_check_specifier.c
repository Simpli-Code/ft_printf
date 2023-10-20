/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:35:24 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/14 10:00:02 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*ft_check_specifier(const char *format))(va_list args)
{
	int			i;
	t_function	functions[10];

	functions[0] = (t_function){"u", ft_put_unsigned};
	functions[1] = (t_function){"x", ft_put_hex_low};
	functions[2] = (t_function){"X", ft_put_hex_upp};
	functions[3] = (t_function){"%", ft_put_percent};
	functions[4] = (t_function){"p", ft_put_addres};
	functions[5] = (t_function){"c", ft_put_char};
	functions[6] = (t_function){"s", ft_put_str};
	functions[7] = (t_function){"d", ft_put_nbr};
	functions[8] = (t_function){"i", ft_put_nbr};
	functions[9] = (t_function){NULL, NULL};
	i = 0;
	while (functions[i].str != NULL)
	{
		if (*(functions[i].str) == *format)
			return (functions[i].f);
		i++;
	}
	return (NULL);
}

/*
www.scaler.com/topics/c/array-of-structure-in-c/
overiq.com/c-programming-101/array-of-structures-in-c/
www.youtube.com/watch?v=Ranc3VvjI88
*/