/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:56 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	findxy(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
			{
				info->x = j;
				info->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_col(t_data *info)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	info->coll = c;
	info->copy_c = c;
}

void	find_e(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'E')
			{
				info->ex = j;
				info->ey = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	swap_image(t_data *info, void *image1, void *image2, void *image3)
{
	mlx_put_image_to_window(info->mlx, info->window, image1,
		info->x * 40, info->y * 40);
	if (info->map[info->oy][info->ox] == '2')
		mlx_put_image_to_window(info->mlx, info->window, image3,
			info->ox * 40, info->oy * 40);
	else
		mlx_put_image_to_window(info->mlx, info->window, image2,
			info->ox * 40, info->oy * 40);
}

void	remove_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == '\n')
		str[i - 1] = '\0';
}
