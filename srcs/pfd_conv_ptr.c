/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:35:47 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 12:50:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	int	pfd_null_ptr_prec(t_pfd_data *data)
{
	char	str[3 + data->tag->precision];
	int		i;

	ft_bzero(str, 3 + data->tag->precision);
	ft_strncpy(str, "0x", 2);
	i = 0;
	while (i < data->tag->precision)
	{
		str[2 + i] = '0';
		i++;
	}
	return (pfd_add_width(data, str, 2 + data->tag->precision));
}

int			pfd_conv_ptr(t_pfd_data *data, va_list ap)
{
	unsigned long	nb;
	void			*addr;

	addr = va_arg(ap, void *);
	if (addr == NULL && data->tag->precision == -1)
		return (pfd_add_width(data, "0x0", 3));
	nb = (unsigned long)addr;
	data->tag->flags ^= P_CONV;
	data->tag->flags |= X_CONV;
	data->tag->flags |= L_MOD;
	data->tag->flags |= POUND;
	if (addr == NULL)
		return (pfd_null_ptr_prec(data));
	return (pfd_num_to_str(data, (unsigned long long)nb));
}
