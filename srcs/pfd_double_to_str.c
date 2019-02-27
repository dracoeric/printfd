/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_double_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:24:58 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 14:33:28 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Retrieves the whole part and the float_part.
*/

static	void		pfd_get_whole_part(long double nb, long double *whole_part,
						long double *prec_part)
{
	int	exponent;

	exponent = ((*((unsigned char *)(&nb) + LD_SIZE - 1)) & 127) << 8;
	exponent |= (*((unsigned char *)(&nb) + LD_SIZE - 2));

}

static	void		pfd_round_up(t_pfd_data *data, double *whole_part,
						double *float_part)
{


}

int					pfd_double_to_str(t_pfd_data *data, long double nb)
{
	long double	whole_part;
	long double	prec_part;
	int			pow;
	int			len;
	int			total_len;

	if (data->tag->flags & MEM_MOD)
		return (pfd_arg_to_mem(data, &nb));
	if (data->tag->flags & B_MOD)
		return (pfd_arg_to_bin(data, &nb));
	pow = 0;
	pfd_get_whole_part(nb, &whole_part, &prec_part);
	pfd_round_up(data->tag, &whole_part, &prec_part, &pow);
	len = pfd_double_len(data, whole_part, float_part);
	total_len = pfd_total_len(data, whole_part, float_part);
	return (pfd_write_double_to_str(data, nb, (size_t)total_len));
}
