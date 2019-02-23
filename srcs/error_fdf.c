/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_fdf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 16:09:37 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 16:09:39 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_file(t_file *file, t_map *map, char **tab, char *line)
{
	(void)map;
	free(file);
	free(line);
	free_tab(&tab);
	write(1, "map error\n", 10);
	exit(0);
}

int		check_line(char **tab, int *count)
{
	if (*count == 0)
		*count = count_line(tab);
	if (count_line(tab) != *count)
		return (0);
	if (count == 0)
		return (0);
	return (1);
}

int		count_line(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
