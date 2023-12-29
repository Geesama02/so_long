/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:07:52 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/27 16:34:08 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	map_path_check(char **map, int x, int y, t_vars *vars)
{
	if (x < 0 || y < 0
		|| map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'C')
		vars->chest_collected++;
	if (x == vars->character.x && y == vars->character.y)
		vars->is_found = 1;
	if (vars->chest_collected == vars->chest_count && vars->is_found == 1)
		return (1);
	if (x == vars->character.x && y == vars->character.y
		&& vars->chest_collected == vars->chest_count)
		return (1);
	if (map[y][x] != 'P')
		map[y][x] = 'V';
	if (map_path_check(map, x + 1, y, vars)
		|| map_path_check(map, x - 1, y, vars)
		|| map_path_check(map, x, y + 1, vars)
		|| map_path_check(map, x, y - 1, vars))
		return (1);
	return (0);
}
