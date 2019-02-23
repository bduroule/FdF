/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hud_fdf.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/05 15:10:42 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 16:45:18 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		hud_key(t_file *file)
{
	mlx_string_put(file->mlx_ptr, file->win_ptr, 1710, 1052, 0x000000,
			"Beduroul - Jadonvez");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 25, 1052, 0x000000, file->av);
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 40, 0xffffff,
			"Zoom       : Scroll");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 60, 0xffffff,
			"Relief     : + / -");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 80, 0xffffff,
			"Moves      : Arrows");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 100, 0xffffff,
			"Rotation x : W / S");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 120, 0xffffff,
			"Rotation y : A / D");
	mlx_string_put(file->mlx_ptr, file->win_ptr, 45, 140, 0xffffff,
			"Rotation z : Q / E");
}

void		bottom_fdf(t_file *file)
{
	int		i;

	i = 0;
	file->z = 1;
	while (i <= 35)
	{
		file->point.xi = 0;
		file->point.yi = 1045 + i;
		file->point.xf = 1920;
		file->point.yf = 1045 + i;
		bresenham(file);
		i++;
	}
}

void		hud_border(t_file *file)
{
	file->point.xi = 25;
	file->point.xf = 25;
	file->point.yi = 24;
	file->point.yf = 175;
	bresenham(file);
	file->point.xi = 250;
	file->point.xf = 250;
	file->point.yi = 175;
	file->point.yf = 24;
	bresenham(file);
	file->point.xi = 25;
	file->point.xf = 250;
	file->point.yi = 175;
	file->point.yf = 175;
	bresenham(file);
	file->point.xi = 250;
	file->point.xf = 25;
	file->point.yi = 24;
	file->point.yf = 24;
	bresenham(file);
}
