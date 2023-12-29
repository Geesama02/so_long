/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:43:29 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 12:28:19 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static void	free_and_perror(t_vars *vars, char *str)
{
	free_vars(vars);
	perror(str);
	exit(6);
}

static void	set_imgs(t_vars *vars)
{
	vars->floor_position->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Floor.xpm", &vars->floor_position->width,
			&vars->floor_position->height);
	vars->wall_position->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Wall.xpm", &vars->wall_position->width,
			&vars->wall_position->height);
	vars->door.img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Door/Closed_door.xpm", &vars->door.width,
			&vars->door.height);
	vars->chest_position->img = mlx_xpm_file_to_image(vars->mlx,
			"./textures/Collectable/C0.xpm", &vars->chest_position->width,
			&vars->chest_position->height);
	if (vars->floor_position->img == NULL || vars->wall_position->img == NULL
		|| vars->door.img == NULL || vars->chest_position->img == NULL)
	{
		perror("Error\nInvalid textures");
		free_vars(vars);
		exit(5);
	}
}

static void	start_game(t_vars *vars, int i, int j)
{
	vars->chest_collected = 0;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		free_and_perror(vars, "Error\nmlx init failed");
	vars->win = mlx_new_window(vars->mlx, j * 50, i * 50, "My Game");
	if (vars->win == NULL)
		free_and_perror(vars, "Error\nmlx window failed");
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	set_imgs(vars);
	set_character_frames(vars);
	set_monster_frames(vars);
	vars->character.current_frame = 0;
	if (vars->monster_count > 0)
		vars->monster->current_frame = 0;
	put_image(vars->wall_count, vars, vars->wall_position->img,
		vars->wall_position);
	show_steps(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->character.frames[vars->character.current_frame].img,
		vars->character.x, vars->character.y);
	mlx_hook(vars->win, 17, 0, close_program, vars);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_loop(vars->mlx);
}

static void	read_file(char *file_name, t_vars *vars, char **line, int *fd)
{
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
	{
		free_vars(vars);
		perror("Map");
		exit(3);
	}
	*line = get_next_line(*fd);
	if (!*line)
	{
		free_vars(vars);
		perror("Error\nInvalid map");
		close(*fd);
		exit(4);
	}
}

int	main(int argc, char **argv)
{
	char	*line;
	t_vars	vars;
	int		i;
	int		j;
	int		fd;

	i = 0;
	j = 0;
	line = NULL;
	if (argc != 2)
	{
		perror("Error\nInvalid number of arguments");
		return (1);
	}
	if (!count_elements(&vars, argv[1]))
		return (2);
	allocate_memory(&vars);
	read_file(argv[1], &vars, &line, &fd);
	j = ft_strlen(line) - 1;
	process_line(&vars, line, fd, &i);
	start_game(&vars, i, j);
	return (0);
}
