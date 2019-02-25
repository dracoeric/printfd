/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/02/25 18:52:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include <stdio.h>
#include "libft.h"

int		main(void)
{
	int				ret;
	unsigned int	u;

	ret = ft_printfd(1, "f,dishfgisekjfhk %4mtm.3#llLh+020c %hllhhlL%", "caca");
	ret = -1;
	u = (unsigned int)ret;
	ft_printf("unisnged = %u\n, u + 1 = %u\n", u, u + 1);
	ft_putnbr(ret);
	return (0);
}
