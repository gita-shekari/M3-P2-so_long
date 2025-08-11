/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:28:22 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 19:47:55 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	free_game_copy(t_game *game)
{
	int	i;

	i = 0;
	if (!game || !game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

int	copy_game(t_game *temp, t_game *game)
{
	int	i;

	temp->row = game->row;
	temp->col = game->col;
	temp->px = game->px;
	temp->py = game->py;
	temp->collectibles = 0;
	temp->map = (char **)malloc(sizeof(char *) * (temp->row + 1));
	if (!temp->map)
		return (0);
	i = 0;
	while (i < game->row)
	{
		temp->map[i] = ft_strdup(game->map[i]);
		if (!temp->map[i])
		{
			while (--i >= 0)
				free(temp->map[i]);
			free(temp->map);
			return (0);
		}
		i++;
	}
	temp->map[i] = NULL;
	return (1);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'R')
		return ;
	map[y][x] = 'R';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}
