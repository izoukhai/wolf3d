/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 18:42:31 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/21 18:42:31 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void		s_open(t_env *env, char *file)
{
	if ((env->fd = open(file, O_RDONLY)) == -1)
		die(env, "can't open file.", 0);
}

static int	check_length(int nb)
{
	int		res;

	res = 1;
	while (nb / 10)
		res++;
	return (res);
}

void		check_map(t_env *env)
{
	t_index	index;
	int		c;

	c = 0;
	index.i = -1;
	while (++index.i < env->map.size.i)
	{
		index.j = -1;
		while (++index.j < env->map.size.j)
		{
			if (env->map.coord[index.i][index.j].value != 1 &&
				(index.i == 0 || index.i == env->map.size.i - 1))
				die(env, "invalid map (borders are not walls)\n", 1);
			if (env->map.coord[index.i][index.j].value != 1 && (index.j == 0 ||
			index.j == env->map.size.j - 1))
				die(env, "invalid map (borders are not walls)\n", 1);
			if (env->map.coord[index.i][index.j].value == 0)
				c++;
			if (check_length(env->map.coord[index.i][index.j].value) != 1)
				die(env, "invalid map (map must contain only digits)\n", 1);
		}
	}
	if (c == 0)
		die(env, "invalid map (only walls)\n", 1);
}
