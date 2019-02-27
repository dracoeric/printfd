/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_double_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:24:58 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 16:05:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Retrieves the whole part and the float_part.
*/

static	void		pfd_get_whole_part(long double nb, long double *whole_part,
						long double *prec_part)
{
	int				exponent;
	int				bias;

	exponent = ft_double_exponent(nb, LD_SIZE, LD_NB_EXP_BIT);
	bias = (1 << LD_NB_EXP_BIT) - 1;
	*whole_part = 0;
	*whole_part = exponent << (LD_SIZE * 8 - LD_NB_EXP_BIT - 1);
	*whole_part |= (long double)1 << (LD_SIZE * 8 - 1);
	if (exponent == bias)
		*whole_part |= 

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
