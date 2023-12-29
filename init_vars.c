/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:11:35 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 10:15:03 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	init_vars(t_vars *vars)
{
	vars->door_count = 0;
	vars->floor_count = 0;
	vars->wall_count = 0;
	vars->chest_count = 0;
	vars->monster_count = 0;
	vars->character_count = 0;
	vars->steps = 0;
	vars->is_found = 0;
}
