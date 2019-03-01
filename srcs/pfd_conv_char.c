/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:21:48 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 18:26:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int			pfd_conv_char(t_pfd_data *data, va_list ap)
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	return (pfd_add_width(data, (char *)&c, 1));
}
