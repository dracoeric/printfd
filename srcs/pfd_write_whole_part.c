/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_write_whole_part_silde.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:47:42 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 17:44:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Print whole part. manage round up il E-conv and whole == 10.
*/

int				pfd_write_whole_part(t_pfd_data *data, char *str,
					unsigned long long whole, size_t i)
{
	if (whole == 0)
		str[i] = '0';
	while (whole != 0)
	{
		str[i--] = whole % 10 + '0';
		whole /= 10;
	}
	return (pfd_remove_trailing_zeros(data, str, ft_strlen(str)));
}
