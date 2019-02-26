/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_unload_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:43:47 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 17:31:36 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"
#include <unistd.h>

/*
** Unloads the content of buf in data->fd, returns -1 if error on write.
** Reset cursor.q
*/

int			pfd_unload_buf(t_pfd_data *data)
{
	if (write(data->fd, data->buf, data->cursor) < 0)
		return (-1);
	data->ret += data->cursor;
	ft_bzero(data->buf, PRINT_B_SIZE + 1);
	data->cursor = 0;
	return (data->ret);
}
