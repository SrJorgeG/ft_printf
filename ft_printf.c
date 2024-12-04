/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:15:38 by jorge             #+#    #+#             */
/*   Updated: 2024/12/04 16:58:56 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arglst;
	int		counter;
	char	*fmt;
	
	counter = 0;
	fmt = (char *)format;
	va_start(arglst, format);
	fmt--;
	while (*(++fmt))
	{
		if (*(fmt) != '%')
			write(1, fmt, 1);
		else if (*(fmt++) == '%')
	 		if (*fmt == 'c' || *fmt == '%')
				ft_putchar_pf(va_arg(arglst, int), &counter);
			else if (*fmt == 's')
				ft_putstr_pf(va_arg(arglst, char *), &counter);
			else if (*fmt == 'i' || *fmt == 'd')
				ft_putnbr_pf(va_arg(arglst, int), &counter);
			else if (*fmt == 'u')
				ft_putu_pf(va_arg(arglst, unsigned int), &counter);
			else if (*fmt == 'x' || *fmt == 'X' || *fmt == 'p')
				ft_puthex_pf(va_arg(arglst, int), &counter, *fmt);
	}
	return (va_end(arglst), counter);
}

int main()
{
	int i = 42, j = 0;
	char *s;

	s = "Hola Mundo";
	j = ft_printf("%s  %d  %p", s, i, &i);
	printf("\n %d \n", j);
	return 0;
}
