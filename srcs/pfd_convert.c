/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:40:33 by erli              #+#    #+#             */
/*   Updated: 2019/02/24 18:42:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Retrieve the argument in the va_list, manage the formating and writes it in
** buf;
*/

int				pfd_convert(t_pfd_data *data, va_list ap)
{
	if (data == 0 || ap == 0)
		return (-1);
	return (0);
}
