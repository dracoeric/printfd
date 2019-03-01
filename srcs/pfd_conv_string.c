/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:28:02 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 18:33:16 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int			pfd_conv_string(t_pfd_data *data, va_list ap)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	if (str == NULL && data->tag->precision != 0)
		return (pfd_add_width(data, "(null)", 6));
	len = (data->tag->precision == -1 ? ft_strlen(str) : data->tag->precision);
	return (pfd_add_width(data, str, len));
}
