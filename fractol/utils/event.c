/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:55:31 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/04 18:10:06 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header/fractol.h"
#include <stdlib.h>
#include "../libft/libft.h"

int close_programm(t_fract *fractol)
{
    mlx_destroy_image(fractol->mlx_connect, fractol->img.img_ptr);
    mlx_destroy_window(fractol->mlx_connect, fractol->mlx_window);
    mlx_destroy_display(fractol->mlx_connect);
    free(fractol->mlx_connect);
    exit(EXIT_SUCCESS);
}

int key_manager(int key_value, t_fract *fractol)
{
    if (key_value == XK_Escape)
        close_programm(fractol);
    else if (key_value == XK_Left)
        fractol->shift_x += (0.5 * fractol->zoom);
    else if (key_value == XK_Right)
        fractol->shift_x -= (0.5 * fractol->zoom);
    else if (key_value == XK_Up)
        fractol->shift_y -= (0.5 * fractol->zoom);
    else if (key_value == XK_Down)
        fractol->shift_y += (0.5 * fractol->zoom);
    else if (key_value == XK_plus)
        fractol->nb_it += 10;
    else if (key_value == XK_minus)
        fractol->nb_it -= 10;
    fractal_create(fractol);
    return (0);    
}

int mouse_manager(int button, t_fract *fractol)
{
    if (button == Button5)
        fractol->zoom *= 0.95;
    else if (button == Button4)
        fractol->zoom *= 1.05;
    fractal_create(fractol);
    return (0);
}

int julia_mouse_manager(int x, int y, t_fract *fractol)
{
    if (!ft_strncmp(fractol->title, "julia", 5))
    {
        fractol->julia_x = (get_scale(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
        fractol->julia_y = (get_scale(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
        fractal_create(fractol);
    }
    return (0);
}
