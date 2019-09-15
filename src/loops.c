/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:49:44 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/14 17:43:58 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		how_did_you_get_here(t_fractol *f, int x)
{
	(void)f;
	(void)x;
	ft_dprintf(2, "out of jumptable index lucky meeee!");
	exit(2);
}

int		mandlebrot(t_fractol *f, int x)
{
	int	boole;

	f->frac.c_real = f->frac.zoom *(f->frac.min_real + (x * f->frac.re_factor));
	f->frac.z_real = f->frac.zoom * f->frac.c_real;
	f->frac.z_irat = f->frac.c_irat;
	boole = 1;
	f->frac.current_iteration = 0;
	while (f->frac.current_iteration < f->frac.iterations)
	{
		f->frac.z_2real = f->frac.z_real * f->frac.z_real;
		f->frac.z_2irat = f->frac.z_irat * f->frac.z_irat;
		if ((f->frac.z_2real + f->frac.z_2irat) > 4)
		{
			boole = 0;
			break ;
		}
		f->frac.z_irat = 2 * f->frac.z_real * f->frac.z_irat + f->frac.c_irat;
		f->frac.z_real = f->frac.z_2real - f->frac.z_2irat + f->frac.c_real;
		f->frac.current_iteration++;
	}
	return (boole);
}

int		julia(t_fractol *f, int x)
{
	int	boole;
	(void)x;

	f->frac.c_real = f->frac.zoom *(f->frac.min_real + (x * f->frac.re_factor));
	f->frac.z_real = f->frac.zoom * f->frac.c_real;
	f->frac.z_irat = f->frac.c_irat;
	boole = 1;
	f->frac.current_iteration = 0;
	while (f->frac.current_iteration < f->frac.iterations)
	{
		f->frac.z_2real = f->frac.z_real * f->frac.z_real;
		f->frac.z_2irat = f->frac.z_irat * f->frac.z_irat;
		if ((f->frac.z_2real + f->frac.z_2irat) > 4)
		{
			boole = 0;
			break ;
		}
		f->frac.z_irat = 2 * f->frac.z_real * f->frac.z_irat + f->frac.c_irat;
		f->frac.z_real = f->frac.z_2real - f->frac.z_2irat + f->frac.c_real;
		f->frac.current_iteration++;
	}
	return (boole);
}
