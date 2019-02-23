/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_fdf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 14:06:50 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:19:28 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void			rotate(t_file *file, t_map *tmp, int i, int j)
{
	file->xyz_tab[i][j].x = (j - file->width / 2) * cos(file->z_angle)
	- (i - file->height / 2) * sin(file->z_angle);
	file->xyz_tab[i][j].y = (j - file->width / 2) * sin(file->z_angle)
	+ (i - file->height / 2) * cos(file->z_angle);
	file->xyz_tab[i][j].z = tmp->i_tab[j] * file->relief;
	file->xyz_tab[i][j].z_tmp = file->xyz_tab[i][j].z;
	file->xyz_tab[i][j].y = file->xyz_tab[i][j].y * cos(file->x_angle) +
	tmp->i_tab[j] * file->relief * sin(file->x_angle);
	file->xyz_tab[i][j].z = tmp->i_tab[j] * file->relief * cos(file->x_angle) -
	file->xyz_tab[i][j].y * sin(file->x_angle);
	file->xyz_tab[i][j].x = file->xyz_tab[i][j].x * cos(file->y_angle) +
	tmp->i_tab[j] * file->relief * sin(file->y_angle);
	file->xyz_tab[i][j].z = -file->xyz_tab[i][j].x * sin(file->y_angle) +
	tmp->i_tab[j] * file->relief * cos(file->y_angle);
}

int					store_coord(t_map *map, t_file *file)
{
	int			i;
	int			j;
	t_map		*tmp;

	i = 0;
	tmp = map;
	if (!(file->xyz_tab = malloc(sizeof(t_coord) * file->height)))
		return (0);
	while (i < file->height)
	{
		if (!(file->xyz_tab[i] = malloc(sizeof(t_coord) * file->width)))
			return (0);
		i++;
	}
	i = 0;
	while (i < file->height)
	{
		j = -1;
		while (++j < file->width)
			rotate(file, tmp, i, j);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

static int			store_line(t_map **origin, t_file *file, char **tab, int i)
{
	t_map		*tmp;
	t_map		*new;

	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (0);
	i = 0;
	while (tab[i])
		i++;
	file->width = i;
	if (!(new->i_tab = (int *)malloc(sizeof(int) * i)))
		return (0);
	i = -1;
	while (tab[++i])
		new->i_tab[i] = ft_atoi(tab[i]);
	new->next = NULL;
	if (*origin == NULL)
		*origin = new;
	else
	{
		tmp = *origin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void				free_tab(char ***tab)
{
	char	**str;
	int		i;

	i = 0;
	str = *tab;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*tab)[i];
	}
	ft_memdel((void **)tab);
}

int					split_map(int fd, t_map **map, t_file *file)
{
	char	*line;
	char	**tab;
	int		n;
	int		i;
	int		count;

	n = 0;
	i = 0;
	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tab = ft_strsplit(line, ' ')))
			return (0);
		if (check_line(tab, &count) == 0)
			free_file(file, *map, tab, line);
		if (!(store_line(map, file, tab, i)))
			return (0);
		if (line)
			free(line);
		free_tab(&tab);
		n++;
	}
	file->height = n;
	store_coord(*map, file);
	return (1);
}
