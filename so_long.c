/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:39:03 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/30 19:47:51 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game)
{
	game->width = 640;
	game->height = 480;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_printf("Error");
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
		ft_printf("Error");
	int img_width;
	int img_height;
	int x;
	int y;

	game->bg_img = mlx_xpm_file_to_image(game->mlx, "basic/bg.xpm", &img_width, &img_height);
	if (!game->bg_img)
	{
		ft_printf("Error: could not load bg.xpm\n");
		exit(1);
	}
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->bg_img, x, y);
			x += img_width;
		}
		y += img_height;
	}
	mlx_loop(game->mlx);
}

