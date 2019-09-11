/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:10:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/10 17:09:46 by jtaylor          ###   ########.fr       */
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

typedef struct	s_fractol
{
	t_minilibx		mlx;
	t_mlx_image		img;
	int				fractol_opt;
}				t_fractol;

#endif
