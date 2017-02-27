/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_none.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:08:57 by kcheung           #+#    #+#             */
/*   Updated: 2017/02/23 13:22:45 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	pf_handle_none(char **fmt, va_list args, t_fmt *fl)
{
	size_t			nbrlen;
	unsigned int	strlen;
	ssize_t			ret;

	nbrlen = 1;
	ret = 0;
	strlen = pf_calclen(nbrlen, fl, NULL, NULL);
	if (fl->width && !fl->left_justify)
	{
		if (fl->pad_zeroes)
			ret += pf_pad(nbrlen, fl->width_val, '0');
		else
			ret += pf_pad(nbrlen, fl->width_val, ' ');
	}
	ft_putchar(**fmt);
	ret += nbrlen;
	if (fl->left_justify)
		ret += pf_pad(nbrlen, fl->width_val, ' ');
	args = NULL;
	return (ret);
}
