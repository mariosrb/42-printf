/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:56 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/23 17:15:37 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *adress)
{
	unsigned long long	p;

	p = (unsigned long long)adress;
	ft_putlstr("0x");
	return (ft_putnbr_hex('x', p) + 2);
}