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

void		die(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

point_t		index_to_pos(index_t index)
{
	point_t res;

	res.x = index.j;
	res.y = index.i;
	return (res);
}

void		set_index(index_t *index, int i, int j)
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

point_t		new_point(double x, double y)
{
	point_t	res;

	res.x = x;
	res.y = y;
	return (res);
}