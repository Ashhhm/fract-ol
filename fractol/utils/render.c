/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:14:15 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/04 23:23:20 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	ft_my_pixel_put(int x, int y, t_image *img, int col)
{
	char	*dst;

	dst = img->pix_ptr + (y * img->l_len + x * (img->bpp / 8));
	*(unsigned int *)dst = col;
}

double	get_scale(double u_num, double n_min, double n_max, double o_max)
{
	double	old_min;

	old_min = 0;
	return ((n_max - n_min) * (u_num - old_min) / (o_max - old_min) + n_min);
}

void	get_pixel(int x, int y, t_fract *fr)
{
	t_com	z;
	t_com	c;
	int		i;
	int		col;
	double	s;

	i = 0;
	z.r = 0.0;
	z.i = 0.0;
	s = 4.0 / fr->zoom;
	c.r = get_scale(x, -s / 2 + fr->shift_x, s / 2 + fr->shift_x, WIDTH - 1);
	c.i = get_scale(y, -s / 2 + fr->shift_y, s / 2 + fr->shift_y, HEIGHT - 1);
	while (i < fr->nb_it)
	{
		z = com_sum(com_square(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fr->esc)
		{
			col = get_scale(i, BLACK, WHITE, fr->nb_it);
			ft_my_pixel_put(x, y, &fr->img, col);
			return ;
		}
		i++;
	}
	ft_my_pixel_put(x, y, &fr->img, MATRIX_GREEN);
}

void	fractal_create(t_fract *fr)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			get_pixel(x, y, fr);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx_connect, fr->mlx_window, fr->img.img_ptr, 0,
		0);
}
