/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:09:53 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/04 23:14:15 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 950
# define HEIGHT 950

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define PSYCHEDELIC_PURPLE 0x660066
# define MATRIX_GREEN 0x00FF41

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
	double	esc;
	int		nb_it;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}			t_fract;

typedef struct s_com
{
	double	r;
	double	i;
}			t_com;

/*init.c*/
void		mem_fail(void);
void		fract_init(t_fract *fractol);
void		data_create(t_fract *fractol);

/*render.c*/
void		fractal_create(t_fract *fractol);
void		get_pixel(int x, int y, t_fract *fractol);
double		get_scale(double u_num, double n_min, double n_max, double o_max);
void		ft_my_pixel_put(int x, int y, t_image *img, int col);

/*math.c*/
t_com		com_square(t_com z);
t_com		com_sum(t_com z1, t_com z2);

/*event.c*/
int			close_programm(void *param);
int			key_manager(int key_value, void *param);
int			mouse_manager(int button, int x, int y, void *param);
int			julia_mouse_manager(int x, int y, t_fract *fractol);

#endif