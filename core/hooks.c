/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hooks.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 07:31:13 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 07:31:13 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void		move_player(env_t *env, const int dir)
{
	if (dir == 1)
	{
		if (env->map.coord[(int)(env->player.pos.y)][(int)(env->player.pos.x + env->player.dir.x * 0.2)].value == 0)
			env->player.pos.x += env->player.dir.x * 0.2;
		if (env->map.coord[(int)(env->player.pos.y + env->player.dir.y * 0.2)][(int)(env->player.pos.x)].value == 0)
			env->player.pos.y += env->player.dir.y * 0.2;
	}
	if (dir == -1)
	{
		if (env->map.coord[(int)(env->player.pos.y)][(int)(env->player.pos.x
			- env->player.dir.x * 0.2)].value == 0)
				env->player.pos.x -= env->player.dir.x * 0.2;
		if (env->map.coord[(int)(env->player.pos.y - env->player.dir.y * 0.2)]
			[(int)(env->player.pos.x)].value == 0)
				env->player.pos.y -= env->player.dir.y * 0.2;
	}
}

void		move_cam(env_t *env, const int dir)
{
	if (dir == 3)
	{
		double tmp = env->player.dir.x;
		env->player.dir.x = env->player.dir.x * cos(-env->rs) -
			env->player.dir.y * sin(-env->rs);
		env->player.dir.y = tmp * sin(-env->rs) + env->player.dir.y * cos(-env->rs);
		double tmp2 = env->plane.x;
		env->plane.x = env->plane.x * cos(-env->rs) - env->plane.y * sin(-env->rs);
		env->plane.y = tmp2 * sin(-env->rs) + env->plane.y * cos(-env->rs);
	}
	if (dir == 1)
	{
		double tmp = env->player.dir.x;
		env->player.dir.x = env->player.dir.x * cos(env->rs) -
			env->player.dir.y * sin(env->rs);
		env->player.dir.y = tmp * sin(env->rs) + env->player.dir.y * cos(env->rs);
		double tmp2 = env->plane.x;
		env->plane.x = env->plane.x * cos(-env->rs) - env->plane.y * sin(env->rs);
		env->plane.y = tmp2 * sin(env->rs) + env->plane.y * cos(env->rs);
	}
}

int			on_press(int key, env_t *env)
{
	if (key == kVK_UpArrow)
		move_player(env, 1);
	if (key == kVK_DownArrow)
		move_player(env, -1);
	if (key == kVK_LeftArrow)
		move_cam(env, 1);
	if (key == kVK_RightArrow)
		move_cam(env, 3);
	clear(env);
	ray_cast(env);
	return (0);
}

int			on_release(int key, env_t *env)
{
	if (key == kVK_UpArrow)
		move_player(env, 1);
	if (key == kVK_DownArrow)
		move_player(env, -1);
	if (key == kVK_LeftArrow)
		move_cam(env, 1);
	if (key == kVK_RightArrow)
		move_cam(env, 3);
	clear(env);
	ray_cast(env);
	return (0);
}

int			handle_keys(int key, env_t *env)
{
	on_press(key, env);
	on_release(key, env);
}