/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:42:07 by rabusala          #+#    #+#             */
/*   Updated: 2025/02/02 13:01:08 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <MLX/mlx.h>
# include <stdio.h>
# include <stdio.h>
# include "libft/libft.h"

struct s_images
{
	void	*skully;
	void	*vamp;
	void	*deadman;
	void	*coffin;
	void	*tile;
	void	*coff;
	void	*blood;
};

typedef struct s_data
{
	struct s_images	images;
	void			*mlx;
	void			*window;
	int				height;
	int				width;
	char			**map;
	int				x;
	int				y;
	int				ox;
	int				oy;
	int				coll;
	int				ey;
	int				ex;
	int				copy_c;
	int				exit_flag;
	char			**map_copy;
	int				p;
	int				e;
	int				c;
}	t_data;

void	remove_nl(char *str);
void	flood_fill(t_data *info, int x, int y);

void	ft_exit(t_data *data, int exit_status, char *exit);

void	find_e(t_data *info);
void	findxy(t_data *info);
void	find_col(t_data *info);

void	put_image(t_data *info, struct s_images *images);
void	put_image_2(t_data *info, struct s_images *images, int j, int i);

int		handle_esc(int keycode, t_data *data);
int		handle_cross(t_data *data);

int		checkfile(char *file);
int		checkrec(t_data *info);
int		checkborder(t_data *info);
int		check_input(t_data *info);
int		solveable(t_data *info);

void	swap_image(t_data *info, void *image1, void *image2, void *image3);
void	move(t_data *info, struct s_images *images);
int		moveleft(t_data *info);
int		moveright(t_data *info);
int		movedown(t_data *info);
int		moveup(t_data *info);

int		inserttoarr(t_data *info, char *file);
int		insert_copy(t_data *info);
int		counter(char *file);

#endif
