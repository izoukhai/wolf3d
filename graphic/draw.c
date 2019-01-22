#include "../wolf3d.h"

void				put_pixel(env_t *env, double x, double y, int color)
{
	if ((x > 0 && x < WIN_W) && (y > 0 && y < WIN_H))
		env->image.buf[((int)y * WIN_W + (int)x)] = color;
}

void				connect_rect(env_t *env, index_t pos, int color)
{
	if (pos.j < env->map.size.j - 1)
		put_line(env, env->map.coord[pos.i][pos.j],
			env->map.coord[pos.i][pos.j + 1], color);
	if (pos.i < env->map.size.i - 1)
		put_line(env, env->map.coord[pos.i][pos.j],
			env->map.coord[pos.i + 1][pos.j], color);
}

void				draw_wall(env_t *env, int x)
{
	int tmp;

	tmp = env->start - 1;
	while (++tmp <= env->end)
		put_pixel(env, x, tmp, env->color);
}

void				clear(env_t *env)
{
	ft_bzero(env->image.buf, WIN_W * WIN_H * 4);
}

void				draw_floor(env_t *env)
{
	index_t			index;

	index.i = -1;
	while (++index.i < WIN_W)
	{
		index.j = WIN_H / 2;
		while (++index.j < WIN_H)
			put_pixel(env, index.j, index.j, RGB(100, 140, 70));
	}
}