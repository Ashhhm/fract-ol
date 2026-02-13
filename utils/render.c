/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:14:15 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/13 11:02:28 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

double  get_scale(double u_num, double n_min, double n_max, double o_max)
{
    double  old_min;

    old_min = 0;
    return (n_max - n_min) * (u_num - old_min) / (o_max - old_min) + n_min;
}
void    get_pixel(int x, int y, t_fract *fractol)
{
    t_com   z;
    t_com   c;

    z.r = 0.0;
    z.i = 0.0;
    c.r = get_scale(x, -2, 2, 949);
    c.i = get_scale(y, 2, -2, 949);
    while ()
    
}

void	fractal_create(t_fract *fractol)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            get_pixel(x, y, fractol);
            x++;
        }
        y++;
    }
}

void    data_create(t_fract *fractol)
{
    
}
