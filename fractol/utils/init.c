/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:33:37 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/06 17:09:10 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	mem_fail(void)
{
	perror("Memory allocation fail");
	exit(EXIT_FAILURE);
}

void	data_create(t_fract *fractol)
{
	fractol->esc = 4;
	fractol->nb_it = 42;
	fractol->shift_r = 0.0;
	fractol->shift_i = 0.0;
	fractol->zoom = 1.0;
}
/**
 * @brief managing to listening events 
 * 
 * @param fractol t_fract struct
 */
void	event_init(t_fract *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_manager, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, mouse_manager,
		fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask,
		close_programm, fractol);
	mlx_hook(fractol->mlx_window, MotionNotify, PointerMotionMask,
		julia_mouse_manager, fractol);
}
/**
 * @brief creating the window using the mlx API and after we are initiating the t_fract struct
 * with the hook (mouse and keyboard) event.
 * 
 * @param fractol t_fract struct
 */
void	fract_init(t_fract *fractol)
{
	fractol->mlx_connect = mlx_init();
	if (fractol->mlx_connect == NULL)
		mem_fail();
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
	data_create(fractol);
}
