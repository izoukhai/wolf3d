#include "../wolf3d.h"

static inline void	set_line(point_t *step, point_t *src, point_t *dst)
{
	(*step).x = (*dst).x - (*src).x;
	(*step).y = (*dst).y - (*src).y;
}

static inline void	set_point(point_t *pos, point_t src, int i, point_t step)
{
	(*pos).x = src.x + i * step.x;
	(*pos).y = src.y + i * step.y;
}

void				put_line(env_t *env, point_t src, point_t dst, int color)
{
	point_t			step;
	int				n;
	int				i;
	point_t			pos;

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