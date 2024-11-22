/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:30:17 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/22 19:28:15 by mdodevsk         ###   ########.fr       */
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
		return (ft_putnbr_hex(va_arg(args, void*)));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;
	int	count;
	
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

int	main()
{
	int ret_printf;
	int ret_ft_printf;
	
	// Test pour un char 
	printf("=== Test %%c ===\n");
	ret_printf = printf("Printf   : [%c]\n", 'A');
	ret_ft_printf = ft_printf("ft_printf: [%c]\n", 'A');
	printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);
	
	// Test avec une string
	printf("=== Test %%s ===\n");
    ret_printf = printf("Printf   : [%s]\n", "Hello, world!");
    ret_ft_printf = ft_printf("ft_printf: [%s]\n", "Hello, world!");
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);
	
	// Test %d and %i
    printf("=== Test %%d and %%i ===\n");
    ret_printf = printf("Printf   : [%d] [%i]\n", -123, 456);
    ret_ft_printf = ft_printf("ft_printf: [%d] [%i]\n", -123, 456);
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);

	// Test %%
    printf("=== Test %% ===\n");
    ret_printf = printf("Printf   : [%%]\n");
    ret_ft_printf = ft_printf("ft_printf: [%%]\n");
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);

	// Test %u
    printf("=== Test %%u ===\n");
    ret_printf = printf("Printf   : [%u]\n", 3000000000U);
    ret_ft_printf = ft_printf("ft_printf: [%u]\n", 3000000000U);
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);

	// Test %x et %X
	/*printf("=== Test %%x and %%X ===");
	ret_printf = printf("Printf   : [%x] [%X]\n", 255, 255);
    ret_ft_printf = ft_printf("ft_printf: [%x] [%X]\n", 255, 255);
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);*/
	
	// Test %p
    printf("=== Test %%p ===\n");
    int x = 42;
    ret_printf = printf("Printf   : [%p]\n", (void *)&x);
    ret_ft_printf = ft_printf("ft_printf: [%p]\n", (void *)&x);
    printf("Return printf: %d | Return ft_printf: %d\n\n", ret_printf, ret_ft_printf);

	return (0);
}