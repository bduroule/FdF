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

int				deal_key_t(int key, t_file *file)
{
	if (key == 14)
		file->z_angle += 0.1;
	if (key == 0)
		file->y_angle -= 0.1;
	if (key == 2)
		file->y_angle += 0.1;
	if (key == 13)
		file->x_angle -= 0.1;
	if (key == 1)
		file->x_angle += 0.1;
	if (key == 34)
		event_fdf_iso(file);
	if (key == 35)
		event_fdf(file);
	return (0);
}

int				deal_key(int key, t_file *file)
{
	t_file *tmp;

	tmp = file;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 124)
		file->h_moove += 10;
	if (key == 123)
		file->h_moove -= 10;
	if (key == 125)
		file->v_moove += 10;
	if (key == 126)
		file->v_moove -= 10;
	if (key == 78)
		file->relief -= 0.01;
	if (key == 69)
		file->relief += 0.01;
	if (key == 12)
		file->z_angle -= 0.1;
	deal_key_t(key, file);
	display(file);
	return (0);
}

int				mouse_press(int key, int x, int y, t_file *file)
{
	(void)x;
	(void)y;
	if (key == 4)
		file->zoom += 0.5;
	if (key == 5)
		file->zoom -= 0.5;
	if (key == 1)
		file->color.start = rand();
	if (key == 2)
		file->color.end = rand();
	display(file);
	return (0);
}

void			free_cord(t_file *file)
{
	int i;

	i = 0;
	while (i < file->height)
		free(file->xyz_tab[i++]);
	free(file->xyz_tab);
}

void			display(t_file *file)
{
	file->ptr_img = mlx_new_image(file->mlx_ptr, WIDTH, HEIGHT);
	file->my_str_img = mlx_get_data_addr(file->ptr_img, &(file->bpp),
	&(file->s_l), &(file->endian));
	mlx_clear_window(file->mlx_ptr, file->win_ptr);
	free_cord(file);
	store_coord(file->map, file);
	algo(file);
	hud_border(file);
	bottom_fdf(file);
	mlx_put_image_to_window(file->mlx_ptr, file->win_ptr, file->ptr_img, 0, 0);
	hud_key(file);
	mlx_destroy_image(file->mlx_ptr, file->ptr_img);
}
