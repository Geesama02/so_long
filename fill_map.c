/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:10:28 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 14:04:44 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	fill_map(t_vars *vars, char **map, char *line, int fd)
{
	int	i;
	int	r;

	r = 0;
	while (line != NULL)
	{
		i = 0;
		map[r] = ft_strdup(line);
		if (!map[r])
			return ((int)free_memory(map, line, r));
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (fill_count(vars, line[i], i, r) == 0)
			{
				perror("Error\nInvalid map");
				free(map[r]);
				return ((int)free_memory(map, line, r));
			}
			i++;
		}
		r++;
		free(line);
		line = get_next_line(fd);
	}
	return (r);
}
