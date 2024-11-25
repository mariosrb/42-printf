/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:53:30 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/25 12:46:07 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(char c, unsigned long nb)
{
	char				*str;
	int					count;

	count = 0;
	if (c == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_putnbr_hex(c, (nb / 16));
	count += ft_putlchar(str[nb % 16]);
	return (count);
}
