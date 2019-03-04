/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_no_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:57:13 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 11:49:24 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int	pfd_no_conv(t_pfd_data *data, va_list ap)
{
	int	ret;

	if (data == 0 || ap == 0)
		return (-1);
	if (data->no_conv == 0)
		ret = pfd_add_width(data, "", 0);
	else
		ret = pfd_add_width(data, &(data->no_conv), 1);
	if (ret < 0)
		return (-1);
	data->no_conv = '\0';
	return (1);
}
