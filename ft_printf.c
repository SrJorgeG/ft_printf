/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:15:38 by jorge             #+#    #+#             */
/*   Updated: 2024/12/09 08:20:45 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// • %c Imprime un solo carácter.
// • % % para imprimir el símbolo del porcentaje.

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_pf(char *fmt, va_list arglst)
{
	int	counter;

	counter = 0;
	if (*fmt == 'c')
		counter += ft_putchar_pf(va_arg(arglst, int));
	else if (*fmt == '%')
		counter += ft_putchar_pf('%');
	else if (*fmt == 's')
		counter += ft_putstr_pf(va_arg(arglst, char *));
	else if (*fmt == 'i' || *fmt == 'd')
		counter += ft_putnbr_pf(va_arg(arglst, int), 0);
	else if (*fmt == 'u')
		counter += ft_putu_pf(va_arg(arglst, unsigned int), 0);
	else if (*fmt == 'x' || *fmt == 'X')
		counter += ft_puthex_pf(va_arg(arglst, unsigned int), 0, *fmt);
	else if (*fmt == 'p')
		counter += ft_putptr(va_arg(arglst, void *));
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	arglst;
	int		counter;
	char	*fmt;
	int		i;

	i = 0;
	counter = 0;
	fmt = ((char *)format);
	va_start(arglst, format);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			counter += ft_putchar_pf(fmt[i++]);
		else
		{
			counter += ft_print_pf(&fmt[(++i)], arglst);
			i++;
		}
	}
	return (va_end(arglst), counter);
}
