/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:09:53 by hammeah           #+#    #+#             */
/*   Updated: 2026/02/10 13:10:18 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "../mlx-linux/mlx.h"
#include "../mlx-linux/mlx_int.h"

typedef struct s_image
{
    void    *img_ptr;
    char    *pix_ptr;
    int     bpp;
    int     endian;
    int     l_len;
}               t_image;


typedef struct s_fract
{
    void    *mlx_connect;
    void    *mlx_window;
    t_image img;
    
    /* data */
}               t_fract;


typedef struct s_com
{
    double  r;
    double  i; 
}               t_com;

#endif