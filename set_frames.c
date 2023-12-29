/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_frames.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:57:27 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 16:32:53 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	load_monster_frames(t_vars *vars, int i, int j, char *path)
{
	vars->monster[j].frames[i].img = mlx_xpm_file_to_image(vars->mlx, path,
			&vars->monster[j].frames[i].width,
			&vars->monster[j].frames[i].height);
	if (vars->monster[j].frames[i].img == NULL)
	{
		perror("Error\nInvalid textures");
		close_program(vars);
	}
}

static void	load_character_frames(t_vars *vars, int i, char *path)
{
	vars->character.frames[i].img = mlx_xpm_file_to_image(vars->mlx, path,
			&vars->character.frames[i].width,
			&vars->character.frames[i].height);
	if (vars->character.frames[i].img == NULL)
	{
		perror("Error\nInvalid textures");
		close_program(vars);
	}
}

void	set_monster_frames(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->monster_count > 0 && i < vars->monster_count)
	{
		if (vars->monster[i].side == 'l')
		{
			load_monster_frames(vars, 0, i, "./textures/Monster/Left/M0.xpm");
			load_monster_frames(vars, 1, i, "./textures/Monster/Left/M1.xpm");
			load_monster_frames(vars, 2, i, "./textures/Monster/Left/M2.xpm");
			load_monster_frames(vars, 3, i, "./textures/Monster/Left/M3.xpm");
			load_monster_frames(vars, 4, i, "./textures/Monster/Left/M4.xpm");
			load_monster_frames(vars, 5, i, "./textures/Monster/Left/M5.xpm");
		}
		else if (vars->monster[i].side == 'r')
		{
			load_monster_frames(vars, 0, i, "./textures/Monster/Right/M0.xpm");
			load_monster_frames(vars, 1, i, "./textures/Monster/Right/M1.xpm");
			load_monster_frames(vars, 2, i, "./textures/Monster/Right/M2.xpm");
			load_monster_frames(vars, 3, i, "./textures/Monster/Right/M3.xpm");
			load_monster_frames(vars, 4, i, "./textures/Monster/Right/M4.xpm");
			load_monster_frames(vars, 5, i, "./textures/Monster/Right/M5.xpm");
		}
		i++;
	}
}

void	set_character_frames(t_vars *vars)
{
	if (vars->character.side == 'l')
	{
		load_character_frames(vars, 0, "./textures/Player/Left/P0.xpm");
		load_character_frames(vars, 1, "./textures/Player/Left/P1.xpm");
		load_character_frames(vars, 2, "./textures/Player/Left/P2.xpm");
		load_character_frames(vars, 3, "./textures/Player/Left/P3.xpm");
		load_character_frames(vars, 4, "./textures/Player/Left/P4.xpm");
		load_character_frames(vars, 5, "./textures/Player/Left/P5.xpm");
	}
	else
	{
		load_character_frames(vars, 0, "./textures/Player/Right/P0.xpm");
		load_character_frames(vars, 1, "./textures/Player/Right/P1.xpm");
		load_character_frames(vars, 2, "./textures/Player/Right/P2.xpm");
		load_character_frames(vars, 3, "./textures/Player/Right/P3.xpm");
		load_character_frames(vars, 4, "./textures/Player/Right/P4.xpm");
		load_character_frames(vars, 5, "./textures/Player/Right/P5.xpm");
	}
}
