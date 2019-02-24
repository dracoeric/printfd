/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfd.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:27:46 by erli              #+#    #+#             */
/*   Updated: 2019/02/24 18:15:39 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFD_H
# define FT_PRINTFD_H

# include <stdarg.h>
# include <stdlib.h>

# define PRINT_B_SIZE 2043

typedef struct		s_pfd_tag
{
	int 	flags;
	int		width;
	int		precision;
	char	conversion;
}					t_pfd_tag;

typedef struct		s_pfd_data
{
	int			fd;
	char		buf[PRINT_B_SIZE + 1];
	int			cursor;
	int			ret;
	t_pfd_tag	*tag;
}					t_pfd_data;

int					ft_printfd(int fd, char *format, ...);
int					pfd_add_char(t_pfd_data *data, char c);
int					pfd_unload_buf(t_pfd_data *data);
int					pfd_manage_tag(t_pfd_data *data, char *format,
						va_list ap, size_t *i);
int					pfd_read_tag(t_pfd_data *data, char *format, int *i);
int					pfd_convert(t_pfd_data *data, va_list ap);

#endif
