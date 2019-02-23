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

int		out(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	error_file(int fd, char *av)
{
	errno = 0;
	read(fd, av, 0);
	if (errno != 0)
	{
		perror("error ");
		exit(0);
	}
}

void	fonction_call(t_file *file)
{
	display(file);
	mlx_hook(file->win_ptr, 4, 0, mouse_press, file);
	mlx_hook(file->win_ptr, 2, 0, deal_key, (void *)file);
	mlx_hook(file->win_ptr, 17, 0, out, file);
	mlx_loop(file->mlx_ptr);
}

int		main(int ac, char **av)
{
	int		fd;
	t_file	*file;

	if (ac != 2)
		return (write(1, "usage: ./fdf map\n", 17));
	file = malloc(sizeof(t_file));
	file->map = NULL;
	if (ft_strcchr(av[1], '/'))
		file->av = ft_strrchr(av[1], '/') + 1;
	else
		file->av = av[1];
	if ((fd = open(av[1], O_RDONLY)) < 1)
	{
		free(file);
		return (write(1, "file invalide\n", 14));
	}
	error_file(fd, av[1]);
	color(file);
	event_fdf(file);
	if (!(split_map(fd, &file->map, file)))
		return (write(1, "map error\n", 10));
	file->mlx_ptr = mlx_init();
	file->win_ptr = mlx_new_window(file->mlx_ptr, WIDTH, HEIGHT, "fdf");
	fonction_call(file);
	return (0);
}
