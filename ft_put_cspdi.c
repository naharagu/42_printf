/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_cspdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/28 16:03:31 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long long	put_c(int c)
{
	return (write(1, &c, 1));
}

long long	put_s(char *s)
{
	long long i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s)
		write(1, &s[i++], 1);
	return (i);
}

long long put_p_helper(uintptr_t p, long long len)
{
	if (p >= 16)
	{
		len++;
		len += put_p_helper(p / 16, len);
		put_p_helper(p % 16, len);
	}

}

long long	put_p(uintptr_t p)
{
	long long	i;

	i = write(1, "0x", 2);
	if (!p)
		i += write(1, '0', 1);
	else
	{

	}

}

long long	put_d_i(int n)
{

}