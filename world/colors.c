/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 06:54:16 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 06:54:18 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void		init_colors(t_env *env)
{
	env->map.color[2][0] = RGB(10, 5, 40);
	env->map.color[2][1] = RGB(5, 5, 60);
	env->map.color[2][2] = RGB(60, 5, 5);
	env->map.color[2][3] = RGB(5, 50, 5);
	env->map.color[2][4] = RGB(140, 140, 140);
	env->map.color[1][0] = RGB(70, 20, 100);
	env->map.color[1][1] = RGB(10, 10, 90);
	env->map.color[1][2] = RGB(90, 10, 5);
	env->map.color[1][3] = RGB(5, 90, 5);
	env->map.color[1][4] = RGB(170, 170, 170);
	env->map.color[0][0] = RGB(70, 20, 110);
	env->map.color[0][1] = RGB(10, 10, 100);
	env->map.color[0][2] = RGB(100, 10, 10);
	env->map.color[0][3] = RGB(5, 100, 5);
	env->map.color[0][4] = RGB(180, 180, 180);
}

void		set_colors(t_env *env)
{
	if (env->b_color == 1)
		env->color = env->map.color[env->type][env->color_select];
	else
	{
		if (env->type == 0 && env->player.raydir.x > 0)
			env->color = RGB(170, 0, 0);
		if (env->type == 0 && env->player.raydir.x < 0)
			env->color = RGB(0, 200, 40);
		if (env->type == 1 && env->player.raydir.y > 0)
			env->color = RGB(0, 0, 200);
		if (env->type == 1 && env->player.raydir.y < 0)
			env->color = RGB(170, 100, 0);
	}
}
