/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_fdf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 13:42:38 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 13:42:55 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			algo_x(t_file *file)
{
	int			i;
	int			j;

	i = 0;
	while (i < file->height - 1)
	{
		j = 0;
		while (j < file->width)
		{
			file->point.xi = file->xyz_tab[i][j].x * file->zoom +
			file->h_moove;
			file->point.yi = file->xyz_tab[i][j].y * file->zoom +
			file->v_moove - file->xyz_tab[i][j].z;
			file->point.xf = file->xyz_tab[i + 1][j].x * file->zoom +
			file->h_moove;
			file->point.yf = file->xyz_tab[i + 1][j].y * file->zoom +
			file->v_moove - file->xyz_tab[i + 1][j].z;
			file->z = file->xyz_tab[i][j].z_tmp;
			file->z_bis = file->xyz_tab[i + 1][j].z_tmp;
			bresenham(file);
			j++;
		}
		i++;
	}
}

void			algo_y(t_file *file)
{
	int			i;
	int			j;

	i = 0;
	while (i < file->height)
	{
		j = 0;
		while (j < file->width - 1)
		{
			file->point.xi = file->xyz_tab[i][j].x * file->zoom +
			file->h_moove;
			file->point.yi = file->xyz_tab[i][j].y * file->zoom +
			file->v_moove - file->xyz_tab[i][j].z;
			file->point.xf = file->xyz_tab[i][j + 1].x * file->zoom +
			file->h_moove;
			file->point.yf = file->xyz_tab[i][j + 1].y * file->zoom +
			file->v_moove - file->xyz_tab[i][j + 1].z;
			file->z = file->xyz_tab[i][j].z_tmp;
			file->z_bis = file->xyz_tab[i][j + 1].z_tmp;
			bresenham(file);
			j++;
		}
		i++;
	}
}

void			algo(t_file *file)
{
	algo_x(file);
	algo_y(file);
}
