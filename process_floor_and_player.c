/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_floor_and_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:15:05 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 11:51:50 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	process_floor_and_player(t_vars *vars, char character, int i, int l)
{
	static int	floor_count;

	if (character == '0' || character == 'C' || character == 'E'
		|| character == 'P' || character == 'M')
	{
		vars->floor_position[floor_count].x = l * 50;
		vars->floor_position[floor_count].y = i * 50;
		floor_count++;
	}
	if (character == 'P')
	{
		vars->character.x = l * 50;
		vars->character.y = i * 50;
	}
}
