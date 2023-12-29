/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:51:23 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/28 10:54:32 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_stuff_position
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_stuff_position;

typedef struct s_data
{
	void	*img;
	int		width;
	int		height;
}	t_data;

typedef struct s_character
{
	t_data		frames[6];
	int			current_frame;
	char		side;
	double		x;
	double		y;
	int			mv;
}	t_character;

typedef struct s_vars
{
	t_stuff_position	*floor_position;
	t_stuff_position	*wall_position;
	t_stuff_position	*chest_position;
	t_character			character;
	t_character			*monster;
	t_stuff_position	door;
	void				*mlx;
	void				*win;
	int					is_found;
	int					steps;
	int					character_count;
	int					monster_count;
	int					door_count;
	int					floor_count;
	int					wall_count;
	int					chest_count;
	int					chest_collected;
}	t_vars;

void	allocate_memory(t_vars *vars);
void	process_line(t_vars *vars, char *line, int fd, int *i);
int		key_hook(int keycode, t_vars *vars);
void	put_image(int count, t_vars *vars, void *img,
			t_stuff_position *position);
void	show_steps(t_vars *vars);
int		wall_check(int x, int y, int count, t_vars *vars);
void	set_character_frames(t_vars *vars);
void	set_monster_frames(t_vars *vars);
void	monster_movement(t_vars *vars, int i, int *frame_delay);
void	render_next_move(t_vars *vars, int frame_delay);
int		render_next_frame(t_vars *vars);
int		close_program(t_vars *vars);
void	check_collisions(t_vars *vars);
void	*free_memory(char **map, char *line, int r);
int		map_border_check(char **map, int row_count);
int		check_map_rectangular(char **map, int row_count);
int		map_path_check(char **map, int start_x, int start_y,
			t_vars *vars);
int		count_rows(char *file);
int		handle_file(char *file, t_vars *vars, char **map,
			int *r);
void	*handle_invalid_map(char **map, char *line, int r);
void	init_vars(t_vars *vars);
void	*count_elements(t_vars *vars, char *file);
void	process_floor_and_player(t_vars *vars, char character,
			int i, int l);
void	process_walls_and_chests(t_vars *vars, char character,
			int i, int l);
void	process_door_and_monster(t_vars *vars, char character,
			int i, int l);
void	process_line(t_vars *vars, char *line, int fd, int *i);
void	move_sides(int keycode, t_vars *vars);
int		fill_count(t_vars *vars, char c, int i, int r);
int		fill_map(t_vars *vars, char **map, char *line, int fd);
char	*ft_itoa(int n);
void	free_vars(t_vars *vars);

#endif