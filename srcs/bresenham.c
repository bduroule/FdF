/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 14:29:38 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 16:21:52 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		color_converter(t_file *file, int hex)
{
	file->color.red = ((hex >> 16) & 0xFF);
	file->color.green = ((hex >> 8) & 0xFF);
	file->color.blue = ((hex) & 0xFF);
}

void			color_pixel(t_file *file, int x, int y)
{
	int i;

	i = (x * 4) + (y * (file->s_l));
	if (x > 0 && y > 0 && x < 1920 && y < 1080)
	{
		file->my_str_img[i] = (char)file->color.blue;
		file->my_str_img[i + 1] = (char)file->color.green;
		file->my_str_img[i + 2] = (char)file->color.red;
	}
}

static void		brese_x(t_bresenham brese, t_file *file)
{
	brese.cumul = brese.dx / 2;
	while (brese.i <= brese.dx)
	{
		brese.x += brese.xinc;
		brese.cumul += brese.dy;
		if (brese.cumul >= brese.dx)
		{
			brese.cumul -= brese.dx;
			brese.y += brese.yinc;
		}
		if (file->z == 0 && file->z_bis == 0)
			get_color(file, brese, 0xFFFFEB, 0xFFFFEB);
		else if (fabs(file->z) + fabs(file->z_bis) > 0 && fabs(file->z)
				< fabs(file->z_bis))
			get_color(file, brese, file->color.start, file->color.end);
		else if (fabs(file->z) > fabs(file->z_bis))
			get_color(file, brese, file->color.end, file->color.start);
		else if (fabs(file->z) == fabs(file->z_bis) && file->z != 0)
			color_converter(file, file->color.end);
		else
			color_converter(file, file->color.start);
		color_pixel(file, (double)brese.x, (double)brese.y);
		brese.i++;
	}
}

static void		brese_y(t_bresenham brese, t_file *file)
{
	brese.cumul = brese.dy / 2;
	while (brese.i <= brese.dy)
	{
		brese.y += brese.yinc;
		brese.cumul += brese.dx;
		if (brese.cumul >= brese.dy)
		{
			brese.cumul -= brese.dy;
			brese.x += brese.xinc;
		}
		if (file->z == 0 && file->z_bis == 0)
			get_color(file, brese, 0xFFFFFF, 0xFFFFFF);
		else if (fabs(file->z) + fabs(file->z_bis) > 0 && fabs(file->z) <
				fabs(file->z_bis))
			get_color(file, brese, file->color.start, file->color.end);
		else if (fabs(file->z) > fabs(file->z_bis))
			get_color(file, brese, file->color.end, file->color.start);
		else if (fabs(file->z) == fabs(file->z_bis) && file->z != 0)
			color_converter(file, file->color.end);
		else
			color_converter(file, file->color.start);
		color_pixel(file, (double)brese.x, (double)brese.y);
		brese.i++;
	}
}

void			bresenham(t_file *file)
{
	t_bresenham brese;

	brese.i = 1;
	brese.x = file->point.xi;
	brese.y = file->point.yi;
	brese.dx = file->point.xf - file->point.xi;
	brese.dy = file->point.yf - file->point.yi;
	brese.xinc = (brese.dx > 0) ? 1 : -1;
	brese.yinc = (brese.dy > 0) ? 1 : -1;
	brese.dx = fabs(brese.dx);
	brese.dy = fabs(brese.dy);
	color_pixel(file, brese.x, brese.y);
	if (brese.dx > brese.dy)
		brese_x(brese, file);
	else
		brese_y(brese, file);
}
