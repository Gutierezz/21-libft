/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:22:04 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:13:42 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nblen_base(long long nb, unsigned int base)
{
	size_t	len;

	len = 1;
	if (base < 2 || base > 16)
		return (0);
	if (nb < 0)
	{
		if (nb == LLONG_MIN)
			nb++;
		nb = -nb;
		(base == 10) ? len++ : len;
	}
	while (nb / base)
	{
		len++;
		nb /= base;
	}
	return (len);
}
