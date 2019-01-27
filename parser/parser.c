/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 23:55:14 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 23:55:15 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

static inline void	get_lines(t_env *env)
{
	char			*line;
	t_index			index;
	int				c;
	int				tmp_j;

	set_index(&index, 0, -1);
	c = 0;
	tmp_j = -1;
	while ((get_next_line(env->fd, &line)) == 1)
	{
		index.j = -1;
		while (line[++index.j])
			if (line[index.j] == '9')
				c++;
		index.i++;
		if (env->map.size.j > 0)
			tmp_j = env->map.size.j;
		env->map.size.j = index.j - ft_strichr(line, ' ');
		if (tmp_j != -1 && tmp_j != env->map.size.j)
			die(env, "invalid map (lines are not equals)\n", 0);
	}
	env->map.size.i = index.i;
	close(env->fd);
	if (c != 1)
		die(env, "invalid map (can't find player position)\n", 0);
}

static inline void	init_coord(t_env *env)
{
	t_index			index;

	set_index(&index, -1, -1);
	env->map.coord = (t_point**)malloc(sizeof(t_point*) * env->map.size.i);
	while (++index.i < env->map.size.i)
	{
		index.j = -1;
		env->map.coord[index.i] = (t_point*)malloc(sizeof(t_point) *
			env->map.size.j);
		while (++index.j < env->map.size.j)
		{
			env->map.coord[index.i][index.j].x = 0;
			env->map.coord[index.i][index.j].y = 0;
		}
	}
	env->malloced = 1;
}

static inline void	get_coord(t_env *env)
{
	char			*line;
	t_index			index;
	char			**split;

	set_index(&index, 0, 1);
	s_open(env, env->file);
	while ((get_next_line(env->fd, &line)) == 1)
	{
		index.j = -1;
		split = ft_strsplit(line, ' ');
		while (split[++index.j])
		{
			if ((ft_atoi(split[index.j])) == 9)
				env->player.pos = t_indexo_pos(index);
			env->map.coord[index.i][index.j].value = ft_atoi(split[index.j]);
		}
		index.i++;
	}
	close(env->fd);
}

void				init_map(t_env *env)
{
	get_lines(env);
	init_coord(env);
	get_coord(env);
	check_map(env);
}
