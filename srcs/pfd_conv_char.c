/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:21:48 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 18:18:17 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

static	int	pfd_char_to_str(t_pfd_data *data, char c)
{
	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, &c));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, &c));
	return (pfd_add_width(data, (char *)&c, 1));
}

static	int	pfd_conv_char_ptr(t_pfd_data *data, char *ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_col)
	{
		if (pfd_char_to_str(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_col)
			ret = pfd_add_str(data, ", ", 0, 2);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

static	int	pfd_conv_char_mat(t_pfd_data *data, char **ptr)
{
	size_t	i;
	int		ret;

	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	i = 0;
	ret = pfd_add_char(data, '{');
	while (i < (size_t)data->tag->nb_line)
	{
		if (pfd_conv_char_ptr(data, ptr[i]) < 0)
			return (-1);
		if (i + 1 < (size_t)data->tag->nb_line)
			ret = pfd_add_str(data, ",\n ", 0, 3);
		i += 1;
	}
	if (ret > 0)
		ret = pfd_add_char(data, '}');
	return (ret);
}

int			pfd_conv_char(t_pfd_data *data, va_list ap)
{
	char c;

	if (data->tag->flags & T_MOD)
		return (pfd_conv_char_ptr(data, va_arg(ap, char *)));
	if (data->tag->flags & M_MOD)
		return (pfd_conv_char_mat(data, va_arg(ap, char **)));
	c = (char)va_arg(ap, int);
	return (pfd_add_width(data, (char *)&c, 1));
}
