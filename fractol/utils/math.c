/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:51:12 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/13 11:00:38 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_com  com_square(t_com z)
{
    t_com   result;
    
    result.r = (z.r * z.r) - (z.i * z.i);
    result.i = 2 * z.r * z.i;

    return (result);
}

t_com   com_sum(t_com z1, t_com z2)
{
    t_com   result;

    result.r = z1.r + z2.r;
    result.i = z1.i +z2.i;
    return (result);
}
