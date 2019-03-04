/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_num_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:32:21 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 13:22:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** If it's a signed conversion, return '-' if negative number by reading first
** bit.
** Else, if SPACE or PLUS option are enabled, return ' ' or '+';
** Also transform nb to abs(nb);
*/

static	char	pfd_extract_sign(int flags, unsigned long long *nb)
{
	if ((flags & (3 << 14)) && (*nb & ((unsigned long long)1 << LL_LAST_BIT)))
	{
		*nb = ((unsigned long long)1 << LL_LAST_BIT)
			- (*nb - ((unsigned long long)1 << LL_LAST_BIT));
		return ('-');
	}
	else if (flags & SPACE)
		return (' ');
	else if (flags & PLUS)
		return ('+');
	return ('\0');
}

/*
** calculate the width of a number in base 10, 8 or 16.
*/

static	size_t	pfd_num_len(t_pfd_data *data, unsigned long long nb)
{
	unsigned long long	base;
	int					len;

	base = 10;
	if (data->tag->flags & O_CONV)
		base = 8;
	if (data->tag->flags & X_CONV || data->tag->flags & BX_CONV)
		base = 16;
	len = 1;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	return (len);
}

/*
** Calculate the lenght if the part if there was no width. takes into account
** the addition of 0x or 0 for o,x,X conversion, and the sign -,+,space.
*/

static	size_t	pfd_num_total_len(t_pfd_data *data, unsigned long long nb,
					int len, char sign)
{
	int	total_len;

	total_len = (len > data->tag->precision ? len : data->tag->precision);
	total_len += (sign == '\0' ? 0 : 1);
	if (nb != 0 && data->tag->flags & O_CONV && data->tag->flags & POUND
		&& !(data->tag->precision > len))
		total_len += 1;
	else if (nb != 0 && data->tag->flags & (3 << 18)
		&& data->tag->flags & POUND)
		total_len += 2;
	return (total_len);
}

/*
** Convert a nb (no double) to str with all the spacing needed, retrive the
** sign by reading first bit.
*/

int				pfd_num_to_str(t_pfd_data *data, unsigned long long nb)
{
	char	sign;
	int		len;
	int		total_len;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, &nb));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, &nb));
	sign = pfd_extract_sign(data->tag->flags, &nb);
	if (nb == 0 && data->tag->precision == 0 && data->tag->flags & O_CONV
		&& data->tag->flags & POUND)
		return (pfd_add_width(data, "0", 1));
	if (nb == 0 && data->tag->precision == 0)
		return (pfd_add_width(data, &sign, (sign == '\0' ? 0 : 1)));
	len = pfd_num_len(data, nb);
	total_len = pfd_num_total_len(data, nb, len, sign);
	return (pfd_write_num_to_str(data, nb, sign, (size_t)total_len));
}
