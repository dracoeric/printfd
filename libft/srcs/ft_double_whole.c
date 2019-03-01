/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_whole.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 09:31:18 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 09:48:30 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_double_whole(long double nb, size_t size,
							size_t exp_nb_bit)
{
	int					exponent;
	int					i;
	int					nb_bits;
	unsigned char		*ptrbase;
	unsigned long long	whole;

	ptrbase = (unsigned char *)(&nb);
	i = (8 * size) - 1 - exp_nb_bit;
	i = (i % 8 == 0 ? i / 8 - 1 : i / 8);
	nb_bits = 0;
	while (i >= 0)
	{
		nb_bits += 8;
		((unsigned char *)(&whole))[i] = ptrbase[i];
		i--;
	}
	exponent = ft_double_exponent(nb, size, exp_nb_bit);
	exponent -= (1 << (exp_nb_bit - 1)) - 1;
	nb_bits -= (7 - exponent % 8);
	whole = whole >> (7 - (exponent % 8));
	whole = whole >> (nb_bits - exponent - 1);
	return (whole);
}
