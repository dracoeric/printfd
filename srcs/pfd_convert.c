/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:40:33 by erli              #+#    #+#             */
/*   Updated: 2019/02/25 14:17:01 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Retrieve the argument in the va_list, manage the formating and writes it in
** buf;
*/

static	t_pfd_conv	pfd_get_converter(int flags)
{
	if (flags & D_CONV)
		return (&pfd_conv_d);
	return (&pfd_no_conv);
}

int					pfd_convert(t_pfd_data *data, va_list ap)
{
	t_pfd_conv converter;

	converter = pfd_get_converter(data->tag->flags);
	return (converter(data, ap));
}
