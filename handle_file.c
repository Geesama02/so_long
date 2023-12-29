/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:10:57 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 14:54:51 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

static int	read_file(char *file, int *fd, char **map, char **line)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		perror("Map");
		free(map);
		return (0);
	}
	*line = get_next_line(*fd);
	if (!*line)
	{
		free(map);
		perror("Error\nInvalid map");
		close(*fd);
		return (0);
	}
	return (1);
}

int	handle_file(char *file, t_vars *vars, char **map, int *r)
{
	char	*line;
	int		fd;

	line = NULL;
	if (!read_file(file, &fd, map, &line))
		return (0);
	*r = fill_map(vars, map, line, fd);
	if (*r == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
