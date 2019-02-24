/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_read_tag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:35:16 by erli              #+#    #+#             */
/*   Updated: 2019/02/24 18:40:23 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"

/*
** Exctract tag information and move cursor to first caracter after conversion
** If there is a non defined flag, move pointer to right location.
** Return -1 if it encounters a non defined flags.
*/

int				pfd_read_tag(t_data *data, char *format, int *i)
{
	if (data == 0 || format == 0 || i == 0)
		return (-1);
	return (0);
}	
