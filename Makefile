CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c get_next_line.c get_next_line_utils.c allocate_memory.c \
		check_collisions.c check_map_rectangular.c close_program.c \
		count_elements.c count_rows.c fill_count.c fill_map.c \
		free_memory.c ft_itoa.c handle_file.c handle_invalid_map.c \
		init_vars.c key_hook.c map_border_check.c map_path_check.c \
		monster_movement.c move_sides.c process_door_and_monster.c \
		process_floor_and_player.c process_line.c process_walls_and_chests.c \
		put_image.c render_next_frame.c render_next_move.c set_frames.c \
		show_steps.c wall_check.c ft_printf_mem.c ft_lower_hex.c ft_putchar.c \
		ft_putnbr.c ft_putstr.c ft_upper_hex.c u_printf.c ft_printf.c
OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c so_long_header.h get_next_line.h ft_printf.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all