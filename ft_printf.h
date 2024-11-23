/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdodevsk <mdodevsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:57:57 by mdodevsk          #+#    #+#             */
/*   Updated: 2024/11/23 17:14:53 by mdodevsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putlchar(char c);
int	ft_putlstr(const char *s);
int	ft_putnbr(int n);
int	ft_putnbr_hex(char c, unsigned long long);
int	ft_putnbr_u(unsigned int n);
int	ft_ptr(void *adress);


#endif