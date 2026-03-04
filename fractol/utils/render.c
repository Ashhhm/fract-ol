/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:14:15 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/04 17:47:50 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void    ft_my_pixel_put(int x, int y, t_image *img, int col)
{
    char    *dst;

    dst = img->pix_ptr + (y * img->l_len + x * (img->bpp / 8));
    *(unsigned int*)dst = col;
}

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
    int     i;
    int     col;

    i = 0;
    z.r = 0.0;
    z.i = 0.0;
    c.r = get_scale(x, -2, 2, 949) + fractol->shift_x;
    c.i = get_scale(y, 2, -2, 949) + fractol->shift_y;
    while (i < fractol->nb_it)
    {
        z = com_sum(com_square(z), c);
        if ((z.r * z.r) + (z.i * z.i) > fractol->esc)
        {
            col = get_scale(i, BLACK, WHITE, fractol->nb_it);
            ft_my_pixel_put(x, y, &fractol->img, col);
            return ;
        }
        i++;
    }
    ft_my_pixel_put(x, y, &fractol->img, MATRIX_GREEN);
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
    mlx_put_image_to_window(fractol->mlx_connect, fractol->mlx_window,
                            fractol->img.img_ptr,
                            0, 0);
}


