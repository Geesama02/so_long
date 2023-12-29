/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:16:39 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 16:11:01 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	process_line(t_vars *vars, char *line, int fd, int *i)
{
	int	l;

	while (line != NULL)
	{
		l = 0;
		while (line[l] != '\0' && line[l] != '\n')
		{
			process_floor_and_player(vars, line[l], *i, l);
			process_walls_and_chests(vars, line[l], *i, l);
			process_door_and_monster(vars, line[l], *i, l);
			l++;
		}
		(*i)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
