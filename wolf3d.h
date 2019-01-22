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
# define WIN_W 1200
# define WIN_H 1200
# define RGB(r,g,b) (r << 16) + (g << 8) + (b)

typedef struct
{
	double  	x;
	double  	y;
	uint32_t	value;
}				point_t; 

typedef struct
{
	int			i;
	int			j;
}				index_t;

typedef struct
{
	point_t		**coord;
	index_t		size;
}				map_t;

typedef struct
{
	point_t		pos;
	point_t		dir;
	point_t		raypos;
	point_t		raydir;
}				player_t;

typedef struct
{
	void		*ptr;
	int			*buf;
	int			szl;
	int			bpp;
	int			endian;
}				image_t;

typedef struct
{
	void		*mlx;
	void		*win;
	image_t		image;
	map_t		map;
	int			map_x;
	int			map_y;
	point_t		delta_dist;
	point_t		step;
	point_t		side_dist;
	int			type;
	int			ray_hit;
	double			wall_dist;
	double		ray_height;
	int			start;
	int			end;
	int			color;
	player_t	player;
	point_t		plane;
	double		time;
	double		old_time;
	double		ms;
	double		rs;
	double		cam;
	char		*file;
	int			fd;
}				env_t;

void			init(env_t *env, char *map);
void			init_ray(env_t *env, int x);

void			put_pixel(env_t *env, double x, double y, int color);
void			put_line(env_t *env, point_t src, point_t dst, int color);
void			clear(env_t *env);
void			connect_rect(env_t *env, index_t pos, int color);
void			draw_wall(env_t *env, int x);
void			draw_floor(env_t *env);
void        	ray_cast(env_t *env);

void			init_map(env_t *env);
void			check_map(env_t *env);

void			die(char *msg);
point_t			index_to_pos(index_t index);
void			set_index(index_t *index, int i, int j);
int				ft_strichr(char *str, char c);
point_t			new_point(double x, double y);

void			s_open(env_t *env, char *file);

int				handle_keys(int key, env_t *env);
int				on_release(int key, env_t *env);
int				on_press(int key, env_t *env);
void			move_player(env_t *env, const int dir);
void			move_cam(env_t *env, const int dir);

#endif


