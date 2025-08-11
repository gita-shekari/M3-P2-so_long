/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 20:21:52 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 21:03:25 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.bg = mlx_xpm_file_to_image(game->mlx,
			"basic/bg.xpm", &img_width, &img_height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"basic/wall.xpm", &img_width, &img_height);
	game->img.player = mlx_xpm_file_to_image(game->mlx,
			"basic/player.xpm", &img_width, &img_height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"basic/exit.xpm", &img_width, &img_height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"basic/collectible.xpm", &img_width, &img_height);
	if (!game->img.bg || !game->img.wall || !game->img.player
		|| !game->img.exit || !game->img.collectible)
	{
		ft_printf("Error loading images\n");
		free_all(game);
		exit(1);
	}
}

void	place_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img.bg, x * TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, x * TILE_SIZE, y * TILE_SIZE);
}
