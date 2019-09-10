/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:10:50 by jtaylor           #+#    #+#             */
/*   Updated: 2019/09/09 14:54:35 by jtaylor          ###   ########.fr       */
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

typedef			s_minilibx
{
	void			*mlx_ptr;
	void			*window_ptr;
	void			*img_ptr;
	void			*img_data_ptr;
}				t_minilibx;

typedef			s_fractol
{
	t_minilibx		mlx;

}				t_fractol;

#endif
