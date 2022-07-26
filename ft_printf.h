/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:59:39 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/26 17:39:17 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

typedef struct s_info
{
	int		c;
	bool	has_width;
	int		width;
	bool	has_precision;
	int		precision;
}				t_info;

#endif