/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:14:15 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/05 22:45:49 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include "../libft/libft.h"

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

void	ft_julia_set(t_com *z, t_com *c, t_fract *fr)
{
	if (!ft_strncmp(fr->title, "julia", 5))
	{
		c->r = fr->julia_r;
		c->i = fr->julia_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

void	get_pixel(int x, int y, t_fract *fr)
{
	t_com	z;
	t_com	c;
	int		i;
	int		col;
	double	s;

	i = 0;
	s = 4.0 / fr->zoom;
	if (!ft_strncmp(fr->title, "mandelbrot", 10))
	{
		z.r = 0;
		z.i = 0;
		c.r = get_scale(x, -s / 2 + fr->shift_r, s / 2 + fr->shift_r, WIDTH - 1);
		c.i = get_scale(y, -s / 2 + fr->shift_i, s / 2 + fr->shift_i, HEIGHT - 1);
	}
	else
	{
		z.r = get_scale(x, -s / 2 + fr->shift_r, s / 2 + fr->shift_r, WIDTH - 1);
		z.i = get_scale(y, -s / 2 + fr->shift_i, s / 2 + fr->shift_i, HEIGHT - 1);
		c.r = fr->julia_r;
		c.i = fr->julia_i;
	}
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
