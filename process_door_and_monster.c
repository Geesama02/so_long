/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_door_and_monster.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:16:14 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 10:53:48 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	process_door_and_monster(t_vars *vars, char character, int i, int l)
{
	static int	monster_count;

	if (character == 'E')
	{
		vars->door.x = l * 50;
		vars->door.y = i * 50;
	}
	else if (character == 'M')
	{
		vars->monster[monster_count].side = 'r';
		vars->monster[monster_count].x = l * 50;
		vars->monster[monster_count].y = i * 50;
		monster_count++;
	}
}
