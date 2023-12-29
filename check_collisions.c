/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collisions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:00:01 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 12:16:52 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	check_win(t_vars *vars)
{
	if (vars->character.x < vars->door.x + 10
		&& vars->character.x + 50 > vars->door.x
		&& vars->character.y < vars->door.y + 10
		&& vars->character.y + 50 > vars->door.y
		&& vars->chest_collected == vars->chest_count)
	{
		ft_printf("\n");
		ft_printf("__   _____  _   _  __        _____ _   _ _ \n");
		ft_printf("\\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | | |\n");
		ft_printf(" \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| | |\n");
		ft_printf("  | || |_| | |_| |   \\ V  V /  | || |\\  |_|\n");
		ft_printf("  |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_(_)\n");
		ft_printf("\n");
		close_program(vars);
	}
}

static void	check_lose(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->monster_count)
	{
		if (vars->character.x < vars->monster[i].x + 10
			&& vars->character.x + 30 > vars->monster[i].x
			&& vars->character.y < vars->monster[i].y + 10
			&& vars->character.y + 30 > vars->monster[i].y)
		{
			ft_printf("\n");
			ft_printf("__   _____  _   _   _     ___  ____ _____ _ \n");
			ft_printf("\\ \\ / / _ \\| | | | | |   / _ \\/ ___|_   _| |\n");
			ft_printf(" \\ V / | | | | | | | |  | | | \\___ \\ | | | |\n");
			ft_printf("  | || |_| | |_| | | |__| |_| |___) || | |_|\n");
			ft_printf("  |_| \\___/ \\___/  |_____\\___/|____/ |_| (_)\n");
			ft_printf("\n");
			close_program(vars);
		}
		i++;
	}
}

void	check_collisions(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->chest_count)
	{
		if (vars->character.x < vars->chest_position[i].x + 15
			&& vars->character.x + 30 > vars->chest_position[i].x
			&& vars->character.y < vars->chest_position[i].y + 15
			&& vars->character.y + 30 > vars->chest_position[i].y)
		{
			vars->chest_position[i].x = -100;
			vars->chest_position[i].y = -100;
			vars->chest_collected += 1;
		}
		i++;
	}
	check_win(vars);
	check_lose(vars);
}
