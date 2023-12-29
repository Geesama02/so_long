/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:03:27 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 14:58:22 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	put_monster_image(t_vars *vars, int i, int frame_delay)
{
	while (vars->monster_count > 0 && i < vars->monster_count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->monster[i].frames[vars->monster->current_frame].img,
			vars->monster[i].x, vars->monster[i].y);
		if (frame_delay == 0)
			vars->monster->current_frame = (vars->monster->current_frame + 1)
				% 6;
		i++;
	}
}

void	render_next_move(t_vars *vars, int frame_delay)
{
	int	i;

	i = 0;
	if (vars->character.mv == 1)
	{
		mlx_clear_window(vars->mlx, vars->win);
		set_character_frames(vars);
		set_monster_frames(vars);
		put_image(vars->floor_count, vars, vars->floor_position->img,
			vars->floor_position);
		put_image(vars->wall_count, vars, vars->wall_position->img,
			vars->wall_position);
		show_steps(vars);
		put_image(vars->chest_count, vars, vars->chest_position->img,
			vars->chest_position);
		vars->character.current_frame = (vars->character.current_frame + 1) % 6;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->door.img,
			vars->door.x, vars->door.y);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->character.frames[vars->character.current_frame].img,
			vars->character.x, vars->character.y);
		put_monster_image(vars, i, frame_delay);
		vars->character.mv = 0;
	}
}
