/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:18:23 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	transform(t_data *info, struct s_images *images)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	images->skully = mlx_xpm_file_to_image(info->mlx, "bskully.xpm", &x, &y);
	if (!images->skully)
		ft_exit(info, 1, "IMAGE bskully.xpm DOES NOT EXIST");
	images->vamp = mlx_xpm_file_to_image(info->mlx, "vampire.xpm", &x, &y);
	if (!images->vamp)
		ft_exit(info, 1, "IMAGE vampire.xpm DOES NOT EXIST");
	images->coffin = mlx_xpm_file_to_image(info->mlx, "closed.xpm", &x, &y);
	if (!images->coffin)
		ft_exit(info, 1, "IMAGE closed.xpm DOES NOT EXIST");
	images->deadman = mlx_xpm_file_to_image(info->mlx, "deadman.xpm", &x, &y);
	if (!images->deadman)
		ft_exit(info, 1, "IMAGE deadman.xpm DOES NOT EXIST");
	images->tile = mlx_xpm_file_to_image(info->mlx, "sfloor.xpm", &x, &y);
	if (!images->tile)
		ft_exit(info, 1, "IMAGE sfloor.xpm DOES NOT EXIST");
	images->coff = mlx_xpm_file_to_image(info->mlx, "opencoffin.xpm", &x, &y);
	images->blood = mlx_xpm_file_to_image(info->mlx, "blood.xpm", &x, &y);
	if (!images->tile || !images->tile)
		ft_exit(info, 1, "IMAGE opencoffin.xpm DOES NOT EXIST");
}

void	put_image(t_data *info, struct s_images *images)
{
	int	i;
	int	j;

	i = 0;
	transform(info, images);
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->window,
					images->skully, j * 40, i * 40);
			else if (info->map[i][j] == '0')
				mlx_put_image_to_window(info->mlx, info->window,
					images->tile, j * 40, i * 40);
			else
				put_image_2(info, images, j, i);
			j++;
		}
		i++;
	}
}

void	put_image_2(t_data *info, struct s_images *images, int j, int i)
{
	if (info->map[i][j] == 'C')
		mlx_put_image_to_window(info->mlx, info->window,
			images->deadman, j * 40, i * 40);
	else if (info->map[i][j] == 'P')
		mlx_put_image_to_window(info->mlx, info->window,
			images->vamp, j * 40, i * 40);
	else if (info->map[i][j] == 'E')
		mlx_put_image_to_window(info->mlx, info->window,
			images->coffin, j * 40, i * 40);
}
