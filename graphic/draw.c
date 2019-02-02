/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 04:47:27 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 04:47:29 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void				put_pixel(t_env *env, double x, double y, int color)
{
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
		env->image.buf[((int)y * WIN_W + (int)x)] = color;
	
}

void				put_pixel_tex(t_env *env, double x, double y, t_image texture)
{
	env->tex_y = ((y - WIN_H * 0.5f + env->ray_height * 0.5f) *
	texture.height) / env->ray_height - 0.5;
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
		env->image.buf[((int)y * WIN_W + (int)x)] =
		texture.buf[texture.height *
		(int)env->tex_y + (int)env->tex_x];
}

void				draw_wall(t_env *env, int x)
{
	int tmp;

	tmp = -1;
	if (env->type == 0)
		env->tex_x = env->player.raypos.y + env->wall_dist * env->player.raydir.y;
	else
		env->tex_x = env->player.raypos.x + env->wall_dist * env->player.raydir.x;
	env->tex_x -= floor(env->tex_x);
	env->tex_x *= (double)env->tex.walls[env->tex.id].height;
	while (++tmp <= env->start)
		put_pixel(env, x, tmp, env->map.color[2][env->color_select]);
	while (++env->start <= env->end)
	{
		if (env->b_color == -1)
			put_pixel_tex(env, x, (int)env->start, env->tex.walls[env->tex.id]);
		else
			put_pixel(env, x, (int)env->start,
			env->map.color[env->type][env->color_select]);
	}
	while (++env->start <= WIN_H)
		put_pixel(env, x, (int)env->start,
		env->map.color[2][env->color_select]);
}

void				clear(t_env *env)
{
	ft_bzero(env->image.buf, WIN_W * WIN_H * 4);
}
