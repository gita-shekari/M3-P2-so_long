/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:28:22 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/02 21:30:30 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position (t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col)
		{
			if (game->map[i][j] == 'P')
			{
				game->px = i;
				game->py = j;
			}
			j++;
		}
		i++;
	}
}

void	free_game_copy(t_game *game)
{
	int	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	copy_game(t_game *temp, t_game *game)
{
	int	i;

	temp->row = game->row;
	temp->col = game->col;
	temp->px = game->px;
	temp->py = game->py;
	temp->collectibles = 0;
	temp->map = (char **)malloc(sizeof(char *)*(temp->row + 1));
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


void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'F')
		return;
	map[x][y] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}



