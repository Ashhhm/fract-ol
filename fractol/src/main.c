/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:44:45 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/20 14:30:04 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_fract	fractol;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		// change th estrncmp function
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.title = av[1];
		fract_init(&fractol);
		fractal_create(&fractol);
		mlx_loop(fractol.mlx_connect);
	}
	else
	{
		ft_putstr_fd("error", STDERR_FILENO);
		exit(EXIT_FAILURE);
		// function to print error msg;
		// and exit programme
	}
}
