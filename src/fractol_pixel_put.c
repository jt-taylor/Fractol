/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:08:22 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/12 17:16:02 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** the mlx_image functionality treats the whole image as one stream of data
** --> use the line and pixel_width offsets to reach the desired pixel
**
** add in the color later
** this is just broken at the moment
*/

//void		ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord)
//{
//	int		position_offset;
//	unsigned int	color;
//
//	color = mlx_get_color_value(f->mlx.mlx_ptr, 0xFFFF00);
//	//this neds to chagnge wiht resizing the window
//	position_offset = ((y_cord * 500) + (x_cord));// * f->img.bpp));
//	f->img.data_start[position_offset] = color;
//	mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.window_ptr, f->img.image_ptr, 0, 0);
//}

void		ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord)
{
	int		off;

	off = (x_cord + (y_cord * 500)) * 4;
	f->img.data_start[off] = 0xFF;
	f->img.data_start[off + 1] = 0xfa;
	f->img.data_start[off + 2] = 0x00;
}
