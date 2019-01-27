/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/27 04:47:40 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 04:47:42 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

static inline void	set_line(t_point *step, t_point *src, t_point *dst)
{
	(*step).x = (*dst).x - (*src).x;
	(*step).y = (*dst).y - (*src).y;
}

static inline void	set_point(t_point *pos, t_point src, int i, t_point step)
{
	(*pos).x = src.x + i * step.x;
	(*pos).y = src.y + i * step.y;
}

void				put_line(t_env *env, t_point src, t_point dst, int color)
{
	t_point			step;
	int				n;
	int				i;
	t_point			pos;

	i = -1;
	set_line(&step, &src, &dst);
	if (ABS(step.x) > ABS(step.y))
	{
		n = ABS(step.x);
		step.y /= ABS(step.x);
		step.x /= ABS(step.x);
	}
	else
	{
		n = ABS(step.y);
		step.x /= ABS(step.y);
		step.y /= ABS(step.y);
	}
	while (++i < n)
	{
		set_point(&pos, src, i, step);
		if ((pos.x >= 0 && pos.x <= WIN_W) && (pos.y >= 0 && pos.y <= WIN_H))
			put_pixel(env, pos.x, pos.y, color);
	}
}
