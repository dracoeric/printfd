/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:22:53 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 10:25:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

int			ft_printf(const char *format, ...)
{
	t_pfd_data	data[1];
	size_t		i;
	va_list		ap;
	int			ret;

	if (format == NULL)
		return (ft_msg_int(2, "ft_printfd: Null format string.\n", -1));
	ft_bzero(data, sizeof(t_pfd_data));
	data->fd = 1;
	i = 0;
	va_start(ap, format);
	ret = 1;
	while (format[i] != '\0' && ret > 0)
	{
		while (format[i] != '%' && format[i] != '\0' && ret > 0)
			ret = pfd_add_char(data, format[i++]);
		if (ret > 0 && format[i] == '%')
			ret = pfd_manage_tag(data, (char *)format, ap, &i);
	}
	va_end(ap);
	return (ret > 0 ? pfd_unload_buf(data) : ret);
}
