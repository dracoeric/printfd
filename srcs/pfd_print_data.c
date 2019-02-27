/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_print_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:57:04 by erli              #+#    #+#             */
/*   Updated: 2019/02/27 11:59:41 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"

static	void	pfd_print_format(t_pfd_tag *tag)
{
	ft_putstr("format flags: ");
	if (tag->flags & POUND)
		ft_putstr("# ");
	if (tag->flags & ZERO)
		ft_putstr("0 ");
	if (tag->flags & MINUS)
		ft_putstr("- ");
	if (tag->flags & SPACE)
		ft_putstr("_ ");
	if (tag->flags & PLUS)
		ft_putstr("+\n");
	else
		ft_putchar('\n');
}

static	void	pfd_print_mod(t_pfd_tag *tag)
{
	ft_putstr("modifier:     ");
	if (tag->flags & H_MOD)
		ft_putstr("h ");
	if (tag->flags & HH_MOD)
		ft_putstr("hh ");
	if (tag->flags & L_MOD)
		ft_putstr("l ");
	if (tag->flags & LL_MOD)
		ft_putstr("ll ");
	if (tag->flags & BL_MOD)
		ft_putstr("L ");
	if (tag->flags & T_MOD)
		ft_putstr("t ");
	if (tag->flags & M_MOD)
		ft_putstr("m ");
	if (tag->flags & MEM_MOD)
		ft_putstr("M ");
	if (tag->flags & B_MOD)
		ft_putstr("b\n");
	else
		ft_putchar('\n');
}

static	void	pfd_print_conv2(t_pfd_tag *tag)
{
	if (tag->flags & F_CONV)
		ft_putstr("f\n");
	if (tag->flags & E_CONV)
		ft_putstr("e\n");
	if (tag->flags & G_CONV)
		ft_putstr("g\n");
	if (tag->flags & NO_CONV)
		ft_putstr("no converter\n");
}

static	void	pfd_print_conv(t_pfd_tag *tag)
{
	ft_putstr("conversion:   ");
	if (tag->flags & D_CONV)
		ft_putstr("d\n");
	if (tag->flags & I_CONV)
		ft_putstr("i\n");
	if (tag->flags & O_CONV)
		ft_putstr("o\n");
	if (tag->flags & U_CONV)
		ft_putstr("u\n");
	if (tag->flags & X_CONV)
		ft_putstr("x\n");
	if (tag->flags & BX_CONV)
		ft_putstr("X\n");
	if (tag->flags & C_CONV)
		ft_putstr("c\n");
	if (tag->flags & S_CONV)
		ft_putstr("s\n");
	if (tag->flags & P_CONV)
		ft_putstr("p\n");
	pfd_print_conv2(tag);
}

void			pfd_print_data(t_pfd_data *data)
{
	ft_printf("\n==== Printing data ====\nfd =           %d\n", data->fd);
	ft_printf("buf =         '%s'\n", data->buf);
	ft_printf("cursor =      %d\n", data->cursor);
	ft_printf("pointing at:  '%c'\n", data->buf[data->cursor]);
	ft_printf("ret =         %d\n", data->ret);
	if (data->tag == 0)
		ft_putstr("no tag\n\n");
	else
	{
		ft_putstr("--------- tag ---------\n");
		pfd_print_format(data->tag);
		pfd_print_mod(data->tag);
		pfd_print_conv(data->tag);
		ft_printf("width =       %d\n", data->tag->width);
		ft_printf("precision =   %d\n", data->tag->precision);
		ft_printf("nb_col =      %d\n", data->tag->nb_col);
		ft_printf("nb_line =     %d\n\n", data->tag->nb_line);
	}
}
