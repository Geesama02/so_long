/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:12:57 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/26 16:31:55 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	map_border_check(char **map, int row_count)
{
	int	i;
	int	j;

	i = 0;
	if (check_map_rectangular(map, row_count) == 0)
		return (0);
	while (i < row_count)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (i == 0 || i == row_count - 1 || j == 0 || map[i][j + 1] == '\n')
			{
				if (map[i][j] != '1' && map[i][j] != '\n')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
