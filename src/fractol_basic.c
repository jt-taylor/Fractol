/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:52:17 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/13 20:54:41 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>


static inline void	fractol_color_default(t_fractol *f)
{
	f->color.red = 0xff;
	f->color.green = 0x00;
	f->color.blue = 0x00;
}

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

void				draw_fractol(t_fractol *f)
{
	unsigned		y;
	unsigned		x;
	int				boole;

	init_fractol_options(f);
	fractol_color_default(f);
	y = 0;
	while (y < HEIGHT)
	{
		f->frac.c_irat = f->frac.max_irat - (y * f->frac.ir_factor);
		x = 0;
		while (x < WIDTH)
		{
			boole = g_fractol_loops[f->fractol_opt](f, x);
	//		if (boole)
			ft_mlx_img_pixel_put(f, (int)x, (int)y);
			x++;
		}
		y++;
	}
}
