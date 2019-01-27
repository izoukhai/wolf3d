/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 00:02:03 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 00:02:03 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void		die(t_env *env, char *msg, const int b_free)
{
	t_index	index;

	index.i = -1;
	ft_putstr(msg);
	if (b_free && env->malloced)
	{
		while (++index.i < env->map.size.i)
			free(env->map.coord[index.i]);
		free(env->map.coord);
	}
	exit(1);
}

t_point		t_indexo_pos(t_index index)
{
	t_point res;

	res.x = index.j;
	res.y = index.i;
	return (res);
}

void		set_index(t_index *index, int i, int j)
{
	index->i = i;
	index->j = j;
}

int			ft_strichr(char *str, char c)
{
	int		i;
	int		res;

	res = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			res++;
	return (res);
}

t_point		new_point(double x, double y)
{
	t_point	res;

	res.x = x;
	res.y = y;
	return (res);
}
