/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_unsigned_decimals.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:52:47 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 09:11:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

static	int		pfd_conv_d_ptr(t_pfd_data *data, char *ptr)
{
	size_t	type_size;
	size_t	i;

	type_size = pfd_num_type_size(data->tag->flags);
	i = 0;
	pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_col)
	{
		if (pfd_num_to_str(data,
			*(unsigned long long *)(&(ptr[i * type_size]))) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			pfd_add_str(data, ", ", 2);
		i += 1;
	}
	pfd_add_char(data, '}');
	return (1);
}

static	int		pfd_conv_d_mat(t_pfd_data *data, char **ptr)
{
	size_t	i;

	i = 0;
	pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_d_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			pfd_add_str(data, ",\n", 2);
		i += 1;
	}
	pfd_add_char(data, '}');
	return (1);
}

int				pfd_conv_unsigned_decimals(t_pfd_data *data, va_list ap)
{
	unsigned long long	nb;

	if (data->tag->flags & T_MOD)
		return (pfd_conv_d_ptr(data, va_arg(ap, char *)));
	else if (data->tag->flags & M_MOD)
		return (pfd_conv_d_mat(data, va_arg(ap, char **)));
	if (data->tag->flags & L_MOD)
		nb = (unsigned long long)va_arg(ap, unsigned long);
	else if (data->tag->flags & LL_MOD)
		nb = va_arg(ap, unsigned long long);
	else if (data->tag->flags & H_MOD)
		nb = (unsigned long long)(unsigned short)va_arg(ap, unsigned int);
	else if (data->tag->flags & HH_MOD)
		nb = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	else
		nb = (unsigned long long)va_arg(ap, unsigned int);
	return (pfd_num_to_str(data, nb));
}
