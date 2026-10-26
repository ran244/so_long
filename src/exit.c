/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:18:51 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter(char *file)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		return (i);
	}
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	free_images(t_data *data, struct s_images *images)
{
	if (images->deadman)
		mlx_destroy_image(data->mlx, images->deadman);
	if (images->vamp)
		mlx_destroy_image(data->mlx, images->vamp);
	if (images->skully)
		mlx_destroy_image(data->mlx, images->skully);
	if (images->tile)
		mlx_destroy_image(data->mlx, images->tile);
	if (images->coffin)
		mlx_destroy_image(data->mlx, images->coffin);
	if (images->coff)
		mlx_destroy_image(data->mlx, images->coff);
	if (images->blood)
		mlx_destroy_image(data->mlx, images->blood);
}

void	ft_exit(t_data *data, int exit_status, char *message)
{
	free_map(data->map);
	free_map(data->map_copy);
	free_images(data, &data->images);
	if (data->mlx && data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (message)
	{
		if (exit_status != 0)
			ft_printf("Error\n%s\n", message);
		else
			ft_printf("%s\n", message);
	}
	exit(exit_status);
}
