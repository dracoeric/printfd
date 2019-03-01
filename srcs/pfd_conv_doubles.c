/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_doubles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:52:47 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 17:47:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

static	int		pfd_conv_double_ptr(t_pfd_data *data, char *ptr)
{
	size_t	type_size;
	size_t	i;

	type_size = (data->tag->flags & BL_MOD ? sizeof(long double)
		: sizeof(double));
	i = 0;
	pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_col)
	{
		if (pfd_num_to_str(data,
			*(long double *)(&(ptr[i * type_size]))) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			pfd_add_str(data, ", ", 2);
		i += 1;
	}
	pfd_add_char(data, '}');
	return (1);
}

static	int		pfd_conv_double_mat(t_pfd_data *data, char **ptr)
{
	size_t	i;

	i = 0;
	pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_double_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			pfd_add_str(data, ",\n", 2);
		i += 1;
	}
	pfd_add_char(data, '}');
	return (1);
}

int				pfd_conv_doubles(t_pfd_data *data, va_list ap)
{
	long double	nb;

	data->tag->precision = (data->tag->precision == -1 ? 6
		: data->tag->precision);
	if (data->tag->flags & T_MOD)
		return (pfd_conv_double_ptr(data, va_arg(ap, char *)));
	else if (data->tag->flags & M_MOD)
		return (pfd_conv_double_mat(data, va_arg(ap, char **)));
	if (data->tag->flags & BL_MOD)
		nb = va_arg(ap, long double);
	else
		nb = (long double)va_arg(ap, double);
	return (pfd_double_to_str(data, (long double)nb));
}
