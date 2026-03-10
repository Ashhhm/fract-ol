/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:44:45 by hammeah           #+#    #+#             */
/*   Updated: 2026/03/06 16:37:50 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_fract	fractol;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.title = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractol.julia_r = d_atoi(av[2]);
			fractol.julia_i = d_atoi(av[3]);
		}
		fract_init(&fractol);
		fractal_create(&fractol);
		mlx_loop(fractol.mlx_connect);
	}
	else
	{
		ft_putstr_fd(ERR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}

