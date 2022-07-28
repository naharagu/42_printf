/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/29 00:33:19 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	check_base(char *base)
{
	unsigned long long	i;
	unsigned long long	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(long long nbr, char *base)
{
	unsigned long long	i;
	unsigned long long	b;

	b = check_base(base);
	if (b == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		i = -(unsigned int)nbr;
	}
	else
		i = nbr;
	if (i < b)
		ft_putchar(base[i]);
	else
	{
		ft_putnbr_base(i / b, base);
		ft_putchar(base[i % b]);
	}
}
