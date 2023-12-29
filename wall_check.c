/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:58:55 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 17:58:38 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	wall_check(int x, int y, int wall_count, t_vars *vars)
{
	int	i;

	i = 0;
	while (i != wall_count)
	{
		if (x < vars->wall_position[i].x + 50
			&& x + 50 > vars->wall_position[i].x
			&& y < vars->wall_position[i].y + 50
			&& y + 50 > vars->wall_position[i].y)
			return (1);
		i++;
	}
	return (0);
}
