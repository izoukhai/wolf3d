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

int			cross_exit(t_env *env)
{
	die(env, "program exit.\n", 1);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		die(&env, "usage: ./wolf3d [map]\n", 0);
	if ((env.fd = open(av[1], O_RDONLY)) == -1)
		die(&env, "invalid file\n", 0);
	init(&env, av[1]);
	ray_cast(&env);
	mlx_hook(env.win, 2, 0, on_press, &env);
	mlx_hook(env.win, 3, 0, on_release, &env);
	mlx_hook(env.win, 17, 0, cross_exit, &env);
	mlx_loop_hook(env.mlx, handle_move, &env);
	mlx_loop(env.mlx);
	return (0);
}
