/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:15:38 by jorge             #+#    #+#             */
/*   Updated: 2024/12/04 22:47:34 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pf(char *fmt, int *counter, va_list arglst)
{
	if (*fmt == 'c' || *fmt == '%')
		ft_putchar_pf(va_arg(arglst, int), counter);
	else if (*fmt == 's')
		ft_putstr_pf(va_arg(arglst, char *), counter);
	else if (*fmt == 'i' || *fmt == 'd')
		ft_putnbr_pf(va_arg(arglst, int), counter);
	else if (*fmt == 'u')
		ft_putu_pf(va_arg(arglst, unsigned int), counter);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_puthex_pf(va_arg(arglst, unsigned long), counter, *fmt);
	else if (*fmt == 'p')
		ft_putptr(va_arg(arglst, void *), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	arglst;
	int		counter;
	char	*fmt;

	fmt = (counter = 0, (char *)format);
	fmt--;
	va_start(arglst, format);
	while (*(++fmt))
 		if (*fmt++ != '%')
			ft_putchar_pf(*fmt, &counter);
		else 
			ft_print_pf(fmt, &counter, arglst);
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
