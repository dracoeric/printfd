/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_no_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:57:13 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 09:20:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	pfd_no_conv(t_pfd_data *data, va_list ap)
{
	if (data == 0 || ap == 0)
		return (-1);
	if (data->tag->width > 0)
		data->tag->width -= 1;
	return (pfd_add_width(data, "", 0));
}
