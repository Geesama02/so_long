/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:20:21 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 16:33:21 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	open_door(t_vars *vars)
{
	vars->door.img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Door/Open_door.xpm", &vars->door.width,
			&vars->door.height);
	if (vars->door.img == NULL)
	{
		perror("Error\nInvalid textures");
		close_program(vars);
	}
}

int	render_next_frame(t_vars *vars)
{
	static int	frame_delay;
	int			delay_amount;
	int			i;

	i = 0;
	delay_amount = 7;
	check_collisions(vars);
	frame_delay = (frame_delay + 1) % delay_amount;
	if (vars->chest_collected == vars->chest_count)
		open_door(vars);
	render_next_move(vars, frame_delay);
	put_image(vars->floor_count, vars, vars->floor_position->img,
		vars->floor_position);
	put_image(vars->chest_count, vars, vars->chest_position->img,
		vars->chest_position);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->door.img,
		vars->door.x, vars->door.y);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->character.frames[vars->character.current_frame].img,
		vars->character.x, vars->character.y);
	while (vars->monster_count > 0 && i < vars->monster_count)
		monster_movement(vars, i++, &frame_delay);
	return (0);
}
