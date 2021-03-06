/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 23:30:55 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 23:30:56 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

static void	init_core(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "Wolf3D");
	env->image.ptr = mlx_new_image(env->mlx, WIN_W, WIN_H);
	env->image.buf = (int*)mlx_get_data_addr(env->image.ptr, &(env->image.bpp),
		&(env->image.szl), &(env->image.endian));
	env->tex_x = 0;
	env->tex_y = 0;
	env->tex.id = 0;
	set_textures(env);
}

void		init(t_env *env, char *map)
{
	env->file = map;
	env->player.pos.x = -1;
	env->player.pos.y = -1;
	env->player.dir.x = -1;
	env->player.dir.y = 0;
	env->cam = 0;
	env->plane.x = 0;
	env->plane.y = 0.66;
	env->malloced = 0;
	env->speed = 0.05;
	env->right = 0;
	env->up = 0;
	env->left = 0;
	env->down = 0;
	env->color_select = 0;
	env->b_color = -1;
	init_core(env);
	init_colors(env);
	init_map(env);
}
