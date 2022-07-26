/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:55:36 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/26 22:47:30 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;
	t_info	info;

	len = 0;
	va_start(ap, fmt);
	while(*fmt)
	{
		if (*fmt == '%');
		{
			fmt = get_fmt_info(&info, fmt);
			len +=
			continue;
		}
		
	}

	va_end(ap);
	return ((int)len);
}

int	main(void)
{
	ft_printf("ft : [%s]\n");
	printf("lib: [%s]\n");
}
