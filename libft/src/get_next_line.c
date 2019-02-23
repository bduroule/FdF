/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:09:47 by beduroul     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 18:44:53 by beduroul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static int				ft_error(int fd, char *str, char **line)
{
	char *buff;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buff = ft_strnew(BUFF_SIZE + 1))
		|| read(fd, buff, 0) == -1)
		return (-1);
	if (!str)
	{
		if (!(str = ft_strnew(0)))
			return (-1);
	}
	ft_strdel(&buff);
	return (0);
}

static t_liste			*ft_fd_read(int fd, t_liste **list)
{
	t_liste *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_liste *)malloc(sizeof(t_liste))))
		return (NULL);
	tmp->string = ft_strnew(0);
	tmp->fd = fd;
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static char				*ft_read(int fd, char *str)
{
	char	*tmp;
	char	*buff;
	int		n;

	buff = ft_strnew(BUFF_SIZE + 1);
	n = 1;
	while (n && (!(ft_strchr(str, '\n'))))
	{
		n = read(fd, buff, BUFF_SIZE);
		buff[n] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buff)))
			return (NULL);
		ft_strdel(&tmp);
	}
	if (!n && ft_strlen(str) > 0)
	{
		tmp = str;
		str = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (str);
}

static char				*ft_search_line(char **str)
{
	char *line;
	char *new;
	char *tmp;

	new = ft_strchr(*str, '\n');
	if (new)
	{
		if (!(line = ft_strsub(*str, 0, new - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(new + 1)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else if (!(line = ft_strdup(*str)))
		return (NULL);
	return (line);
}

int						get_next_line(const int fd, char **line)
{
	static t_liste	*str;
	t_liste			*tab;

	tab = ft_fd_read(fd, &str);
	if (ft_error(fd, tab->string, line) || (tab->string == NULL &&
	!(tab->string = ft_strnew(0))))
		return (-1);
	if (!(tab->string = ft_read(fd, tab->string)))
		return (-1);
	if (*tab->string)
	{
		if (!(*line = ft_search_line(&tab->string)))
			return (-1);
		return (1);
	}
	ft_memdel((void **)&tab->string);
	return (0);
}
