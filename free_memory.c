/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:09:27 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 11:29:47 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	*free_memory(char **map, char *line, int r)
{
	while (r != 0)
		free(map[--r]);
	free(map);
	free(line);
	return (NULL);
}

void	free_vars(t_vars *vars)
{
	free(vars->floor_position);
	free(vars->chest_position);
	free(vars->wall_position);
	if (vars->monster_count > 0)
		free(vars->monster);
}
