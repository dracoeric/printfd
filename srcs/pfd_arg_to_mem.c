/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_arg_to_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:00:35 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 12:03:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Read the right amout of byte in memory pointed by ptr then right it in hex
** in buf.
*/

int			pfd_arg_to_mem(t_pfd_data *data, void *ptr)
{
	if (data == 0 || ptr == 0)
		return (-1);
	return (1);
}
