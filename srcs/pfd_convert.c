/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:40:33 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 09:27:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Retrieve the argument in the va_list, manage the formating and writes it in
** buf;
*/

static	t_pfd_conv	pfd_get_converter(int flags)
{
	if (flags & D_CONV || flags & I_CONV)
		return (&pfd_conv_signed_decimals);
	if (flags & (15 << 16))
		return (&pfd_conv_unsigned_decimals);
	return (&pfd_no_conv);
}

int					pfd_convert(t_pfd_data *data, va_list ap)
{
	t_pfd_conv converter;

	converter = pfd_get_converter(data->tag->flags);
	return (converter(data, ap));
}
