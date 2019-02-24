/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_read_tag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:35:16 by erli              #+#    #+#             */
/*   Updated: 2019/02/24 19:26:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Exctract tag information and move cursor to first caracter after conversion
** If there is a non defined flag, move pointer to right location.
** Return -1 if it encounters a non defined flags.
*/

int				pfd_read_tag(t_pfd_data *data, char *format, size_t *i)
{
	while (format[*i] != '\0' && ft_char_at_pos(format[*i], format_flags) > 0)
	{



	}
	
	if (data == 0 || format == 0 || i == 0)
		return (-1);
	return (0);
}

