/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_conv_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:35:47 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 18:44:37 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

int			pfd_conv_ptr(t_pfd_data *data, va_list ap)
{
	unsigned long	*nb;
	void			*addr;

	addr = va_arg(ap, void *);
	if (addr == NULL)
		return (pfd_add_width(data, "0x0", 3));
	nb = (unsigned long *)addr;
	data->tag->flags ^= P_CONV;
	data->tag->flags |= X_CONV;
	data->tag->flags |= L_MOD;
	data->tag->flags |= POUND;
	return (pfd_num_to_str(data, (unsigned long long)nb));
}
