/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:08:22 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/16 20:14:29 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** the mlx_image functionality treats the whole image as one stream of data
** --> use the line and pixel_width offsets to reach the desired pixel
**
** things to do here --
** 		change the color values to come fromt the struct so they aren't static
** 			handle the color based on depth here (?)
** 		move the x && y parameters into the struct >?
*/

void		ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord)
{
	int		off;
	double	mult;

	mult = 255 / f->frac.iterations;
	off = (x_cord + (y_cord * WIDTH)) * 4;
	if (f->frac.current_iteration == 0)
	{
		f->img.data_start[off] = 0x00;
		f->img.data_start[off + 1] = 0x00;
		f->img.data_start[off + 2] = 0x00;
	}
	else
	{
		f->img.data_start[off] = (char)(f->color.green - (mult * .7)
				* f->frac.current_iteration);
		f->img.data_start[off + 1] = (char)(f->color.blue - (mult * .3)
				* f->frac.current_iteration);
		f->img.data_start[off + 2] = (char)(f->color.red - mult
				* f->frac.current_iteration);
	}
}
