/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:27:46 by erli              #+#    #+#             */
/*   Updated: 2019/02/25 15:27:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <stdlib.h>

# define PRINT_B_SIZE 2043

# define TAG_CHARS "#0 -+.123456789hzjlbtmdiuoxXcspf%eg"
# define FORMAT_FLAGS "0# -+"
# define MODIFIERS "hlLtmbzj"
# define CONVERSION "diouxXcspfeg%"

# define ZERO 1
# define POUND (1 << 1)
# define MINUS (1 << 2)
# define PLUS (1 << 3)
# define SPACE (1 << 4)

# define HH_MOD (1 << 5)
# define LL_MOD (1 << 6)
# define H_MOD (1 << 7)
# define L_MOD (1 << 8)
# define BL_MOD (1 << 9)
# define T_MOD (1 << 10)
# define M_MOD (1 << 11)
# define B_MOD (1 << 12)

# define D_CONV (1 << 13)
# define I_CONV (1 << 14)
# define O_CONV (1 << 15)
# define U_CONV (1 << 16)
# define X_CONV (1 << 17)
# define BX_CONV (1 << 18)
# define C_CONV (1 << 19)
# define S_CONV (1 << 20)
# define P_CONV (1 << 21)
# define F_CONV (1 << 22)
# define E_CONV	(1 << 23)
# define G_CONV (1 << 24)
# define PER_CONV (1 << 25)
# define NO_CONV (1 << 26)

typedef struct		s_pfd_tag
{
	int		flags;
	int		width;
	int		precision;
	int		nb_line;
	int		nb_col;
}					t_pfd_tag;

typedef struct		s_pfd_data
{
	int			fd;
	char		buf[PRINT_B_SIZE + 1];
	int			cursor;
	size_t		ret;
	t_pfd_tag	*tag;
}					t_pfd_data;

typedef	int (*t_pfd_conv)(t_pfd_data *, va_list);

int					ft_printfd(int fd, char *format, ...);
int					pfd_add_char(t_pfd_data *data, char c);
int					pfd_unload_buf(t_pfd_data *data);
int					pfd_manage_tag(t_pfd_data *data, char *format,
						va_list ap, size_t *i);
int					pfd_read_tag(t_pfd_data *data, char *format, size_t *i);
int					pfd_convert(t_pfd_data *data, va_list ap);

int					pfd_no_conv(t_pfd_data *data, va_list ap);
int					pfd_conv_d(t_pfd_data *data, va_list ap);

void				pfd_print_data(t_pfd_data *data);


#endif
