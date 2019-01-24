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

int			store_coord(t_map **map, t_file *file)
{
	int			i;
	int			j;
	t_map		*tmp;

	i = 0;
	tmp = *map;
	if (!(file->xyz_tab = malloc(sizeof(t_coord) * file->height)))
		return (0);
	while (i < file->height)
	{
		if (!(file->xyz_tab[i] = malloc(sizeof(t_coord) * file->width)))
			return (0);
		i++;
	}
	i = 0;
	while (tmp)
	{
		j = 0;
		while (j <= file->width)
		{
			file->xyz_tab[i][j].x = j;
			file->xyz_tab[i][j].y = i;
			file->xyz_tab[i][j].z = tmp->i_tab[j];
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int			store_line(t_map **origin, t_file *file, char **tab)
{
	int			i;
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

int			split_map(int fd, t_map **map, t_file *file)
{
	char *line;
	char **tab;
	int n;

	n = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		store_line(map, file,  tab);
		if (line)
			free(line);
		free(tab);
		n++;
	}
	file->height = n;
	store_coord(map, file);
	return (1);
}