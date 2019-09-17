/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:10:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/16 17:05:01 by jtaylor          ###   ########.fr       */
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
# define WINDOW_SIZE 1000, 1000
# define WIDTH 500
# define HEIGHT 500

/*
** Structures
*/

typedef struct	s_mlx_image
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
	double			min_real;
	double			max_real;
	double			min_irat;
	double			max_irat;
	double			re_factor;
	double			ir_factor;
	double			c_real;
	double			c_irat;
	double			z_real;
	double			z_irat;
	double			z_2real;
	double			z_2irat;
	double			zoom;
	int				mouse_x;
	int				mouse_y;
	int				type;
	int				current_iteration;
	int				iterations;
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

void			ft_mlx_img_pixel_put(t_fractol *f, int x_cord, int y_cord);
void			draw_fractol(t_fractol *f);

typedef int		t_fractol_loops(t_fractol *f, int x);
extern t_fractol_loops	*g_fractol_loops[];

int				mandlebrot(t_fractol *f, int x);
int				how_did_you_get_here(t_fractol *f, int x);
void			init_fractol_options(t_fractol *f);
int				fractol_keypress(int keycode, t_fractol *f);
int				fractol_mousepress(int keycode, int x, int y, t_fractol *f);
int				julia(t_fractol *f, int x);
void			fractol_color_default(t_fractol *f);
int				wat_is_this_called(t_fractol *f, int x);
int				wat2(t_fractol *f, int x);
#endif
