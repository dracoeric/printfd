/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 17:28:15 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		pfd_print_doubles(long double nb)
{
	unsigned char	*ptr;
	int 			i;
	int				j;
	int				nb_bytes;

	ptr = (unsigned char *)(&nb);
	nb_bytes = 10;
	i = 0;
	while (i < nb_bytes)
	{
		j = 0;
		while (j < 8)
		{
			ft_putnbr((ptr[i] & (1 << (7 - j)) ? 1 : 0));
			if (j % 8 == 7)
				ft_putchar(' ');
			j++;
		}
		if (i == 7)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void		pfd_print_int(unsigned long long nb)
{
	unsigned char	*ptr;
	int 			i;
	int				j;
	int				nb_bytes;

	ptr = (unsigned char *)(&nb);
	nb_bytes = 8;
	i = 0;
	while (i < nb_bytes)
	{
		j = 0;
		while (j < 8)
		{
			ft_putnbr((ptr[i] & (1 << (7 - j)) ? 1 : 0));
			if (j % 8 == 7)
				ft_putchar(' ');
			j++;
		}
		if (i == 7)
			ft_putchar('\n');
		i++;
	}
}

static	void		pfd_get_whole_part(long double nb, unsigned long long *whole_part,
						unsigned long long *prec_part)
{
	int				exponent;
	int		 		i;
	int				j;
	int				nb_bits;
	unsigned char 	*ptrbase;
	unsigned long long	mantisse;

	ptrbase = (unsigned char *)(&nb);
	i = (8 * LD_SIZE) - 1 - LD_NB_EXP_BIT;
	if (i % 8 == 0)
		i = i / 8 - 1;
	else
		i = i / 8;
	j = 0;
	mantisse = 0;
	nb_bits = 0;
	while (j <= i)
	{
		nb_bits += 8;
		if (mantisse != 0)
			mantisse = mantisse << 8;
		mantisse |= ptrbase[i - j];
		j++;
	}
	exponent = ft_double_exponent(nb, LD_SIZE, LD_NB_EXP_BIT);
	exponent -= (1 << (LD_NB_EXP_BIT - 1)) - 1;
	nb_bits -= (7 - exponent % 8);
	*whole_part = mantisse >> (7 - (exponent % 8));
	*whole_part = *whole_part >> (nb_bits - exponent - 1);
	*prec_part = mantisse;
	pfd_print_int(*whole_part);
	ft_printf("expo = %d, whole = %llu\n\n", exponent, *whole_part);
	pfd_print_int(*prec_part);
	ft_printf("expo = %d, prec = %llu\n\n", exponent, *prec_part);
}

int		main(void)
{
	int			ret;
	int			ret1;
	int			**mat;
	char		*str;
	long double	nb;
	int			exponent;
	unsigned long long	whole;
	unsigned long long	float_;

	nb = 2898127373.1198237;
	ft_printf("sizeof (long double) = %lu\n", sizeof(double));
	str = "%0-20.0+Lf\n";
	mat = malloc(8);
	mat[0] = malloc(4);
	mat[0][0] = 33;
	ret = printf(str, nb);
	ret1 = ft_printfd(1, str, nb);
	if (ret != ret1)
		ft_printf("difference: ret = %d, retfd = %d\n", ret, ret1);
	ft_printf("\n\n TEST\n");
	pfd_print_doubles(nb);
	exponent = ft_double_exponent(nb, LD_SIZE, LD_NB_EXP_BIT);
	pfd_get_whole_part(nb, &whole, &float_);
	pfd_print_int((unsigned long long)nb);
	return (0);
}
