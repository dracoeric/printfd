/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 10:06:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int			main(void)
{
	int					ret;
	int					ret1;
	char				*str;
	char				*c;

	c = 0;
	str = "%#+ 10p%%\n";
	ret = printf(str, c);
	ret1 = ft_printf(str, c);
	if (ret != ret1)
		ft_printf("difference: ret = %d, retfd = %d\n", ret, ret1);
	return (0);
}
