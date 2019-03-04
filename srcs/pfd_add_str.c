/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_add_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:18:32 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 16:00:18 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

int		pfd_add_str(t_pfd_data *data, char *str, size_t start, size_t len)
{
	size_t	i;
	size_t	remaining;

	i = 0;
	remaining = PRINT_B_SIZE - data->cursor;
	if (len > remaining)
	{
		ft_strncpy(data->buf + data->cursor, str + start, remaining);
		data->cursor += remaining;
		if (pfd_unload_buf(data) < 0)
			return (-1);
		return (pfd_add_str(data, str, start + remaining, len - remaining));
	}
	while (i < len)
	{
		data->buf[data->cursor + i] = str[start + i];
		i++;
	}
	data->cursor += i;
	return (1);
}
