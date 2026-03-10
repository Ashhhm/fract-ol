/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:51:12 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/10 13:39:48 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_com	com_square(t_com z)
{
	t_com	result;

	result.r = (z.r * z.r) - (z.i * z.i);
	result.i = 2 * z.r * z.i;
	return (result);
}

t_com	com_sum(t_com z1, t_com z2)
{
	t_com	result;

	result.r = z1.r + z2.r;
	result.i = z1.i + z2.i;
	return (result);
}

double	d_atoi(char *str)
{
	long	e_r;
	double	dec;
	double	vir;
	int		i;
	int		sign;

	(1 && (dec = 0), (e_r = 0), (i = 0), (sign = 1), (vir = 1));
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		e_r = e_r * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		vir /= 10;
		dec = dec + (str[i++] - '0') * vir;
	}
	return ((e_r + dec) * sign);
}
