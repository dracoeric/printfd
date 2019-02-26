/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_arg_to_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:01:42 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 12:03:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Read memory zone the right amout of byte by reading data->tag, then writes
** it's content in binary in buf
*/

int				pfd_arg_to_bin(t_pfd_data *data, void *ptr)
{
	if (data == 0 || ptr == 0)
		return (-1);
	return (0);
}
