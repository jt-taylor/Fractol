/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:52:17 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/13 15:50:39 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>


// break this up to make it modular based off of which fractol you want
static inline void	init_fractol_options(t_fractol *f)
{
	f->frac.iterations = 30;
	f->frac.current_iteration = 0;
	f->frac.min_real = -2.0;
	f->frac.max_real = 1.0;
	f->frac.min_irat = -1.2;
	f->frac.max_irat = f->frac.min_irat + (f->frac.max_real - f->frac.min_real)
		* HEIGHT / WIDTH;
	f->frac.re_factor = (f->frac.max_real - f->frac.min_real) / (WIDTH - 1);
	f->frac.ir_factor = (f->frac.max_irat - f->frac.min_irat) / (HEIGHT - 1);
}

static inline int	fractal_inner_loop(t_fractol *f, int x)
{
	int	boole;

	f->frac.c_real = f->frac.min_real + (x * f->frac.re_factor);
	f->frac.z_real = f->frac.c_real;
	f->frac.z_irat = f->frac.c_irat;
	boole = 1;
	f->frac.current_iteration = 0;
	while (f->frac.current_iteration < f->frac.iterations)
	{
		f->frac.z_2real = f->frac.z_real * f->frac.z_real;
		f->frac.z_2irat = f->frac.z_irat * f->frac.z_irat;
		if ((f->frac.z_2real + f->frac.z_2irat) > 4)
		{
			boole = 0;
			break ;
		}
		f->frac.z_irat = 2 * f->frac.z_real * f->frac.z_irat + f->frac.c_irat;
		f->frac.z_real = f->frac.z_2real - f->frac.z_2irat + f->frac.c_real;
		f->frac.current_iteration++;
	}
	return (boole);
}

void				draw_fractol(t_fractol *f)
{
	unsigned		y;
	unsigned		x;
	int				boole;

	init_fractol_options(f);
	y = 0;
	while (y < HEIGHT)//y < image height
	{
		f->frac.c_irat = f->frac.max_irat - (y * f->frac.ir_factor);
		x = 0;
		while (x < WIDTH)//x < image width;
		{
			boole = fractal_inner_loop(f, x);
			if (boole)
				ft_mlx_img_pixel_put(f, (int)x, (int)y);
			x++;
		}
		y++;
	}
}
