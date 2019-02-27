/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 09:58:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		main(void)
{
	int			ret;
	int			ret1;
	int			**mat;
	char		*str;
	long long	nb;

	nb = 8;
	str = "% #020+llo\n";
	mat = malloc(8);
	mat[0] = malloc(4);
	mat[0][0] = 33;
	ret = printf(str, nb);
	ret1 = ft_printfd(1, str, nb);
	if (ret != ret1)
		ft_printf("difference: ret = %d, retfd = %d\n", ret, ret1);
	return (0);
}
