/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:33:37 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/04 18:16:08 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	mem_fail(void)
{
	perror("Memory allocation fail");
	exit(EXIT_FAILURE);
}

void    data_create(t_fract *fractol)
{
	fractol->esc = 4;
	fractol->nb_it = 100;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

void	event_init(t_fract *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_manager,
		 fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, mouse_manager,
		 fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
		 close_programm, fractol);
}

void	fract_init(t_fract *fractol)
{
	fractol->mlx_connect = mlx_init();
	if (fractol->mlx_connect == NULL)
		mem_fail(); // TD
	fractol->mlx_window = mlx_new_window(fractol->mlx_connect, WIDTH, HEIGHT,
			fractol->title);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connect);
		free(fractol->mlx_connect);
		mem_fail();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connect, WIDTH, HEIGHT);
	if (fractol->img.img_ptr == NULL)
	{
		mlx_destroy_image(fractol->mlx_connect, fractol->img.img_ptr);
		mlx_destroy_display(fractol->mlx_connect);
		free(fractol->mlx_connect);
		mem_fail();
	}
	fractol->img.pix_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.l_len, &fractol->img.endian);
	event_init(fractol);
	fractal_create(fractol);
	data_create(fractol);
}


