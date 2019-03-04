/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:21:45 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 18:19:21 by erli             ###   ########.fr       */
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
	char	*str;
	void	***c;

	c = malloc(sizeof(void **) * 2);
	c[0] = malloc(sizeof(void *) * 4);
	c[1] = malloc(sizeof(void *) * 4);
	c[0][0] = &c;
	c[0][1] = &str;
	c[0][2] = NULL;
	c[0][3] = NULL;
	c[1][0] = &(c[1]);
	c[1][1] = &(c[0]);
	c[1][2] = c[0];
	c[1][3] = c[1];
	str = "%mMp\n";
	ft_printf(str, c, 4, 2);
	return (0);
}
