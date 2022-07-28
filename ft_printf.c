/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:55:36 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/29 00:48:56 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	convert_put(va_list ap, char *fmt, long long res)
{
	if (res > INT_MAX)
		return (-1);
	if (*fmt == 'c')
		res += put_c(va_arg(ap, int));
	else if (*fmt == 's')
		res += put_s(va_arg(ap, char *));
	// else if (*fmt == 'p')
	// 	res += put_p(va_arg(ap, uintptr_t));
	// else if (*fmt == 'd' || *fmt == 'i')
	// 	res += put_d_i(va_arg(ap, int));
	// else if (*fmt == 'u')
	// 	res += put_u(va_arg(ap, unsigned int));
	// else if (*fmt == 'x' || *fmt == 'X')
	// 	res += put_x(va_arg(ap, unsigned int), fmt);
	// else if (*fmt == '%')
	// 	res += write(1, '%', 1);
	else
		res = -1;
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	long long	res;

	res = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			res = convert_put(ap, (char *)fmt, res);
			fmt++;
		}
		else
			res += write(1, fmt, 1);
		if (res == -1 || res > INT_MAX)
		{
			va_end(ap);
			return (-1);
		}
		fmt++;
	}
	va_end(ap);
	return ((int)res);
}
