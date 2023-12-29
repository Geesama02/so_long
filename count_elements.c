/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:14:24 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 11:51:56 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	*count_elements(t_vars *vars, char *file)
{
	int		r;
	int		row_count;
	char	**map;

	init_vars(vars);
	row_count = count_rows(file);
	if (row_count == 0)
		return (handle_invalid_map(NULL, NULL, 0));
	map = (char **)malloc(sizeof(char *) * row_count);
	if (!map)
		return (NULL);
	if (handle_file(file, vars, map, &r) == 0)
		return (NULL);
	if (vars->character_count != 1 || vars->door_count != 1
		|| vars->floor_count == 0 || vars->wall_count == 0
		|| vars->chest_count == 0)
		return (handle_invalid_map(map, NULL, r));
	if (map_border_check(map, row_count) == 0
		|| map_path_check(map, vars->door.x, vars->door.y, vars) == 0)
		return (handle_invalid_map(map, NULL, r));
	vars->chest_collected = 0;
	free_memory(map, NULL, r);
	return (vars);
}
