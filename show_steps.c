/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:01:04 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 17:47:08 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	show_steps(t_vars *vars)
{
	char	*steps_str;
	char	*str;

	steps_str = ft_itoa(vars->steps);
	if (!steps_str)
		close_program(vars);
	str = ft_strjoin("Steps: ", steps_str);
	if (!str)
	{
		free(steps_str);
		close_program(vars);
	}
	free(steps_str);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0x00FFFFFF, str);
	free(str);
}
