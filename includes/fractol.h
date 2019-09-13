/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:10:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/12 13:19:06 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

/*
** macros
*/
# define WINDOW_SIZE 500, 500

/*
** Structures
*/

typedef struct	g_mlx_image
{
	void			*image_ptr;
	char			*data_start;
	int				bpp;
	int				size_line;
	int				endian;
}				t_mlx_image;

typedef struct	s_minilibx
{
	void			*mlx_ptr;
	void			*window_ptr;
}				t_minilibx;

typedef struct	s_fractal_data
{
	int				type;
	int				depth;
	int				iterate;
	//a bunch of double for the actual drawing;
}				t_fractal_data;

typedef struct	s_fractol
{
	t_minilibx		mlx;
	t_mlx_image		img;
	t_fractal_data	frac;
	int				fractol_opt;
}				t_fractol;

/*
**
*/
void		ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord);

#endif
