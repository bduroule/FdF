/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 16:50:31 by jadonvez     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 17:14:50 by jadonvez    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct			s_coord
{
	int					x;
	int					y;
	int					z;
}						t_coord;

typedef struct			s_file
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					height;
	int					width;
	void				*ptr_img;
	char				*my_str_img;
	int					bpp;
	int					s_l;
	int					endian;
	t_coord				**xyz_tab;
	int					zoom;
}						t_file;

typedef struct			s_map
{
	int					*i_tab;
	struct s_map		*next;
}						t_map;

typedef struct			s_bresenham
{
	double				dx;
	double				dy;
	double				i;
	double				xinc;
	double				yinc;
	double				cumul;
	double				x;
	double				y;
	double				c;
}						t_bresenham;

typedef struct			s_ray
{
	int					xi;
	int					xf;
	int					yi;
	int					yf;
}						t_ray;

int						read_map(int fd, char *line, t_map map);
int						store_line(t_map **origin, t_file *file, char **tab);
int						split_map(int fd, t_map **map, t_file *file);
int						store_coord(t_map **map, t_file *file);
void					bresenham(t_ray point, t_file *file);
void					brese_x(t_bresenham brese, t_file *file);
void					brese_y(t_bresenham brese, t_file *file);
void					allume_pixel(t_bresenham brese, t_file *file);
void					display(t_file *file);
void					algo(t_file *file);
void					algo_x(t_file *file);
void					algo_y(t_file *file);
void					zoom_fdf(t_file *file);

#endif
