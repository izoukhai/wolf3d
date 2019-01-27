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

void		move_player(t_env *env, const int dir)
{
	if (dir == 1)
	{
		if (env->map.coord[(int)(env->player.pos.y)][(int)(env->player.pos.x +
			env->player.dir.x * env->speed)].value == 0)
			env->player.pos.x += env->player.dir.x * env->speed;
		if (env->map.coord[(int)(env->player.pos.y + env->player.dir.y *
			env->speed)][(int)(env->player.pos.x)].value == 0)
			env->player.pos.y += env->player.dir.y * env->speed;
	}
	if (dir == -1)
	{
		if (env->map.coord[(int)(env->player.pos.y)][(int)(env->player.pos.x
			- env->player.dir.x * env->speed)].value == 0)
			env->player.pos.x -= env->player.dir.x * env->speed;
		if (env->map.coord[(int)(env->player.pos.y - env->player.dir.y
			* env->speed)][(int)(env->player.pos.x)].value == 0)
			env->player.pos.y -= env->player.dir.y * env->speed;
	}
}

void		move_cam(t_env *env, const int dir)
{
	double tmp;
	double tmp2;

	tmp = env->player.dir.x;
	tmp2 = env->plane.x;
	if (dir == 3)
	{
		env->player.dir.x = env->player.dir.x * cos(-0.05) -
			env->player.dir.y * sin(-0.05);
		env->player.dir.y = tmp * sin(-0.05) + env->player.dir.y * cos(-0.05);
		env->plane.x = env->plane.x * cos(-0.05) - env->plane.y * sin(-0.05);
		env->plane.y = tmp2 * sin(-0.05) + env->plane.y * cos(-0.05);
	}
	if (dir == 1)
	{
		env->player.dir.x = env->player.dir.x * cos(0.05) -
			env->player.dir.y * sin(0.05);
		env->player.dir.y = tmp * sin(0.05) + env->player.dir.y * cos(0.05);
		tmp2 = env->plane.x;
		env->plane.x = env->plane.x * cos(0.05) - env->plane.y * sin(0.05);
		env->plane.y = tmp2 * sin(0.05) + env->plane.y * cos(0.05);
	}
}

int			on_press(int key, t_env *env)
{
	if (key == kVK_UpArrow)
		env->up = 1;
	if (key == kVK_DownArrow)
		env->down = 1;
	if (key == kVK_RightArrow)
		env->right = 1;
	if (key == kVK_LeftArrow)
		env->left = 1;
	if (key == 257)
		env->speed = 0.15;
	if (key == kVK_Escape)
		die(env, "program exit.", 1);
	return (1);
}

int			on_release(int key, t_env *env)
{
	if (key == kVK_UpArrow)
		env->up = 0;
	if (key == kVK_DownArrow)
		env->down = 0;
	if (key == kVK_RightArrow)
		env->right = 0;
	if (key == kVK_LeftArrow)
		env->left = 0;
	if (key == 257)
		env->speed = 0.08;
	return (1);
}

int			handle_move(t_env *env)
{
	if (env->right)
		move_cam(env, 3);
	if (env->left)
		move_cam(env, 1);
	if (env->up)
		move_player(env, 1);
	if (env->down)
		move_player(env, -1);
	clear(env);
	ray_cast(env);
	return (1);
}
