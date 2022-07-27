/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:55:36 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/27 20:01:56 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long putchar_and_count(t_info *arg_info, char *fmt)
{
	write(1, &c, 1);
	return (1);
}


long long get_arg_info(t_info *arg_info, char *fmt)
{

}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	long long	res;
	t_info		arg_info;

	res = 0;
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%')
		{
			res = get_arg_info(&arg_info, fmt);
			fmt++;
		}
		else
			res = putchar_and_count(&arg_info, fmt);
		if (res == -1 || res > INT_MAX)
			return (-1);
		fmt++;
	}
	va_end(ap);
	return ((int)res);
}

int	main(void)
{
	ft_printf("ft : [%s]\n");
	printf("lib: [%s]\n");
}
