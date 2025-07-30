/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:50:05 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/30 21:56:29 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int validate_walls(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->row)
	{
		size_t j = 0;
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
	size_t	i;
	size_t	j;
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
	if (player_count != 1 || game->collectibles < 1 || exit_count != 1)
		return (0);
	return (1);
}

int	validate_path(t_game *game)
{
	if(game)
		return (1);
	return (0);
}

// find player position (px, py)
// copy map to temp_map
// flood_fill(temp_map, px, py)
// for each tile in map:
//     if tile == C and temp_map tile != visited:
//         return false
//     if tile == E and temp_map tile == visited:
//         exit_found = true
// if exit_found == false:
//     return false
// return true

int validate_map(t_game *game)
{
	if (!validate_walls(game))
		return (0);
	if (!validate_elements(game))
		return (0);
	if (!validate_path(game))
		return (0);
	return (1);
}
