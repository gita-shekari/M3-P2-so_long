/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:39:03 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 21:02:25 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(t_game *game)
{
	game->counter = 1;
	game->width = TILE_SIZE * game->col;
	game->height = TILE_SIZE * game->row;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->width, game->height, "so_long");
	if (!game->win)
		return (0);
	init_img(game);
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
	mlx_hook(game->win, 17, 1L << 17, handle_close, game);
	mlx_loop(game->mlx);
	return (1);
}

void	draw_map(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			place_img(game, x, y);
			x++;
		}
		y++;
	}
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_all(game);
		exit(0);
	}
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_all(game);
	exit(0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	char	next_tile;

	next_tile = game->map[game->py + dy][game->px + dx];
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->collectibles--;
	if (next_tile == 'E')
	{
		if (game->collectibles == 0)
		{
			mlx_destroy_window(game->mlx, game->win);
			free_map(game);
			exit(0);
		}
		else
			return ;
	}
	game->map[game->py + dy][game->px + dx] = 'P';
	game->map[game->py][game->px] = '0';
	game->px = game->px + dx;
	game->py = game->py + dy;
	ft_printf("%d\n", game->counter++);
	draw_map(game);
}
