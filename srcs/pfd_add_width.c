/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_add_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:52:16 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 10:46:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

static	int	pfd_manage_pound_ox(t_pfd_data *data, char **str, size_t *len)
{
	size_t nb_char;

	if ((size_t)data->tag->width <= *len || data->tag->flags & MINUS)
		return (pfd_add_str(data, *str, *len));
	if (data->tag->flags & (7 << 17) && (data->tag->flags & 3) == 3)
	{
		nb_char = (data->tag->flags & O_CONV ? 1 : 2);
		if (pfd_add_str(data, *str, nb_char) < 0)
			return (-1);
		*str = (*str) + nb_char;
		*len -= nb_char;
		data->tag->width -= nb_char;
	}
	return (1);
}

int			pfd_add_width(t_pfd_data *data, char *str, size_t len)
{
	int		ret;
	size_t	nb_space;
	size_t	i;

	ret = pfd_manage_pound_ox(data, &str, &len);
	if (ret < 0)
		return (-1);
	i = 0;
	nb_space = ((size_t)data->tag->width > len
		? (size_t)data->tag->width - len : 0);
	while (ret > 0 && i < nb_space)
	{
		if (data->tag->precision == -1 && data->tag->flags & ZERO)
			ret = pfd_add_char(data, '0');
		else
			ret = pfd_add_char(data, ' ');
		i++;
	}
	if (ret < 0)
		return (-1);
	if (!((size_t)data->tag->width <= len || data->tag->flags & MINUS))
		return (pfd_add_str(data, str, len));
	return (1);
}
