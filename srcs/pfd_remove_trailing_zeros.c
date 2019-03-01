/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_trailing_zeros.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:16:17 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 17:57:52 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

int				pfd_remove_trailing_zeros(t_pfd_data *data, char *str,
					size_t len)
{
	size_t	i;
	size_t	j;
	int		dec_point;

	dec_point = 0;
	if ((data->tag->flags & G_CONV) == 0)
		return (pfd_add_width(data, str, len));
	i = (data->tag->flags & E_CONV ? len - 5 : len - 1);
	while (i > 0 && str[i] == '0')
		i--;
	j = i;
	while (j > 0 && str[j] != DECIMAL_POINT)
		j--;
	dec_point = (str[j] == DECIMAL_POINT ? 1 : 0);
	if (dec_point == 1)
	{
		i += (str[i] == DECIMAL_POINT ? 0 : 1);
		if (data->tag->flags & E_CONV)
			ft_memmove(str + i, str + len - 4, 5);
		else
			str[i] = '\0';
		len -= (data->tag->flags & E_CONV ? len - 4 - i : len - i);
	}
	return (pfd_add_width(data, str, len));
}
