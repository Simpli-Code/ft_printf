/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:25:06 by chruhin           #+#    #+#             */
/*   Updated: 2023/01/14 13:27:17 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_function
{
	char	*str;
	int		(*f)(va_list);
}	t_function;

int	(*ft_check_specifier(const char *format))(va_list args);
int	ft_printf(const char *format, ...);
int	ft_put_unsigned(va_list args);
int	ft_put_percent(va_list args);
int	ft_put_hex_low(va_list args);
int	ft_put_hex_upp(va_list args);
int	ft_put_addres(va_list args);
int	ft_put_char(va_list args);
int	ft_put_str(va_list args);
int	ft_put_nbr(va_list args);

#endif

//https://www.educative.io/answers/what-are--
//sharpifndef-and--sharpdefine-used-for-in-cpp
//https://www.educba.com/sharp-ifdef-in-c/ 