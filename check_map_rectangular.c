/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:12:02 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/25 12:17:52 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_header.h"

int	check_map_rectangular(char **map, int row_count)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (row_count > 27)
		return (0);
	while (i < row_count)
	{
		len = ft_strlen(map[i]);
		if (len == 0 || len > 51)
			return (0);
		if (i + 1 < row_count - 1 && len != ft_strlen(map[i + 1]))
			return (0);
		if (i + 1 == row_count - 1 && len - 1 != ft_strlen(map[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
