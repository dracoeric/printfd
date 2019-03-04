/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:28:02 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 18:18:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	int	pfd_string_to_str(t_pfd_data *data, char *str)
{
	size_t	len;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, str));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, str));
	if (str == NULL && data->tag->precision != 0)
		return (pfd_add_width(data, "(null)", 6));
	len = (str == NULL ? 0 : ft_strlen(str));
	if (!(data->tag->precision == -1 || len < (size_t)data->tag->precision))
		len = (size_t)data->tag->precision;
	return (pfd_add_width(data, str, len));
}

static	int	pfd_conv_string_ptr(t_pfd_data *data, char **ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (ret > 0 && i < (size_t)data->tag->nb_col)
	{
		if (pfd_string_to_str(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			ret = pfd_add_str(data, ", ", 0, 2);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

static	int	pfd_conv_string_mat(t_pfd_data *data, char ***ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (ret > 0 && i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_string_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			ret = pfd_add_str(data, ",\n ", 0, 3);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

int			pfd_conv_string(t_pfd_data *data, va_list ap)
{
	if (data->tag->flags & T_MOD)
		return (pfd_conv_string_ptr(data, va_arg(ap, char **)));
	if (data->tag->flags & M_MOD)
		return (pfd_conv_string_mat(data, va_arg(ap, char ***)));
	return (pfd_string_to_str(data, va_arg(ap, char *)));
}
