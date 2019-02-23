/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_fdf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/24 19:21:52 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 16:43:53 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		color(t_file *file)
{
	file->color.red = 0;
	file->color.green = 0;
	file->color.blue = 0;
	file->color.start = 0xFFFFFF;
	file->color.end = 0x3264A0;
}

void		event_fdf(t_file *file)
{
	file->zoom = 40;
	file->h_moove = WIDTH / 2;
	file->v_moove = HEIGHT / 2;
	file->relief = 0.8;
	file->z_angle = 0;
	file->y_angle = 0;
	file->x_angle = 0;
}

void		event_fdf_iso(t_file *file)
{
	file->zoom = 50;
	file->h_moove = WIDTH / 2;
	file->v_moove = HEIGHT / 2;
	file->relief = -0.08;
	file->z_angle = 0.8;
	file->y_angle = 0;
	file->x_angle = 1.1;
}
