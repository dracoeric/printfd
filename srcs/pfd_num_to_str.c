/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_num_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 18:32:21 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 15:35:12 by erli             ###   ########.fr       */
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
** Convert a nb to str with all the spacing needed, retrive the sign by reading
** first bit.
*/

static	int		pfd_num_len(t_pfd_data *data, unsigned long long nb)
{
	unsigned long long	base;
	int					len;

	base = 10;
	if (data->tag->flags & O_CONV)
		base = 8;
	if (data->tag->flags & X_CONV || data->tag->flags & BX_CONV)
		base = 16;
	len = 1;
	while (nb / base >= base)
	{
		nb /= base;
		len++;
	}	
	return (len);
}

int				pfd_num_to_str(t_pfd_data *data, unsigned long long nb)
{
	char	sign;
	int		len;
	int		total_len;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, &nb));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, &nb));
	if (nb == 0 && data->tag->precision == 0)
		return (1);
	sign = pfd_extract_sign(data->tag->flags, &nb);
	len = pfd_num_len(data, nb);
	total_len = (len > data->tag->precision ? len : data->tag->precision);
	total_len += (sign == '\0' ? 0 : 1);
	return (1);
}
