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

void        algo_x(t_file *file)
{
    t_ray       point;
    int         i;
    int         j;

    i = 0;
    while (i < file->height - 1)
    {
        j = 0;
        while (j < file->width)
        {
            ft_putnbr(file->zoom);
            point.xi = file->xyz_tab[i][j].x * file->zoom + 100;
            point.yi = file->xyz_tab[i][j].y * file->zoom + 100 - file->xyz_tab[i][j].z * 8;
            point.xf = file->xyz_tab[i + 1][j].x * file->zoom + 100;
            point.yf = file->xyz_tab[i + 1][j].y * file->zoom + 100 - file->xyz_tab[i + 1][j].z * 8;
            bresenham(point, file);
            j++;
        }
        i++;
    }
}

void        algo_y(t_file *file)
{
    t_ray       point;
    int         i;
    int         j;

    i = 0;
    while  (i < file->height)
    {
        j = 0;
        while (j < file->width - 1)
        {
            ft_putnbr(file->zoom);
            point.xi = file->xyz_tab[i][j].x * file->zoom + 100;
            point.yi = file->xyz_tab[i][j].y * file->zoom + 100 - file->xyz_tab[i][j].z * 8;
            point.xf = file->xyz_tab[i][j + 1].x * file->zoom + 100;
            point.yf = file->xyz_tab[i][j + 1].y * file->zoom + 100 - file->xyz_tab[i][j + 1].z * 8;
            bresenham(point, file);
            j++;
        }
        i++;
    }
}

void        algo(t_file *file)
{
    algo_x(file);
    algo_y(file);
}