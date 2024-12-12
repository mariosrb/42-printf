   /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:30:17 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/27 15:22:12 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putlchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putlstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == '%')
		return (ft_putlchar('%'));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_ptr(va_arg(args, void *)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr_hex(c, va_arg(args, unsigned int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putlchar(format[i++]);
		else
		{
			count += check_format(format[++i], args);
			i++;
		}
	}
	va_end(args);
	return (count);
}
// int     main(void)
// {
//         int ret_original;
//         int ret_custom;

//         printf("=== Hexadecimal Tests ===\n");

//         // Test simple
//         ret_original = printf("Original %%x: [%x]\n", 42);
//         ret_custom = ft_printf("Custom %%x: [%x]\n", 42);
//         printf("Return printf: %d | Return ft_printf: %d\n\n", ret_original, ret_custom);
// 		return (0);
// }