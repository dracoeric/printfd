/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_double_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:24:58 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 17:52:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** calculate the exponent. If g_conv, changes flags to e_conv or f_conv
** accordingly and changes nb accordingly. If e_conv, changes nb
** accordingly.
*/

static	int			pfd_double_to_scientific(t_pfd_tag *tag, long double *nb)
{
	int			exp;
	long double	nb_tmp;

	nb_tmp = *nb;
	exp = 0;
	while (ft_double_whole(nb_tmp, LD_SIZE, LD_NB_EXP_BIT) >= 10)
	{
		nb_tmp /= 10.0;
		exp++;
	}
	while (nb_tmp != 0 && ft_double_whole(nb_tmp, LD_SIZE, LD_NB_EXP_BIT) < 1)
	{
		nb_tmp *= 10.0;
		exp--;
	}
	if (tag->flags & E_CONV || (tag->flags & G_CONV && (exp < -4
		|| exp >= tag->precision)))
	{
		*nb = nb_tmp;
		tag->flags |= E_CONV;
	}
	else
		tag->flags |= F_CONV;
	return (exp);
}

static	int			pfd_double_whole_len(long double nb)
{
	int len;

	len = 1;
	while (ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT) >= 10)
	{
		nb /= 10.0;
		len++;
	}
	return (len);
}

int					pfd_double_to_str(t_pfd_data *data, long double nb)
{
	int		exp;
	int		len;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, &nb));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, &nb));
	exp = pfd_double_to_scientific(data->tag, &nb);
	len = 0;
	if (data->tag->flags & E_CONV)
	{
		len = pfd_double_whole_len(exp);
		len = (len == 1 ? 4 : len + 2);
	}
	if (data->tag->flags & G_CONV)
		data->tag->precision -= 1;
	len += pfd_double_whole_len(nb) + (data->tag->precision == 0 ? 0
		: data->tag->precision + 1);
	if (nb < 0 || data->tag->flags & (3 << 3))
		len += 1;
	return (pfd_write_double_to_str(data, nb, exp, (size_t)len));
}
