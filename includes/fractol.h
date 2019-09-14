/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:10:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/13 20:46:22 by jtaylor          ###   ########.fr       */
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
# define WIDTH 500
# define HEIGHT 500

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
	int		type;
	int		current_iteration;
	int		iterations;
	// 4 corners that make the boundry of the dispaly
	double			min_real;
	double			max_real;
	double			min_irat;
	double			max_irat;
	//constants in the formula
	double			re_factor;
	double			ir_factor;
	//to get a (pixel) cordinate
	double			c_real;
	double			c_irat;
	// ^^ the above salculates the equivalent cords for each pixel
	// the vv whould be used to compare the against the fractol set
	// z_2* is just the square of z_* , faster than using square()
	double			z_real;
	double			z_irat;
	double			z_2real;
	double			z_2irat;
}				t_fractal_data;

typedef struct	s_color
{
	char			red;
	char			green;
	char			blue;
	int				depth_mult;
}				t_color;

typedef struct	s_fractol
{
	t_minilibx		mlx;
	t_mlx_image		img;
	t_fractal_data	frac;
	t_color			color;
	int				fractol_opt;
}				t_fractol;

/*
**
*/
void		ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord);
void				draw_fractol(t_fractol *f);

typedef int		t_fractol_loops(t_fractol *f, int x);
extern t_fractol_loops	*g_fractol_loops[];

int		mandlebrot(t_fractol *f, int x);
int		how_did_you_get_here(t_fractol *f, int x);
#endif
