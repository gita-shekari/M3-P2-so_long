/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:43:08 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 19:54:01 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (i < game->row)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	free_all(t_game *game)
{
	free_map(game);
	if (game->img.bg)
		mlx_destroy_image(game->mlx, game->img.bg);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\n"), 1);
	if (!is_map_file(argv[1]))
		return (ft_printf("Error\n"), 1);
	game.col = 0;
	game.row = count_lines(argv[1]);
	if (!game.row || game.row == 0)
		return (ft_printf("Error\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), 1);
	if (!init_map(fd, &game))
		return (ft_printf("Error: failed\n"), free_all(&game), 1);
	if (!so_long(&game))
		return (ft_printf("Error: failed\n"), free_all(&game), 1);
	free_all(&game);
	close(fd);
	return (0);
}
