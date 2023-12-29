/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:56:51 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 11:44:32 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	destroy_monster_images(t_vars *vars, int i, int j)
{
	while (vars->monster_count > 0 && j < vars->monster_count
		&& vars->monster[j].frames[i].img != NULL)
	{
		if (vars->monster[j].frames[i].img != NULL)
			mlx_destroy_image(vars->mlx, vars->monster[j].frames[i].img);
		j++;
	}
}

int	close_program(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 6 && vars->character.frames[i].img != NULL)
		mlx_destroy_image(vars->mlx, vars->character.frames[i++].img);
	if (vars->character.frames[i].img != NULL)
	{
		i = 0;
		while (i < 6 && vars->monster_count > 0 && j < vars->monster_count)
			destroy_monster_images(vars, i++, j++);
	}
	mlx_destroy_image(vars->mlx, vars->chest_position->img);
	mlx_destroy_image(vars->mlx, vars->wall_position->img);
	if (vars->door.img != NULL)
		mlx_destroy_image(vars->mlx, vars->door.img);
	mlx_destroy_image(vars->mlx, vars->floor_position->img);
	free(vars->floor_position);
	free(vars->wall_position);
	free(vars->chest_position);
	if (vars->monster_count > 0)
		free(vars->monster);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
