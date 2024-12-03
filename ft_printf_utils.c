/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 01:13:04 by jorge             #+#    #+#             */
/*   Updated: 2024/12/03 17:38:16 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// • %c Imprime un solo carácter.
// • % % para imprimir el símbolo del porcentaje.

void	ft_putchar_pf(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

// • %s Imprime una string (como se define por defecto en C).

int ft_putstr_pf(char *str, int counter)
{
	if (!str)
		str = ("(null)");
	while (*str)
		ft_putchar_pf(*str++, counter);
}

// • %d Imprime un número decimal (base 10).
// • %i Imprime un entero en base 10.

int	ft_putnbr_pf(int n, int counter)
{
	if (n < 0)
	{
		counter += ft_putchar_pf('-', counter);
		if (n == -2147483648)
		{
			counter += ft_putchar_pf('2', counter);
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, counter);
	counter += ft_putchar_pf((n % 10) + '0', counter);
	return(counter);
}

// • %u Imprime un número decimal (base 10) sin signo.

int ft_putu_pf(unsigned int n, int counter)
{
	if (n >= 10)
		ft_putu_pf(n / 10, counter);
	counter += ft_putchar_pf((n % 10) + '0', counter);
	return(counter);
}

// • %p El puntero void * dado como argumento se imprime en formato hexadecimal.


// • %x Imprime un número hexadecimal (base 16) en minúsculas.
// • %X Imprime un número hexadecimal (base 16) en mayúsculas.

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_puthex_pf(int n, int counter, char *base)
{
	int	i;
	int	aux;
	char	*converted_nbr;

	i = 0;
	aux = 0;
	while (n > 16)
	{
		aux = n % 16;
		converted_nbr[i] = base[aux];
		i++;
	}
	while (converted_nbr[i--])
		ft_putchar_pf(converted_nbr[i], counter);
}
