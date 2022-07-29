/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/29 11:20:40 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	put_c(int c)
{
	return (write(1, &c, 1));
}

long long	put_s(char *s)
{
	long long i;

	i = 0;
	if (!s)
		return(write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

long long p_len(uintptr_t p)
{
	long long len;

	len = 0;
	while (p)
	{
		p = p / 16;
		len++;
	}
	return (len);
}

void put_p_helper(uintptr_t p, long long len)
{
	if (p >= 16)
	{
		put_p_helper(p / 16, len);
		put_p_helper(p % 16, len);
	}
	else
	{
		if (p <= 9)
			write(1, (int)(p + '0'), 1);
		else
			write(1, (int)(p - 10 + 'a'), 1);
	}

}

long long	put_p(uintptr_t p)
{
	long long	res;

	res = write(1, "0x", 2);
	if (!p)
		res += write(1, "0", 1);
	else
	{
		put_p(p);
		res += p_len(p);
	}
	return (res);
}
