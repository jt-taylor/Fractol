/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:09:53 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/13 15:16:10 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** used with strcmp to select which fractol to 'run'
** last string must be "" --> stops the strcmp loop from comparing
**		data from outside the bounds of the array
*/

char		*g_fractol_list[30] =
{
	"test",
	"test1",
	"test2",
	"test-me",
	""
};

/*
** make a usage message 
*/

static inline void	fractol_usage_message(void)
{
	int		i;

	i = 0;
	ft_printf("Usage:\n./fractol [fractol name]\n\tAvailable fractal\'s\n");
	while (g_fractol_list[i][0] != '\0')
		ft_printf("\t- %s\n", g_fractol_list[i++]);
	write(1, "\n", 1);
	exit(0);
}

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
**
**
**
** Things to look at : follow links at your discretion I don't own or maintain
** 	any of them ;
** http://warp.povusers.org/Mandelbrot/
*/

/*
** init all of the mlx pointers
*/

static void		fractol_init_mlx(t_fractol *fractol, char *window_name)
{
	fractol->mlx.mlx_ptr = mlx_init();
	fractol->mlx.window_ptr = mlx_new_window(fractol->mlx.mlx_ptr, WIDTH, HEIGHT,
			window_name);
	fractol->img.image_ptr = mlx_new_image(fractol->mlx.mlx_ptr, WIDTH, HEIGHT);
	fractol->img.data_start = mlx_get_data_addr(fractol->img.image_ptr,
			&fractol->img.bpp, &fractol->img.size_line, &fractol->img.endian);
}

static inline int	fractol_select(char *name)
{
	int		i;

	i = -1;
	while (name[++i])
		name[i] = ft_tolower(name[i]);
	i = 0;
	while (g_fractol_list[i][0] != '\0')
	{
		if (ft_strequ(g_fractol_list[i], name))
			return (i);
		i++;
	}
	if (g_fractol_list[i][0] == '\0')
	{
		ft_dprintf(2, "fractol \'%s\' not found in fractol list\n\n", name);
		fractol_usage_message();
		exit(1);
	}
	else
	{
		ft_putstr_fd("if you changed the fractol_list array make sure to\
				have the last string be "" --> how it checks end of arr", 2);
		exit(-1);
	}
}

int		main(int ac, char **argv)
{
	t_fractol	*fractol;

	if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
		//exit malloc error
		;
	if (ac == 2)
	{
		fractol->fractol_opt = fractol_select(argv[1]);
		//testing
		// take the color option romt
		ft_printf("fractol select option == %d\n", fractol->fractol_opt);
	}
	else
		fractol_usage_message();
	fractol_init_mlx(fractol, argv[1]);
	draw_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx.mlx_ptr, fractol->mlx.window_ptr, fractol->img.image_ptr, 0, 0);
	mlx_loop(fractol->mlx.mlx_ptr);
	return (0);
}
