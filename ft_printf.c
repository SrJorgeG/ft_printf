/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:15:38 by jorge             #+#    #+#             */
/*   Updated: 2024/12/03 17:37:20 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <varargs.h>
#include <stdarg.h>

int	ft_printf(const char *fmt, ...)
{
	va_list arglst;
	int	counter;
	va_start(arglst, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*(++fmt) == 'c' || *(++fmt) == '%')
				ft_putchar_pf(va_arg(arglst, int), counter);
			else if (*(++fmt) == 's')
				ft_putstr_pf(va_arg(arglst, char *), counter);
			else if (*(++fmt) == 'i' || *(++fmt) == 'd')
				ft_putnbr_pf(va_arg(arglst, char *), counter);
			else if (*(++fmt) == 'u')
				ft_putu_pf(va_arg(arglst, char *), counter);
			else if (*(++fmt) == 'x')
				ft_puthex_pf(va_arg(arglst, char *), counter, base_minus);
			else if (*(++fmt) == 'X')
				ft_puthex_pf(va_arg(arglst, char *), counter, base_mayus);
			else if (*(++fmt) == 'p')
				ft_puthex_pf(va_arg(arglst, void *), counter, base_mayus);
		}
		else
			write(1, fmt++, 1);
	}
	
	va_end(arglst);
	return (counter);
}
