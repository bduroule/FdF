/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bresenham.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/17 14:29:38 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 14:29:45 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void        brese_x(t_bresenham brese, t_file *file)
{
    //mlx_pixel_put(file->mlx_ptr, file->win_ptr, 100, 100, brese.c);
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
        mlx_pixel_put(file->mlx_ptr, file->win_ptr, brese.x, brese.y, brese.c);
        brese.i++;
    }
}

void        brese_y(t_bresenham brese, t_file *file)
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
        mlx_pixel_put(file->mlx_ptr, file->win_ptr, brese.x, brese.y, brese.c);
        brese.i++;
    }
    
}

void        bresenham(t_ray point, t_file *file)
{
    t_bresenham brese;
    brese.c = 0xFFFFFF;
    brese.i = 1;
    brese.x = point.xi;
    brese.y = point.yi;
    brese.dx = point.xf - point.xi;
    brese.dy = point.yf - point.yi;
    brese.xinc = (brese.dx > 0) ? 1 : -1;
    brese.yinc = (brese.dy > 0) ? 1 : -1;
    brese.dx = fabs(brese.dx);
    brese.dy = fabs(brese.dy);
    if (brese.dx > brese.dy)
        brese_x(brese, file);
    else
        brese_y(brese, file);
}