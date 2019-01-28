/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 22:45:43 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:45:43 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <math.h>
# include "graphic/minilib/mlx.h"
# include "libft/includes/get_next_line.h"
# include "keys.h"
# define WIN_W 1700
# define WIN_H 1200
# define RGB(r,g,b) (r << 16) + (g << 8) + (b)

typedef struct	s_point
{
	double		x;
	double		y;
	uint32_t	value;
}				t_point;

typedef struct	s_index
{
	int			i;
	int			j;
}				t_index;

typedef struct	s_map
{
	t_point		**coord;
	t_index		size;
	int			color[3][5];
}				t_map;

typedef struct	s_player
{
	t_point		pos;
	t_point		dir;
	t_point		raypos;
	t_point		raydir;
}				t_player;

typedef struct	s_image
{
	void		*ptr;
	int			*buf;
	int			szl;
	int			bpp;
	int			endian;
}				t_image;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			malloced;
	t_image		image;
	t_map		map;
	int			map_x;
	int			map_y;
	t_point		delta_dist;
	t_point		step;
	t_point		side_dist;
	int			type;
	int			ray_hit;
	double		wall_dist;
	double		ray_height;
	int			start;
	int			end;
	int			color;
	uint16_t	color_select;
	t_player	player;
	t_point		plane;
	int			right;
	int			left;
	int			up;
	int			down;
	double		cam;
	char		*file;
	int			fd;
	double		speed;
	int			b_color;
}				t_env;

void			init(t_env *env, char *map);
void			init_ray(t_env *env, int x);

void			put_pixel(t_env *env, double x, double y, int color);
void			put_line(t_env *env, t_point src, t_point dst, int color);
void			clear(t_env *env);
void			connect_rect(t_env *env, t_index pos, int color);
void			draw_wall(t_env *env, int x);
void			ray_cast(t_env *env);

void			init_map(t_env *env);
void			check_map(t_env *env);

void			die(t_env *env, char *msg, const int b_free);
t_point			t_indexo_pos(t_index index);
void			set_index(t_index *index, int i, int j);
int				ft_strichr(char *str, char c);
t_point			new_point(double x, double y);

void			s_open(t_env *env, char *file);

int				on_press(int key, t_env *env);
int				on_release(int key, t_env *env);
int				handle_move(t_env *env);
void			move_player(t_env *env, const int dir);
void			move_cam(t_env *env, const int dir);

void			init_colors(t_env *env);
void			set_colors(t_env *env);

#endif
