/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:21:18 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:15:34 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_cross(t_data *data)
{
	ft_exit(data, 0, NULL);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*info;
	int	is_move;

	info = param;
	is_move = 0;
	info->ox = info->x;
	info->oy = info->y;
	if (info->coll == 0)
		mlx_put_image_to_window(info->mlx, info->window,
			info->images.coff, (info->ex) * 40, (info->ey) * 40);
	if (keycode == 119 || keycode == 65362)
		is_move = moveup(info);
	else if (keycode == 100 || keycode == 65363)
		is_move = moveright(info);
	else if (keycode == 97 || keycode == 65361)
		is_move = moveleft(info);
	else if (keycode == 115 || keycode == 65364)
		is_move = movedown(info);
	else if (keycode == 65307)
		ft_exit(info, 0, NULL);
	if (is_move)
		move(info, &info->images);
	return (0);
}

void	check_for_errors(t_data *info, char *map_path)
{
	int	w;
	int	h;

	if (checkfile(map_path) == 0)
		ft_exit(info, 1, "WRONG FILE TYPE");
	if (inserttoarr(info, map_path))
		ft_exit(info, 1, "FAILED TO ALLOCATE MAP");
	find_e(info);
	if (checkrec(info) != 0 || checkborder(info) != 0 || check_input(info) != 0)
		ft_exit(info, 1, "WRONG SHAPE OR INPUT OR BORDER");
	mlx_get_screen_size(info->mlx, &w, &h);
	if (info->width > (w / 40) || info->height > (h / 40))
		ft_exit(info, 1, "MAP IS TOO LONG");
	if (solveable(info) != 0)
		ft_exit(info, 1, "NOT SOLVEABLE");
}

int	main(int c, char **v)
{
	t_data	info;

	ft_bzero(&info, sizeof(info));
	if (c != 2)
		ft_exit(&info, 1, "WRONG NUM OF ARGS");
	info.mlx = mlx_init();
	if (!info.mlx)
		ft_exit(&info, 1, "NO CONNECTION");
	check_for_errors(&info, v[1]);
	info.window = mlx_new_window (info.mlx, ((info.width)) * 40, \
								((info.height) * 40), "vamp ON skully!!!");
	if (!info.window)
		ft_exit(&info, 1, "NO CONNECTION NO WINDOW");
	put_image(&info, &info.images);
	// mlx_key_hook(info.windowpress, &info);
	mlx_hook(info.window, 17, 0, handle_cross, &info);
	mlx_hook(info.window, 2, 1L << 0, key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
