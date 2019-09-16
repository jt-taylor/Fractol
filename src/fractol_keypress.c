/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:39:59 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/16 13:12:10 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	redraw_fractol(t_fractol *f)
{
//	int	x = 0;
//	int	y = 0;
//	f->frac.current_iteration = 0;
//	while (y++ < HEIGHT)
//		while (x++ < WIDTH)
//			ft_mlx_img_pixel_put(f, x, y);
	ft_bzero(f->img.data_start, (WIDTH * HEIGHT * 4));
	draw_fractol(f);
	mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.window_ptr, f->img.image_ptr, 0, 0);
}

static inline void	reinit_fractol_options(t_fractol *f)
{
	f->frac.iterations = 30;
	f->frac.current_iteration = 0;
	f->frac.max_irat = f->frac.min_irat + (f->frac.max_real - f->frac.min_real)
		* HEIGHT / WIDTH;
	f->frac.re_factor = (f->frac.max_real - f->frac.min_real) / (WIDTH - 1);
	f->frac.ir_factor = (f->frac.max_irat - f->frac.min_irat) / (HEIGHT - 1);
}

// zoom + and - are not inverses , i just don't think it's worth it to do that much more precision
int		fractol_mousepress(int keycode, int x, int y, t_fractol *f)
{
	f->frac.mouse_x = x;
	f->frac.mouse_y = y;
	if (keycode == 0x04)
		f->frac.zoom *= .95;
	else if (keycode == 0x05)
		f->frac.zoom *= 1.05;
	else
		;
	reinit_fractol_options(f);
	redraw_fractol(f);
//	ft_printf("keycode == %X\n", keycode);
	return (0);
}
int		fractol_keypress(int keycode, t_fractol *f)
{
	if (keycode == 0x7b)
	{
		f->frac.max_real += .05 * (1 / f->frac.zoom);
		f->frac.min_real += .05 * (1 / f->frac.zoom);
	}
	else if (keycode == 0x7c)
	{
		f->frac.max_real -= .05 * (1 / f->frac.zoom);
		f->frac.min_real -= .05 * (1 / f->frac.zoom);
	}
	else if (keycode == 0x7d)
		f->frac.min_irat -= .05 * (1 / f->frac.zoom);
	else if (keycode == 0x7e)
		f->frac.min_irat += .05 * (1 / f->frac.zoom);
	else if (keycode == 0x35)
		exit(0);
	reinit_fractol_options(f);
	redraw_fractol(f);
	ft_printf("keycode == %X\n", keycode);
	return (0);
}
