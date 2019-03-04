/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:35:47 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 18:29:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	int	pfd_null_ptr_prec(t_pfd_data *data)
{
	char	str[3 + data->tag->precision];
	int		i;

	ft_bzero(str, 3 + data->tag->precision);
	ft_strncpy(str, "0x", 2);
	i = 0;
	while (i < data->tag->precision)
	{
		str[2 + i] = '0';
		i++;
	}
	return (pfd_add_width(data, str, 2 + data->tag->precision));
}

static	int	pfd_ptr_to_str(t_pfd_data *data, void *addr)
{
	unsigned long	nb;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, addr));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, addr));
	if (addr == NULL && data->tag->precision == -1)
		return (pfd_add_width(data, "0x0", 3));
	nb = (unsigned long)addr;
	data->tag->flags ^= P_CONV;
	data->tag->flags |= X_CONV;
	data->tag->flags |= L_MOD;
	data->tag->flags |= POUND;
	if (addr == NULL)
		return (pfd_null_ptr_prec(data));
	return (pfd_num_to_str(data, (unsigned long long)nb));
}

static	int	pfd_conv_ptr_ptr(t_pfd_data *data, void **ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_col)
	{
		if (pfd_ptr_to_str(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			ret = pfd_add_str(data, ", ", 0, 2);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

static	int	pfd_conv_ptr_mat(t_pfd_data *data, void ***ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_ptr_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			ret = pfd_add_str(data, ",\n ", 0, 3);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

int			pfd_conv_ptr(t_pfd_data *data, va_list ap)
{
	void			*addr;

	if (data->tag->flags & T_MOD)
		return (pfd_conv_ptr_ptr(data, va_arg(ap, void **)));
	if (data->tag->flags & M_MOD)
		return (pfd_conv_ptr_mat(data, va_arg(ap, void ***)));
	addr = va_arg(ap, void *);
	return (pfd_ptr_to_str(data, addr));
}
