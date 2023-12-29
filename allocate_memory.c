/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:49:57 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 12:10:11 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	handle_error(t_vars *vars)
{
	perror("Malloc");
	free(vars->floor_position);
	free(vars->chest_position);
	free(vars->wall_position);
	exit(5);
}

void	allocate_memory(t_vars *vars)
{
	vars->floor_position = (t_stuff_position *)malloc(
			sizeof(t_stuff_position) * vars->floor_count);
	vars->chest_position = (t_stuff_position *)malloc(
			sizeof(t_stuff_position) * vars->chest_count);
	vars->wall_position = (t_stuff_position *)malloc(
			sizeof(t_stuff_position) * vars->wall_count);
	if (!vars->floor_position || !vars->chest_position || !vars->wall_position)
		handle_error(vars);
	if (vars->monster_count > 0)
	{
		vars->monster = (t_character *)malloc(
				sizeof(t_character) * vars->monster_count);
		if (!vars->monster)
			handle_error(vars);
	}
}
