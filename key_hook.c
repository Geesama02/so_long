/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:05:14 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 14:33:39 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_program(vars);
	else if (keycode == 13
		&& wall_check(vars->character.x,
			vars->character.y - 25, vars->wall_count, vars) == 0)
	{
		vars->character.y -= 25;
		vars->character.mv = 1;
		vars->steps++;
	}
	else if (keycode == 1
		&& wall_check(vars->character.x,
			vars->character.y + 25, vars->wall_count, vars) == 0)
	{
		vars->character.y += 25;
		vars->character.mv = 1;
		vars->steps++;
	}
	else if (keycode == 0 || keycode == 2)
		move_sides(keycode, vars);
	return (0);
}
