/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:22:53 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 13:47:06 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"
#include <unistd.h>

static	int	pfd_init_data(t_pfd_data *data, int fd)
{
	if (write(fd, "", 0) < 0)
		return (ft_msg_int(2, "ft_printfd: could not write in fd.\n", -1));
	ft_bzero(data, sizeof(t_pfd_data));
	data->fd = fd;
	return (1);
}

int			ft_printfd(int fd, char *format, ...)
{
	t_pfd_data	data[1];
	size_t		i;
	size_t		start;
	va_list		ap;
	int			ret;

	if (format == NULL)
		return (ft_msg_int(2, "ft_printfd: Null format string.\n", -1));
	ret = pfd_init_data(data, fd);
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0' && ret > 0)
	{
		start = i;
		while (format[i] != '%' && format[i] != '\0' && ret > 0)
			i++;
		ret = pfd_add_str(data, format, start, i - start);
		if (ret > 0 && format[i] == '%')
			ret = pfd_manage_tag(data, format, ap, &i);
	}
	va_end(ap);
	return (ret > 0 ? pfd_unload_buf(data) : ret);
}
