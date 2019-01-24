/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 11:54:15 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 13:43:00 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_file *file)
{
	t_file  *tmp;

	tmp = (t_file*)file;
	if (key == 53)
		exit(EXIT_SUCCESS);
    if (key == 4)
    {
        mlx_destroy();
        file->zoom = file->zoom * 2;
    }
    if (key == 5)
        file->zoom = file->zoom / 2;
	return(0);
}

void        display(t_file *file)
{
    file->zoom = 50;
    file->mlx_ptr = mlx_init();
    file->win_ptr = mlx_new_window(file->mlx_ptr, 1920, 1080, "fdf");
    mlx_key_hook(file->win_ptr, deal_key, file);
    algo(file);
    mlx_loop(file->mlx_ptr);
    /*file->ptr_img = mlx_new_image(file->mlx_ptr, 1400, 1100);
    file->my_str_img = mlx_get_data_addr(file->ptr_img, file->bpp, file->s_l,
                 file->endian);
    allume_pixel(file->my_str_img,);
    mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->ptr_img, 700, 550);
    */
}

