/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_exponent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:22:55 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 15:25:13 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_double_exponent(long double nb, size_t double_size,
						size_t exp_nb_bit)
{
	unsigned int	exponent;
	size_t			i;
	size_t			j;

	i = 0;
	exponent = 0;
	j = 1;
	while (i < exp_nb_bit && j <= double_size)
	{
		exponent |= *(((unsigned char *)&nb) + double_size - j);
		i += 8;
		if (i < exp_nb_bit)
			exponent = exponent << 8;
		j++;
	}
	while (i > exp_nb_bit)
	{
		exponent &= (unsigned int)(-1) ^ (1 << (i - 1));
		i--;
	}
	return (exponent);
}
