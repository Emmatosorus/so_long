/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolitze <epolitze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:45:37 by epolitze          #+#    #+#             */
/*   Updated: 2024/01/08 13:50:55 by epolitze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int nb, int lower, int wcount)
{
	int		temp;
	char	*hexbase;

	if (lower == 1)
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (nb >= 16)
	{
		wcount = ft_puthex(nb / 16, lower, wcount);
		temp = ft_putchar_pf(hexbase[nb % 16]);
		if (temp == -1)
			return (-1);
	}
	else
		temp = ft_putchar_pf(hexbase[nb % 16]);
	if (temp == -1)
		return (-1);
	wcount += temp;
	return (wcount);
}

int	ft_putaddress(void *ptr, int wcount)
{
	unsigned long long	nb;
	int					temp;

	nb = (unsigned long long)ptr;
	temp = ft_puthex(nb, 1, 0);
	if (temp == -1)
		return (-1);
	wcount += temp;
	return (wcount);
}
