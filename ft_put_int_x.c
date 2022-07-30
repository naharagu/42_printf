/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:49:25 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/30 09:51:38 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	put_int(long long n)
{
	long long	i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	else if (n > 10)
	{
		i += put_int(n / 10);
		i += put_int(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
		i++;
	}
	return (i);
}

void	put_x_helper(unsigned int x, char fmt)
{
	if (x >= 16)
	{
		put_x_helper(x / 16, fmt);
		put_x_helper(x % 16, fmt);
	}
	else
	{
		if (x <= 9)
			ft_putchar_fd((x + '0'), 1);
		else
		{
			if (fmt == 'x')
				ft_putchar_fd((x - 10 + 'a'), 1);
			if (fmt == 'X')
				ft_putchar_fd((x - 10 + 'A'), 1);
		}
	}
}

long long	put_x(unsigned int x, char fmt)
{
	if (!x)
		return (write(1, "0", 1));
	put_x_helper(x, fmt);
	return (get_hex_len(x));
}
