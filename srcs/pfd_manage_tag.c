/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_manage_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:06:23 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 13:31:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Manage_tag manages the %~~~ tag, treat it correctly then write the content
** in the buffer
*/

static	void	pfd_get_row_col(t_pfd_data *data, va_list ap)
{
	va_list ap_copy;

	va_copy(ap_copy, ap);
	va_arg(ap_copy, int);
	data->tag->nb_col = va_arg(ap_copy, int);
	if (data->tag->flags & M_MOD)
		data->tag->nb_line = va_arg(ap_copy, int);
	va_end(ap_copy);
	if (data->tag->nb_col <= 0)
		data->tag->nb_col = 1;
	if (data->tag->nb_line <= 0)
		data->tag->nb_line = 1;
}

/*
** removes unnecessary flags regarding converters
** Sensible to .h changes
*/

static	void	pfd_harmonize_flags(t_pfd_tag *tag)
{
	if ((tag->flags & (63 << 14)) == 0)
		tag->flags = (tag->flags & (-1 - (15 << 5)));
	if ((tag->flags & (7 << 20)) == 0)
		tag->flags = (tag->flags & (-1 - BL_MOD));
	if ((tag->flags & (63 << 17)) == 0)
		tag->flags = (tag->flags & (-1 - POUND));
	if (tag->flags & P_CONV)
		tag->flags = (tag->flags & (-1 - ZERO));
	if (tag->flags & (7 << 23) || tag->flags & (15 << 16)
		|| tag->flags & NO_CONV)
		tag->flags = (tag->flags & (-1 - (3 << 3)));
}

int				pfd_manage_tag(t_pfd_data *data, char *format, va_list ap,
				size_t *i)
{
	t_pfd_tag	tag[1];
	int			ret;

	ft_bzero(tag, sizeof(t_pfd_tag));
	tag->precision = -1;
	data->tag = tag;
	*i += 1;
	if ((ret = pfd_read_tag(data, format, i, ap)) < 0)
		return (-1);
	if (tag->width < 0)
	{
		tag->flags = (tag->flags | MINUS) - (tag->flags & ZERO);
		tag->width = -tag->width;
	}
	if (tag->precision < 0)
		tag->precision = -1;
	if (data->tag->flags & T_MOD || data->tag->flags & M_MOD)
		pfd_get_row_col(data, ap);
	pfd_harmonize_flags(data->tag);
	if (pfd_convert(data, ap) < 0)
		return (-1);
	return (1);
}
