/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:17:42 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *info, struct s_images *images)
{
	static int	movement_count;

	ft_printf("move_count: %d\n", ++movement_count);
	if (info->map[info->oy][info->ox] == 'E' && info->coll != 0)
	{
		swap_image(info, images->vamp, images->coffin, images->blood);
		if (info->map[info->y][info->x] == 'C')
			info->coll -= 1;
		if (info->map[info->y][info->x] == 'C')
			info->map[info->y][info->x] = '0';
		return ;
	}
	if (info->map[info->y][info->x] == 'E' && info->coll == 0)
	{
		swap_image(info, images->vamp, images->tile, images->blood);
		ft_exit(info, 0, NULL);
	}
	if (info->map[info->y][info->x] == 'C')
		info->coll -= 1;
	if (info->map[info->y][info->x] == 'C')
		info->map[info->y][info->x] = '2';
	swap_image(info, images->vamp, images->tile, images->blood);
}

int	moveup(t_data *info)
{
	if (info->map[info->y - 1][info->x] != '1')
	{
		info->y -= 1;
		return (1);
	}
	return (0);
}

int	movedown(t_data *info)
{
	if (info->map[info->y + 1][info->x] != '1')
	{
		info->y += 1;
		return (1);
	}
	return (0);
}

int	moveright(t_data *info)
{
	if (info->map[info->y][info->x + 1] != '1')
	{
		info->x += 1;
		return (1);
	}
	return (0);
}

int	moveleft(t_data *info)
{
	if (info->map[info->y][info->x - 1] != '1')
	{
		info->x -= 1;
		return (1);
	}
	return (0);
}
