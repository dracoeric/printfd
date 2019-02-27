/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_write_num_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:30:07 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 09:57:42 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	int		pfd_write_num(t_pfd_data *data, char *str,
					unsigned long long nb, int total_len)
{
	unsigned long long	base;
	char				*str_base;
	int					i;

	base = 10;
	str_base = (data->tag->flags & BX_CONV ? HEXA_CAP : DECIMALS);
	str_base = (data->tag->flags & X_CONV ? HEXA_LOW : str_base);
	if (data->tag->flags & O_CONV)
		base = 8;
	if (data->tag->flags & X_CONV || data->tag->flags & BX_CONV)
		base = 16;
	i = 0;
	if (nb == 0)
		str[total_len - i - 1] = str_base[(nb % base)];
	while (nb != 0)
	{
		str[total_len - i - 1] = str_base[(nb % base)];
		i += 1;
		nb = nb / base;
	}
	return (i);
}

/*
** Writes to str the number as if there was no width.
*/

int				pfd_write_num_to_str(t_pfd_data *data,
					unsigned long long nb, char sign, int total_len)
{
	char				str[total_len + 1];
	int					i;

	ft_bzero(str, total_len + 1);
	i = pfd_write_num(data, str, nb, total_len);
	while (i < data->tag->precision)
	{
		str[total_len - i - 1] = '0';
		i++;
	}
	if (nb != 0 && data->tag->flags & POUND && data->tag->flags & (7 << 17))
		str[0] = '0';
	if (nb != 0 && data->tag->flags & POUND && data->tag->flags & X_CONV)
		str[1] = 'x';
	if (nb != 0 && data->tag->flags & POUND && data->tag->flags & BX_CONV)
		str[1] = 'X';
	if (sign != '\0')
		str[0] = sign;
	return (pfd_add_width(data, str, total_len));
}
