/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:01:57 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 11:15:17 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	put_imgs(t_vars *vars, int i)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->monster[i].frames[vars->monster->current_frame].img,
		vars->monster[i].x, vars->monster[i].y + 10);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->character.frames[vars->character.current_frame].img,
		vars->character.x, vars->character.y);
}

void	monster_movement(t_vars *vars, int i, int *frame_delay)
{
	if (vars->monster[i].x < vars->character.x
		&& wall_check(vars->monster[i].x + 1.25, vars->monster[i].y,
			vars->wall_count, vars) == 0)
	{
		vars->monster[i].side = 'l';
		vars->monster[i].x += 1.25;
	}
	else if (vars->monster[i].x > vars->character.x
		&& wall_check(vars->monster[i].x - 1.25, vars->monster[i].y,
			vars->wall_count, vars) == 0)
	{
		vars->monster[i].side = 'r';
		vars->monster[i].x -= 1.25;
	}
	else if (vars->monster[i].y < vars->character.y
		&& wall_check(vars->monster[i].x, vars->monster[i].y + 1.25,
			vars->wall_count, vars) == 0)
		vars->monster[i].y += 1.25;
	else if (vars->monster[i].y > vars->character.y
		&& wall_check(vars->monster[i].x, vars->monster[i].y - 1.25,
			vars->wall_count, vars) == 0)
		vars->monster[i].y -= 1.25;
	put_imgs(vars, i);
	if (*frame_delay == 0)
		vars->monster->current_frame = (vars->monster->current_frame + 1) % 6;
}
