/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/26 16:58:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int		main(void)
{
	int				ret;
	int				**mat;

	mat = malloc(8);
	mat[0] = malloc(4);
	mat[0][0] = 33;
	ft_printf("sizeof mat = %lu\nmat[0] = %lu\n",
		sizeof(mat), sizeof(mat[0][0]));
	ret = printf("%+.10d\n", 1);
	ft_putnbr(ret);
	ret = ft_printfd(1, "%#0 +%", 1);
	ft_putnbr(ret);
	return (0);
}
