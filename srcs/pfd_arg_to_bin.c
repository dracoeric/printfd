/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_arg_to_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:00:35 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 17:58:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Read the right amout of byte in memory pointed by ptr then right it in hex
** in buf.
*/

static	int	pfd_write_bin(t_pfd_data *data, void *arg, size_t nb_bytes,
				size_t len)
{
	char			str[len + 1];
	size_t			i;
	size_t			j;
	int				k;
	unsigned char	*ptr;

	i = 0;
	j = 0;
	ft_bzero(str, len + 1);
	ptr = (unsigned char *)arg;
	while (i < nb_bytes)
	{
		k = 0;
		while (k < 8)
		{
			str[j++] = ((ptr[i] & (1 << (7 - k))) ? '1' : '0');
			k++;
		}
		i++;
		if (i < nb_bytes)
			str[j++] = ' ';
	}
	return (pfd_add_width(data, str, len));
}

int			pfd_arg_to_bin(t_pfd_data *data, void *ptr)
{
	size_t	nb_bytes;
	size_t	total_len;

	total_len = 0;
	if (data->tag->flags & (63 << 14))
		nb_bytes = pfd_num_type_size(data->tag->flags);
	else if (data->tag->flags & (7 << 20))
		nb_bytes = (data->tag->flags & BL_MOD ? LD_SIZE : D_SIZE);
	else if (data->tag->flags & S_CONV)
		nb_bytes = (ptr == 0 ? 0 : ft_strlen((char *)ptr));
	else if (data->tag->flags & P_CONV)
		nb_bytes = sizeof(void *);
	else
		nb_bytes = 1;
	total_len = (9 * nb_bytes) - 1;
	if (ptr == NULL)
		return (pfd_add_width(data, "(null)", 6));
	return (pfd_write_bin(data, ptr, nb_bytes, total_len));
}
