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

void				connect_rect(t_env *env, t_index pos, int color)
{
	if (pos.j < env->map.size.j - 1)
		put_line(env, env->map.coord[pos.i][pos.j],
			env->map.coord[pos.i][pos.j + 1], color);
	if (pos.i < env->map.size.i - 1)
		put_line(env, env->map.coord[pos.i][pos.j],
			env->map.coord[pos.i + 1][pos.j], color);
}

void				draw_wall(t_env *env, int x)
{
	int tmp;

	tmp = -1;
	while (++tmp <= env->start)
		put_pixel(env, x, tmp, env->map.color[2][env->color_select]);
	while (++env->start <= env->end)
		put_pixel(env, x, (int)env->start, env->color);
	while (++env->start <= WIN_H)
		put_pixel(env, x, (int)env->start, env->map.color[2][env->color_select]);
}

void				clear(t_env *env)
{
	ft_bzero(env->image.buf, WIN_W * WIN_H * 4);
}
