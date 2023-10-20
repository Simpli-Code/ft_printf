/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:38:25 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/14 10:00:59 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_conversion_specifier(char c, va_list args)
{
	int	count;
	int	(*f)(va_list);

	count = 0;
	f = ft_check_specifier(&c);
	if (f == NULL)
		return (count = count + write (1, &c, 1));
	return (f(args));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start (args, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count = count + handle_conversion_specifier(format[i], args);
		}
		else
			count = count + write (1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
