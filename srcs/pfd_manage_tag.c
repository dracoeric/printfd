/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_manage_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:06:23 by erli              #+#    #+#             */
/*   Updated: 2019/02/25 15:41:12 by erli             ###   ########.fr       */
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
	if ((tag->flags & (63 << 13)) == 0)
		tag->flags = (tag->flags & (-1 - (15 << 5)));
	else if ((tag->flags & (7 << 22)) == 0)
		tag->flags = (tag->flags & (-1 - BL_MOD));
}

int				pfd_manage_tag(t_pfd_data *data, char *format, va_list ap,
				size_t *i)
{
	t_pfd_tag	tag[1];
	int			ret;

	ft_bzero(tag, sizeof(t_pfd_tag));
	data->tag = tag;
	*i += 1;
	if ((ret = pfd_read_tag(data, format, i)) < 0)
		return (-1);
	if (data->tag->flags & T_MOD || data->tag->flags & M_MOD)
		pfd_get_row_col(data, ap);
	pfd_harmonize_flags(data->tag);
	pfd_print_data(data);
	if (pfd_convert(data, ap) < 0)
		return (-1);
	return (1);
}
