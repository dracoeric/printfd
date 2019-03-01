/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_write_whole_part_silde.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:47:42 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 17:25:33 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Print whole part. manage round up il E-conv and whole == 10.
*/

static	void	pfd_whole_float_slide(char *str, unsigned long long whole,
					size_t i)
{
	unsigned long long	cpy;

	cpy = whole;
	while (cpy >= 10)
		cpy /= 10;
	if (cpy == 1 && whole != 1)
		ft_memmove(str + i + 2, str + i + 1, ft_strlen(str + i + 1));
	i += (cpy == 1 && whole != 1 ? 1 : 0);
	if (whole == 0)
		str[i] = '0';
	while (whole != 0)
	{
		str[i--] = whole % 10 + '0';
		whole /= 10;
	}
}

int				pfd_write_whole_part_slide(t_pfd_data *data, char *str,
					unsigned long long whole, size_t i)
{
	int	last;

	if (data->tag->flags & E_CONV && whole == 10)
	{
		if (data->tag->precision != 0)
		{
			ft_memmove(str + i + 3, str + i + 2, data->tag->precision + 1);
			str[i + 2] = '0';
		}
		str[i] = '1';
		last = ft_strlen(str) - 1;
		str[last] = (str[last] == '9' ? '0' : str[last] + 1);
		str[last - 1] += (str[last] == '0' ? 1 : 0);
	}
	else
		pfd_whole_float_slide(str, whole, i);
	return (pfd_remove_trailing_zeros(data, str, ft_strlen(str)));
}
