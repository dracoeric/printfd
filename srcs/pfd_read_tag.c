/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_read_tag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:35:16 by erli              #+#    #+#             */
/*   Updated: 2019/03/04 13:34:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

/*
** Reads and light format flags "0# -+"
*/

static	void	pfd_read_flags(t_pfd_tag *tag, char *format, size_t *i)
{
	while (format[*i] != '\0' && ft_char_at_pos(format[*i], FORMAT_FLAGS) >= 0)
	{
		if (format[*i] == '0' && (tag->flags & MINUS) == 0)
			tag->flags = (tag->flags | ZERO);
		else if (format[*i] == ' ' && (tag->flags & PLUS) == 0)
			tag->flags = (tag->flags | SPACE);
		else if (format[*i] == '-')
			tag->flags = (tag->flags | MINUS) - (tag->flags & ZERO);
		else if (format[*i] == '+')
			tag->flags = (tag->flags | PLUS) - (tag->flags & SPACE);
		else if (format[*i] == '#')
			tag->flags = (tag->flags | POUND);
		*i += 1;
	}
}

static	int		pfd_atoi(char *format, size_t *i)
{
	int nb;

	nb = 0;
	while (ft_isdigit(format[*i]) > 0)
	{
		nb = (nb * 10) + (int)(format[*i] - '0');
		*i += 1;
	}
	return (nb);
}

/*
** Reads width if first char is digit != '0', and read precision if format[*i]
** is '.'
*/

static	void	pfd_read_width_and_prec(t_pfd_tag *tag, char *format,
					size_t *i, va_list ap)
{
	if (ft_isdigit(format[*i]) > 0)
		tag->width = pfd_atoi(format, i);
	else if (format[*i] == '*')
	{
		tag->width = va_arg(ap, int);
		*i += 1;
	}
	else if (format[*i] == '.')
	{
		*i += 1;
		if (format[*i] == '*')
		{
			*i += 1;
			tag->precision = va_arg(ap, int);
		}
		else
			tag->precision = pfd_atoi(format, i);
	}
}

/*
** Reads and store modifiers. Modifiers must be followed by a conversion.
** Sensible to .h changes
*/

static	void	pfd_read_mod(t_pfd_tag *tag, char *format,
					size_t *i)
{
	int pos;

	while (format[*i] != '\0'
		&& (pos = ft_char_at_pos(format[*i], MODIFIERS)) >= 0)
	{
		if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			tag->flags = ((tag->flags & (-1 - (31 << 5))) | LL_MOD);
			*i += 1;
		}
		else if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			tag->flags = ((tag->flags & (-1 - (31 << 5))) | HH_MOD);
			*i += 1;
		}
		else if (pos < 3)
			tag->flags = ((tag->flags & (-1 - (31 << 5))) | (H_MOD << pos));
		else if (pos < 5)
			tag->flags = ((tag->flags & (-1 - (3 << 10))) | (H_MOD << pos));
		else if (pos < 7)
			tag->flags = ((tag->flags & (-1 - (3 << 12))) | (H_MOD << pos));
		*i += 1;
	}
}

/*
** Exctract tag information and move cursor to first caracter after conversion
** If there is a non defined flag, move pointer to right location.
** Return -1 if it encounters a non defined flags.
*/

int				pfd_read_tag(t_pfd_data *data, char *format, size_t *i,
					va_list ap)
{
	int	pos;

	while (format[*i] != '\0' && ft_char_at_pos(format[*i], TAG_CHARS) >= 0
		&& data->tag->flags >> 14 == 0)
	{
		pfd_read_flags(data->tag, format, i);
		pfd_read_width_and_prec(data->tag, format, i, ap);
		pfd_read_mod(data->tag, format, i);
		pos = ft_char_at_pos(format[*i], CONVERSION);
		if (format[*i] != '\0' && pos >= 0)
		{
			data->tag->flags = (data->tag->flags | (D_CONV << pos));
			*i += 1;
		}
	}
	if (data->tag->flags >> 14 == 0)
	{
		data->tag->flags = (data->tag->flags | NO_CONV);
		data->no_conv = (format[*i] == '\0' ? '\0' : format[*i]);
		*i += (format[*i] == '\0' ? 0 : 1);
	}
	return (1);
}
