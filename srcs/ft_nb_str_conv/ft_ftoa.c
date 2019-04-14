/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:45:46 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/12 13:15:12 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_nb_str(double ipart, char **nb_str, size_t *i, size_t size)
{
	ipart /= ft_powf_ip(10, size);
	while (size-- > 0)
	{
		if (FLT_ABS(ipart) < 1.f)
			ipart *= 10;
		(*nb_str)[(*i)++] = HEX_STR[(int)ipart];
		ipart -= (int)ipart;
	}
}

static size_t	ft_dbl_ipart_to_arr(double ipart, char **nb_str, int sign)
{
	size_t		size;
	size_t		i;
	double		pow;
	char		*tmp;

	i = 0;
	pow = ft_log10(ipart);
	size = (pow < 1.f) ? 1 : (size_t)ft_ceil(pow);
	*nb_str = ft_strnew(size + sign);
	if (sign)
		(*nb_str)[i++] = '-';
	if (size <= 19)
	{
		ft_strcpy((*nb_str + i), \
		(tmp = ft_ulltoa_base((unsigned long long)(ipart), 10)));
		ft_strdel(&tmp);
	}
	else
		fill_nb_str(ipart, nb_str, &i, size);
	return (ft_strlen(*nb_str));
}

static char		*prec_str(double fpart, size_t prec)
{
	char		*fl_str;
	size_t		i;

	i = 0;
	fl_str = ft_strnew(++prec);
	fl_str[i++] = '.';
	while (i < prec)
	{
		fpart *= 10;
		fl_str[i] = HEX_STR[(int)fpart];
		fpart -= (int)fpart;
		i++;
	}
	return (fl_str);
}

static void		ft_exp_form_offs(double *nb, int *offs)
{
	*offs = 0;
	if (ft_iszero(*nb))
		return ;
	while (FLT_ABS(*nb) < 1.f)
	{
		*nb *= 10;
		(*offs)--;
	}
	while (FLT_ABS(*nb) > 10.f)
	{
		*nb /= 10;
		(*offs)++;
	}
}

char			*ft_ftoa(double nb, size_t prec, size_t *length, int *exp_form)
{
	char	*fl_str;
	char	*nb_str;
	double	ipart;
	double	fpart;
	int		is_exp;

	is_exp = *exp_form;
	nb_str = NULL;
	fl_str = NULL;
	if (ft_isnan(nb) || ft_isinf(nb))
	{
		*length = 3;
		return (ft_isnan(nb) ? ft_strdup("nan") : ft_strdup("inf"));
	}
	(is_exp) ? ft_exp_form_offs(&nb, exp_form) : is_exp;
	(!ft_iszero(nb)) ? ft_round_double(&nb, prec) : nb;
	if (is_exp && (long long)nb > 9)
		(*exp_form)++;
	nb = (is_exp && (long long)nb > 9) ? (nb / 10) : nb;
	fpart = FLT_ABS(ft_modf(nb, &ipart));
	fl_str = (prec != 0) ? prec_str(fpart, prec) : NULL;
	*length = prec + \
	ft_dbl_ipart_to_arr(FLT_ABS(ipart), &nb_str, ft_getsign_dbl(ipart));
	return (ft_strjoin_free(&nb_str, &fl_str));
}
