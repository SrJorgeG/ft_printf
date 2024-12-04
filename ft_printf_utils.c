/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:04 by jorge             #+#    #+#             */
/*   Updated: 2024/12/04 16:53:49 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// • %c Imprime un solo carácter.
// • % % para imprimir el símbolo del porcentaje.

void	ft_putchar_pf(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

// • %s Imprime una string (como se define por defecto en C).

void	ft_putstr_pf(char *str, int *counter)
{
	if (!str)
		str = ("(null)");
	while (*str)
		ft_putchar_pf(*str++, counter);
}

// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.

void	ft_putnbr_pf(int n, int *counter)
{
	if (n < 0)
	{
		ft_putchar_pf('-', counter);
		if (n == -2147483648)
		{
			ft_putchar_pf('2', counter);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, counter);
	ft_putchar_pf((n % 10) + '0', counter);
}

// • %u Imprime un número decimal (base 10) sin signo.

void	ft_putu_pf(unsigned int n, int *counter)
{
	if (n >= 10)
		ft_putu_pf(n / 10, counter);
	ft_putchar_pf((n % 10) + '0', counter);
}

// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.
// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.

void	ft_puthex_pf(int n, int *counter, const char base)
{
	char	*aux;
	char	*bs;

	bs = "0123456789ABCDEF";
	if (base == 'p')
		ft_putstr_pf("0x", counter);
	else if (base == 'x')
		bs = "0123456789abcdef";
	while (n >= 16)
	{	
		ft_putchar_pf(bs[n % 16], counter);
		n /= 16;
	}
	ft_putchar_pf(bs[n], counter);
}
