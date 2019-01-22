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

void        s_open(env_t *env, char *file)
{
	if ((env->fd = open(file, O_RDONLY)) == -1)
		die("can't open file.");
}

void        check_map(env_t *env)
{
	index_t index;

	index.i = -1;
	while (++index.i < env->map.size.i)
	{
		
	}
}