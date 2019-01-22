/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: izoukhai <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 23:31:49 by izoukhai     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 23:31:49 by izoukhai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../wolf3d.h"

int			main(int ac, char **av)
{
	env_t	env;
	if ((env.fd = open(av[1], O_RDONLY)) == -1)
		die("invalid file\n");
	init(&env, av[1]);
	index_t index;
	index.i = -1;
	index.j = -1;
	ray_cast(&env);
	//mlx_put_image_to_window(env.mlx, env.win, env.image.ptr, 0, 0);
	mlx_hook(env.win, 2, 0, on_press, &env);
	//mlx_hook(env.win, 2, 0, on_release, &env);
	mlx_loop(env.mlx);
	return (0);
}
