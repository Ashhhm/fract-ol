/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:09:53 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/13 11:01:47 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 950
# define HEIGHT 950

typedef struct s_image
{
	void	*img_ptr;
	char	*pix_ptr;
	int		bpp;
	int		endian;
	int		l_len;
}			t_image;

typedef struct s_fract
{
	void	*mlx_connect;
	void	*mlx_window;
	t_image	img;
	char	*title;
}			t_fract;

typedef struct s_com
{
	double	r;
	double	i;
}			t_com;

/*init.c*/
void		mem_fail(void);
void		fract_init(t_fract *fractol);
void		fract_screen(t_fract *fractol);

/*render.c*/
void        fractal_create(t_fract *fractol);
void    get_pixel(int x, int y, t_fract *fractol);
double  get_scale(double u_num, double n_min, double n_max, double o_max);


/*math.c*/
t_com  com_square(t_com z);
t_com   com_sum(t_com z1, t_com z2);

#endif