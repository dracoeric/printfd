/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_add_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:18:32 by erli              #+#    #+#             */
/*   Updated: 2019/02/25 18:37:34 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

int		pfd_add_str(t_pfd_data *data, char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (data->cursor + len > PRINT_B_SIZE && pfd_unload_buf(data) < 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		data->buf[data->cursor + i] = str[i];
		i++;
	}
	data->cursor += i;
	return (1);
}
