/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:45:46 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:27:04 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long nb, unsigned int base)
{
	char	*arr;
	size_t	len;

	if ((len = ft_nblen_base(nb, base)) == 0)
		return (NULL);
	arr = ft_strnew(len);
	arr[len] = '\0';
	if (nb < 0)
	{
		if (nb == LLONG_MIN)
		{
			arr[--len] = HEX_STR[-(nb % base)];
			nb /= base;
		}
		nb = -nb;
		arr[0] = (base == 10) ? '-' : arr[0];
	}
	else if (nb == 0)
		arr[--len] = '0';
	while (nb)
	{
		arr[--len] = HEX_STR[nb % base];
		nb /= base;
	}
	return (arr);
}
