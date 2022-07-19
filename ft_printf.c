/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:55:36 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/18 22:56:25 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input)
{
	const char	*tmp;
	va_list		args;
	size_t		count;

	tmp = ft_strdup(input);
	if (!tmp)
		return (0);
	va_start(args, input);
	count = count_output(tmp ,args);
	va_end(args);
	free(save);
	return (count);
}