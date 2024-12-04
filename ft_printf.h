/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:16:48 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/12/04 15:24:20 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_pf(char c, int *counter);
void	ft_putstr_pf(char *str, int *counter);
void	ft_putnbr_pf(int n, int *counter);
void	ft_putu_pf(unsigned int n, int *counter);
void	ft_puthex_pf(int n, int *counter, const char base);

#endif