/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:55:36 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/30 09:46:57 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	convert_put(va_list ap, const char fmt, long long res)
{
	if (fmt == 'c')
		res += put_c(va_arg(ap, int));
	else if (fmt == 's')
		res += put_s(va_arg(ap, char *));
	else if (fmt == 'p')
		res += put_p(va_arg(ap, uintptr_t));
	else if (fmt == 'd' || fmt == 'i')
		res += put_int(va_arg(ap, long long));
	else if (fmt == 'u')
		res += put_int(va_arg(ap, long long));
	else if (fmt == 'x' || fmt == 'X')
		res += put_x(va_arg(ap, unsigned int), fmt, res);
	else if (fmt == '%')
		res += write(1, "%", 1);
	else
		res = -1;
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	long long	res;
	long long	i;

	res = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			res = convert_put(ap, fmt[i + 1], res);
			i++;
		}
		else
			res += write(1, &fmt[i], 1);
		if (res == -1 || res > INT_MAX)
		{
			va_end(ap);
			return (-1);
		}
		i++;
	}
	va_end(ap);
	return ((int)res);
}
