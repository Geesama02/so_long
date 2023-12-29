/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_invalid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:13:32 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/26 14:56:02 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

void	*handle_invalid_map(char **map, char *line, int r)
{
	perror("Error\nInvalid map");
	return (free_memory(map, line, r));
}
