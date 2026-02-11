/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:33:37 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/11 17:25:37 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	mem_fail(void)
{
	perror("Memory allocation fail");
	exit(EXIT_FAILURE);
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
	fractal_create(fractol); // todo
	data_create(fractol);    //  todo
}

void	fract_screen(t_fract *fractol)
{
	
}
