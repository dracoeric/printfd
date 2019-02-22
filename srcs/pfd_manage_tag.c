/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_manage_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:06:23 by erli              #+#    #+#             */
/*   Updated: 2019/02/22 18:28:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Manage_tag manages the %~~~ tag, treat it correctly then write the content
** in the buffer
*/

int			pfd_manage_tag(t_pfd_data *data, char *format, va_list ap,
				size_t *i)
{
	if (data == 0 || format == 0 || ap == 0 || *i == 0)
		return (0);
	return (1);
}
