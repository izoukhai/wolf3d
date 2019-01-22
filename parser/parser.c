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

static inline void	get_lines(env_t *env)
{
	char			*line;
	index_t			index;
	int				c;
	int				tmp;

	set_index(&index, 0, -1);
	c = 0;
	while ((get_next_line(env->fd, &line)) == 1)
	{
		index.j = -1;
		while (line[++index.j])
			if (line[index.j] == '9')
				c++;
		index.i++;
		env->map.size.j = index.j - ft_strichr(line, ' ');
	}
	env->map.size.i = index.i;
	close(env->fd);
	if (c != 1)
		die("invalid map.(can't find player position)\n");
}

static inline void	init_coord(env_t *env)
{
	index_t			index;

	set_index(&index, -1, -1);
	env->map.coord = (point_t**)malloc(sizeof(point_t*) * env->map.size.i);
	while (++index.i < env->map.size.i)
	{
		index.j = -1;
		env->map.coord[index.i] = (point_t*)malloc(sizeof(point_t) *
			env->map.size.j);
		while (++index.j < env->map.size.j)
		{
			env->map.coord[index.i][index.j].x = index.j * 45;
			env->map.coord[index.i][index.j].y = index.i * 45;
		}
	}
}

static inline void	get_coord(env_t *env)
{
	char			*line;
	index_t			index;
	char			**split;

	set_index(&index, 0, 1);
	s_open(env, env->file);
	while ((get_next_line(env->fd, &line)) == 1)
	{
		index.j = -1;
		split = ft_strsplit(line, ' ');
		while (split[++index.j])
		{
			if (ft_atoi(split[index.j]) == 9)
				env->player.pos = index_to_pos(index);
			env->map.coord[index.i][index.j].value = ft_atoi(split[index.j]);
		}
		index.i++;
	}
	close(env->fd);
}

void				init_map(env_t *env)
{
	/*check_file(*env);
	check_map(env);
	init_coord(env);
	get_map(env);*/
	get_lines(env);
	init_coord(env);
	get_coord(env);
}
