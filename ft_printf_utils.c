/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:04 by jorge             #+#    #+#             */
/*   Updated: 2024/12/07 03:13:50 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// • %c Imprime un solo carácter.
// • % % para imprimir el símbolo del porcentaje.

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

// • %s Imprime una string (como se define por defecto en C).

int	ft_putstr_pf(char *str )
{
	int	i;
	int counter;

	i = -1;
	counter = 0;
	if (!str)
		str = "(null)";
	while (str[++i])
		counter += ft_putchar_pf(str[i]);
	return (counter);
}

// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.

int ft_putnbr_pf(int n, int counter)
{
	if (n < 0)
	{
		counter += ft_putchar_pf('-');
		if (n == -2147483648)
		{
			counter += ft_putchar_pf('2');	
			n = (-147483648);
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, counter);
	counter += ft_putchar_pf((n % 10) + '0');
	return (counter);
}

// • %u Imprime un número decimal (base 10) sin signo.

int ft_putu_pf(unsigned int n, int counter)
{
	if (n >= 10)
	{	
		counter = ft_putu_pf(n / 10, counter + 1);
		ft_putchar_pf(n % 10 + '0');
		return (counter);
	}
	counter += ft_putchar_pf(n % 10 + '0');
	return (counter);
}

// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.

int	ft_puthex_pf(unsigned long n, int counter, const char base)
{
	char	*bs;

	bs = "0123456789ABCDEF";
	if (base == 'x')
		bs = "0123456789abcdef";
	if (n >= 16)
	{	
		counter = ft_puthex_pf(n / 16, counter + 1, base);
		ft_putchar_pf(bs[n % 16]);
		return (counter);
	}
	counter += ft_putchar_pf(bs[n % 16]);
	return (counter);
}

// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.

int	ft_putptr(void *ptr)
{
	unsigned long p;
	int counter;
	
	counter = 0;
	p = (unsigned long)ptr;
	if (!ptr)
		return (counter += ft_putstr_pf(("(nil)")));
	counter += ft_putstr_pf("0x");
	counter += ft_puthex_pf(p, 0, 'x');
	return (counter);
}
