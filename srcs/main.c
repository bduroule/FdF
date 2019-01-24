/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 15:54:42 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:14:55 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "fdf.h"

int		main(int ac, char **av)
{
	//int i;
	int		fd;
	t_map	*map;
	t_file	*file;

	map = NULL;
	file = malloc(sizeof(t_file));
	//if (!(map = (t_map*)malloc(sizeof(t_map))))
	//return (0);
	if (ac != 2)
		return (write(1, "usage: ./fdf map\n", 17));
	fd = open(av[1], O_RDONLY);
	/*
	t_file *file;
	file = malloc(sizeof(t_file));
	file->mlx_ptr = mlx_init();
	file->win_ptr = mlx_new_window(file->mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(file->mlx_ptr, file->win_ptr, 250, 250, 250);
	mlx_key_hook(file->win_ptr, deal_key, (void *) file);
	mlx_loop(file->mlx_ptr);*/
	split_map(fd, &map, file);
	display(file);
	/*while (map)
	{
		i = 0;
		while (i < 19)
		{
			ft_putnbr(map->i_tab[i]);
			i++;
		}
		write(1, "\n", 1);
		map = map->next;
	}*/
	return (0);
}
