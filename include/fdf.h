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
# include <errno.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct			s_coord
{
	double				x;
	double				y;
	double				z;
	double				z_tmp;
}						t_coord;

typedef struct			s_map
{
	int					*i_tab;
	struct s_map		*next;
}						t_map;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
	int					start;
	int					current;
	int					end;
}						t_color;

typedef struct			s_ray
{
	int					xi;
	int					xf;
	int					yi;
	int					yf;
}						t_ray;

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
	double				zoom;
	int					h_moove;
	int					v_moove;
	double				relief;
	double				z_angle;
	double				y_angle;
	double				x_angle;
	t_map				*map;
	t_color				color;
	double				z;
	double				z_bis;
	char				*av;
	t_ray				point;
}						t_file;

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

int						read_map(int fd, char *line, t_map map);
int						deal_key(int key, t_file *file);
int						mouse_press(int key, int x, int y, t_file *file);
int						split_map(int fd, t_map **map, t_file *file);
int						store_coord(t_map *map, t_file *file);
void					bresenham(t_file *file);
void					color_pixel(t_file *file, int x, int y);
void					display(t_file *file);
void					algo(t_file *file);
void					algo_x(t_file *file);
void					algo_y(t_file *file);
void					event_fdf(t_file *file);
int						get_color(t_file *file, t_bresenham brese,
						int start, int end);
void					hud_border(t_file *file);
void					bottom_fdf(t_file *file);
void					hud_key(t_file *file);
int						count_line(char **tab);
int						check_line(char **tab, int *count);
void					free_tab(char ***tab);
void					free_file(t_file *file, t_map *map, char **tab,
						char *line);
void					event_fdf_iso(t_file *file);
void					color(t_file *file);

#endif
