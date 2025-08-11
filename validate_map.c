/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:50:05 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 19:06:50 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_walls(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && game->map[i][j] != 'P' && game->map[i][j] != 'C' && game->map[i][j] != 'E')
				return (0);
			if ((i == 0 || i == game->row - 1) && game->map[i][j] != '1')
				return (0);
			if ((j == 0 || j == game->col - 1) && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate_elements(t_game *game)
{
	int	i;
	int	j;
	int		player_count;
	int		exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	game->collectibles = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col)
		{
			if (game->map[i][j] == 'P')
				player_count++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			else if (game->map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1 && game->collectibles >= 1 && exit_count == 1);
}

int	validate_path(t_game *game)
{
	t_game	temp;
	int		i;
	int		j;
	int		reached_c;
	int		reached_e;

	reached_c = 0;
	reached_e = 0;
	if (!copy_game(&temp, game))
		return (0);
	flood_fill(temp.map, temp.py, temp.px);
	i = 0;
	while (i < temp.row)
	{
		j = 0;
		while (j < temp.col)
		{
			if (game->map[i][j] == 'C' && temp.map[i][j] == 'R')
				reached_c++;
			if (game->map[i][j] == 'E' && temp.map[i][j] == 'R')
				reached_e = 1;
			j++;
		}
		i++;
	}
	free_game_copy(&temp);
	return (reached_c == game->collectibles && reached_e);
}

int validate_map(t_game *game)
{
	if (!validate_walls(game))
		return (0);
	if (!validate_elements(game))
		return (0);
	find_player_position(game);
	if (!validate_path(game))
		return (0);
	return (1);
}
