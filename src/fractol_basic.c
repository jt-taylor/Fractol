/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:52:17 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/16 12:35:24 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdbool.h>


static inline void	fractol_color_default(t_fractol *f)
{
	f->color.red = 0xff;
	f->color.green = 0x0f;
	f->color.blue = 0x08;
}

void	init_fractol_options(t_fractol *f)
{
	f->frac.iterations = 30;
	f->frac.current_iteration = 0;
	f->frac.zoom = 1.0;
	f->frac.min_real = -2.0;
	f->frac.max_real = 2.0;
	f->frac.min_irat = -2.0;
	f->frac.mouse_x = WIDTH / 3;
	f->frac.mouse_y = HEIGHT / 3;
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

	fractol_color_default(f);
	y = 0;
	while (y < HEIGHT)
	{
		f->frac.c_irat = f->frac.zoom * (f->frac.max_irat - (y * f->frac.ir_factor));
		x = 0;
		while (x < WIDTH)
		{
			boole = g_fractol_loops[f->fractol_opt](f, x);
			if (!boole)
				ft_mlx_img_pixel_put(f, (int)x, (int)y);
			x++;
		}
		y++;
	}
}
