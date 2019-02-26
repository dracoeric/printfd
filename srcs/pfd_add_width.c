/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_add_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:16 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 17:18:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int			pfd_add_width(t_pfd_data *data, char *str, size_t len)
{
	int		ret;
	size_t	nb_space;
	size_t	i;

	ret = 1;
	if ((size_t)data->tag->width <= len || data->tag->flags & MINUS)
		ret = pfd_add_str(data, str, len);
	if (ret < 0)
		return (-1);
	i = 0;
	nb_space = ((size_t)data->tag->width > len
		? (size_t)data->tag->width - len : 0);
	while (i < nb_space)
	{
		if (pfd_add_char(data, ' ') < 0)
			return (-1);
		i++;
	}
	if (!((size_t)data->tag->width <= len || data->tag->flags & MINUS))
		return (pfd_add_str(data, str, len));
	return (1);
}
