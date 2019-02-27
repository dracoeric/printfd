/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 15:23:13 by erli             ###   ########.fr       */
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

void		pfd_print_int(int nb)
{
	unsigned char	*ptr;
	int 			i;
	int				j;
	int				nb_bytes;

	ptr = (unsigned char *)(&nb);
	nb_bytes = 4;
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

int		main(void)
{
	int			ret;
	int			ret1;
	int			**mat;
	char		*str;
	long double	nb;
	int			exponent;

	nb = 91286738.98172456;
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
	pfd_print_doubles(1);
	pfd_print_doubles(nb);
	exponent = ft_double_exponent(nb, LD_SIZE, LD_NB_EXP_BIT);
	pfd_print_int(exponent);
	
	return (0);
}
