/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheching.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:15:30 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkrec(t_data *info)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (info->map[i])
	{
		remove_nl (info->map[i]);
		if (i == 0)
			info->width = (int)ft_strlen(info->map[0]);
		len = (int)ft_strlen(info->map[i]);
		if (len != info->width)
			return (1);
		i++;
	}
	return (0);
}

int	checkborder(t_data *info)
{
	int	i;

	i = 0;
	while (i < info->width)
	{
		if (info->map[0][i] != '1' || info->map[(info->height) - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < info->height)
	{
		if (info->map[i][0] != '1' || info->map[i][info->width - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_input(t_data *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width - 1)
		{
			if ((ft_strchr("ECP01", info->map[i][j]) == NULL))
				return (1);
			if (info->map[i][j] == 'P')
				info->p++;
			else if (info->map[i][j] == 'E')
				info->e++;
			else if (info->map[i][j] == 'C')
				info->c++;
			j++;
		}
		i++;
	}
	if (info->p != 1 || info->e != 1 || info->c < 1)
		return (1);
	return (0);
}

int	inserttoarr(t_data *info, char *file)
{
	char	*line;
	int		i;
	int		map_size;
	int		fd;

	i = 0;
	map_size = 0;
	map_size = counter(file);
	info->map = (char **)ft_calloc(sizeof(char *), (map_size + 1));
	if (!info->map)
		return (1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line || map_size == 0)
		return (1);
	while (line != NULL)
	{
		info->map[i++] = line;
		line = get_next_line(fd);
	}
	info->map[i] = NULL;
	info->height = i;
	close(fd);
	return (0);
}

int	checkfile(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'r' && file[len - 2] == 'e'
		&& file[len - 3] == 'b' && file[len - 4] == '.')
		return (1);
	return (0);
}
