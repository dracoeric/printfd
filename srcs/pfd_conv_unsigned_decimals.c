/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_unsigned_decimals.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:52:47 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 18:18:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	int		pfd_conv_d_ptr(t_pfd_data *data, char *ptr)
{
	char	str[LD_SIZE];
	size_t	type_size;
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	type_size = pfd_num_type_size(data->tag->flags);
	i = 0;
	ret = pfd_add_char(data, '{');
	while (ret > 0 && i < (size_t)data->tag->nb_col)
	{
		ft_bzero(str, LD_SIZE);
		ft_strncpy(str, ptr + (i * type_size), type_size);
		if (pfd_num_to_str(data, *(unsigned long long *)str) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			ret = pfd_add_str(data, ", ", 0, 2);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

static	int		pfd_conv_d_mat(t_pfd_data *data, char **ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (ret > 0 && i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_d_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			ret = pfd_add_str(data, ",\n ", 0, 3);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
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
