/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_walls_and_chests.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:15:36 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 16:11:35 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	process_walls_and_chests(t_vars *vars, char character, int i, int l)
{
	static int	wall_count;
	static int	chest_count;

	if (character == '1')
	{
		vars->wall_position[wall_count].x = l * 50;
		vars->wall_position[wall_count].y = i * 50;
		wall_count++;
	}
	else if (character == 'C')
	{
		vars->chest_position[chest_count].x = l * 50 + 15;
		vars->chest_position[chest_count].y = i * 50 + 15;
		chest_count++;
	}
}
