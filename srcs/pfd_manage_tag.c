/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_manage_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:06:23 by erli              #+#    #+#             */
/*   Updated: 2019/02/24 18:45:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Manage_tag manages the %~~~ tag, treat it correctly then write the content
** in the buffer
*/

int			pfd_manage_tag(t_pfd_data *data, char *format, va_list ap,
				size_t *i)
{
	t_pfd_tag	tag[1];
	int			ret;
	
	ft_bzero(tag, sizeof(t_pfd_tag));
	data->tag = tag;
	*i += 1;
	if ((ret = pfd_read_tag(data, format, i)) < 0)
		return (-1);
	else if (ret == 0)
		return (1);
	if (pfd_convert(data, ap) < 0)
		return (-1);
	return (1);
}
