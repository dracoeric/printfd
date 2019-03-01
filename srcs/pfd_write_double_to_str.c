/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfd_write_double_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:52:22 by erli              #+#    #+#             */
/*   Updated: 2019/03/01 18:17:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printfd.h"
#include "libft.h"
#include <math.h>

/*
** Extract the sign and transform nb to (abs)nb.
*/

static	void	pfd_double_extract_sign(int flags, long double *nb,
						char *str, size_t *i)
{
	unsigned char	*ptr;
	char			sign;

	sign = '\0';
	ptr = (unsigned char *)nb;
	if (ptr[LD_SIZE - 1] & (1 << 7))
	{
		sign = '-';
		ptr[LD_SIZE - 1] ^= (1 << 7);
	}
	else if (flags & SPACE)
		sign = ' ';
	else
		sign = (flags & PLUS ? '+' : sign);
	if (sign != '\0')
		str[(*i)++] = sign;
}

static	void	pfd_write_exponent(t_pfd_tag *tag, char *str, int exp,
					size_t len)
{
	size_t	i;
	char	sign;

	i = len - 1;
	if (tag->flags & E_CONV)
	{
		sign = (exp < 0 ? '-' : '+');
		exp = (exp < 0 ? -exp : exp);
		if (exp == 0)
			str[i--] = '0';
		while (exp != 0)
		{
			str[i--] = (exp % 10) + '0';
			exp /= 10;
		}
		if (i == len - 2)
			str[i--] = '0';
		str[i--] = sign;
		str[i--] = 'e';
	}
}

/*
** Print the float part and do the round up. return 1 if round up pursue in
** whole part.
*/

static	int		pfd_write_float_part(t_pfd_tag *tag, char *str,
					long double nb, size_t i)
{
	size_t		j;
	long double	ret;

	nb = nb - ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT);
	j = 0;
	nb *= 10;
	if (tag->precision == 0)
		return ((int)nb >= 5 ? 1 : 0);
	str[i++] = DECIMAL_POINT;
	while (j < (size_t)tag->precision)
	{
		str[i + j] = ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT)
			% 10 + '0';
		j++;
		nb = (nb - (int)nb) * 10;
	}
	ret = (ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT) % 10 >= 5 ? 1.0 : 0.0);
	while (ret == 1.0 && j > 0)
	{
		j--;
		str[i + j] = (str[i + j] == '9' ? '0' : str[i + j] + 1);
		ret = (str[i + j] == '0' ? 1.0 : 0.0);
	}
	return (ret);
}

static	int		pfd_double_infinity(t_pfd_data *data, long double nb)
{
	char	str[5];
	size_t	i;
	size_t	len;

	i = 0;
	len = 3;
	ft_bzero(str, 5);
	pfd_double_extract_sign(data->tag->flags, &nb, str, &i);
	if (str[0] != '\0')
		len++;
	ft_strcpy(str + i, "inf");
	return (pfd_add_width(data, str, len));
}

int				pfd_write_double_to_str(t_pfd_data *data, long double nb,
					int exp, size_t len)
{
	unsigned long long	whole;
	unsigned long long	ret;
	char				str[len + 2];
	size_t				i;

	i = 0;
	ft_bzero(str, len + 2);
	if (nb == INFINITY || nb == -INFINITY)
		return (pfd_double_infinity(data, nb));
	pfd_double_extract_sign(data->tag->flags, &nb, str, &i);
	pfd_write_exponent(data->tag, str, exp, len);
	whole = ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT);
	while (whole >= 10)
	{
		whole /= 10;
		i += 1;
	}
	ret = pfd_write_float_part(data->tag, str, nb, i + 1);
	whole = ft_double_whole(nb, LD_SIZE, LD_NB_EXP_BIT) + ret;
	if (ret == 1)
		return (pfd_write_whole_part_slide(data, str, whole, i));
	return (pfd_write_whole_part(data, str, whole, i));
}
