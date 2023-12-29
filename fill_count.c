/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:09:57 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 14:03:56 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	fill_count(t_vars *vars, char c, int i, int r)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M')
		vars->floor_count++;
	if (c == '1')
		vars->wall_count++;
	else if (c == 'P')
	{
		vars->character_count++;
		vars->character.side = 'r';
		vars->character.x = i;
		vars->character.y = r;
	}
	else if (c == 'C')
		vars->chest_count++;
	else if (c == 'E')
	{
		vars->door_count++;
		vars->door.x = i;
		vars->door.y = r;
	}
	else if (c == 'M')
		vars->monster_count++;
	else if (c != '0')
		return (0);
	return (1);
}
