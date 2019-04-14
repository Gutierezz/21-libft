/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:03:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:59:43 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize(int *sign, double *pos, size_t *i, double *res)
{
	*sign = 1;
	*pos = 0.1;
	*i = 0;
	*res = 0;
}

double		ft_atof(const char *str)
{
	double	res;
	int		integer;
	size_t	i;
	double	pos;
	int		sign;

	initialize(&sign, &pos, &i, &res);
	integer = ft_atoi(str);
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -1 : 1;
	i += ft_nblen_base(integer, 10);
	if (str[i] && str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
		{
			res += (pos * (str[i] - '0'));
			pos *= 0.1;
		}
	}
	res += (double)ABS(integer);
	return ((sign < 0) ? -res : res);
}
