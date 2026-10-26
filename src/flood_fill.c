/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:18:43 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	insert_copy(t_data *info)
{
	int	i;

	i = 0;
	info->map_copy = (char **)ft_calloc((info->height + 1), sizeof(char *));
	if (!info->map_copy)
		return (1);
	while (info->map[i])
	{
		info->map_copy[i] = ft_strdup(info->map[i]);
		if (!info->map_copy)
			return (1);
		i++;
	}
	info->map_copy[i] = NULL;
	return (0);
}

void	flood_fill(t_data *info, int x, int y)
{
	if (x < 0 || x >= info->width || y < 0 || y >= info->height)
		return ;
	if (info->map_copy[y][x] == '1')
		return ;
	if (info->map_copy[y][x] == 'C')
		info->copy_c -= 1;
	if (info->map_copy[y][x] == 'E')
		info->exit_flag = 1;
	info->map_copy[y][x] = '1';
	flood_fill(info, x - 1, y);
	flood_fill(info, x + 1, y);
	flood_fill(info, x, y - 1);
	flood_fill(info, x, y + 1);
}

int	solveable(t_data *info)
{
	info->exit_flag = 0;
	findxy(info);
	find_col(info);
	if (insert_copy(info))
		return (1);
	flood_fill(info, info->x, info->y);
	if (info->copy_c > 0 || info->exit_flag == 0)
		return (1);
	return (0);
}
