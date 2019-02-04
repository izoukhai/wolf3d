/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   textures.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 21:01:52 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 21:01:52 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

void			set_textures(t_env *env)
{
	env->tex.walls[0].ptr = mlx_xpm_file_to_image(env->mlx,
	"textures/brick.xpm", &env->tex.walls[0].width, &env->tex.walls[0].height);
	env->tex.walls[0].buf = (int*)mlx_get_data_addr(env->tex.walls[0].ptr,
	&env->tex.walls[0].bpp, &env->tex.walls[0].szl, &env->tex.walls[0].endian);
	env->tex.walls[1].ptr = mlx_xpm_file_to_image(env->mlx,
	"textures/redbrick.xpm", &env->tex.walls[0].width,
	&env->tex.walls[1].height);
	env->tex.walls[1].buf = (int*)mlx_get_data_addr(env->tex.walls[1].ptr,
	&env->tex.walls[1].bpp, &env->tex.walls[0].szl,
	&env->tex.walls[1].endian);
	env->tex.walls[2].ptr = mlx_xpm_file_to_image(env->mlx,
	"textures/stone.xpm", &env->tex.walls[0].width, &env->tex.walls[2].height);
	env->tex.walls[2].buf = (int*)mlx_get_data_addr(env->tex.walls[2].ptr,
	&env->tex.walls[2].bpp, &env->tex.walls[0].szl, &env->tex.walls[2].endian);
	env->tex.walls[3].ptr = mlx_xpm_file_to_image(env->mlx,
	"textures/wood.xpm", &env->tex.walls[0].width, &env->tex.walls[3].height);
	env->tex.walls[3].buf = (int*)mlx_get_data_addr(env->tex.walls[3].ptr,
	&env->tex.walls[3].bpp, &env->tex.walls[0].szl, &env->tex.walls[3].endian);
}

void			del_textures(t_env *env)
{
	int			i;

	i = -1;
	while (++i < 4)
		if (env->tex.walls[i].ptr != NULL)
			mlx_destroy_image(env->mlx, env->tex.walls[i].ptr);
}
