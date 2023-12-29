/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:02:58 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 16:13:34 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	put_image(int count, t_vars *vars, void *path,
					t_stuff_position *position)
{
	int	i;

	i = 0;
	while (i < count)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			path, position[i].x, position[i].y);
		i++;
	}
}
