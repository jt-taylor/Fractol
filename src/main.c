/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:09:53 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/09 14:54:51 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
** The constraints are as follows:
** • Your software should offer at least 3 different types of fractals, including the Julia
** set and the Mandelbrot set. The third fractal (and the optional additional ones)
** can be whatever you want.
** • It must be possible to make the parameter of the Julia set vary only with the mouse
** (without clicking). For the other types of fractal, the decision is yours.
** • The mouse wheel zooms in and out, almost infinitely (within the limits of the
** computer). This is the very principle of fractals.
** • You must use at least a few colors to show the depth of each fractal. It’s even better
** if you hack away on psychedelic effects.
** • A parameter is passed on the command line to define what type of fractal will be
** viewed. If no parameter is provided, or if the parameter is invalid, the program
** displays a list of available parameters and exits properly.
*/

/*
** init all of the mlx pointers
*/
static void		fractol_init_mlx(t_fractol *fractol, char *window_name)
{
	fractol->mlx.mlx_ptr = mlx_init();
	fractol->mlx.window_ptr = mlx_new_window(fractol->mlx.mlx_ptr, WINDOW_SIZE,
			window_name);
}

int		main()
{
	
}
