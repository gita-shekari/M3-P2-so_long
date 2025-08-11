/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:39:10 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 20:59:18 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# ifndef TILE_SIZE
#  define SO_LONG_H
#  define TILE_SIZE 32

#  include "libft/libft.h"
#  include <fcntl.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*bg;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		row;
	int		col;
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	int		collectibles;
	int		px;
	int		py;
	int		counter;
}	t_game;

//---------init_map-------------
int		is_map_file(char *file_name);
int		init_map(int fd, t_game *game);
int		count_lines(char *file_name);
void	free_map(t_game *game);

//--------init_map_utils--------
void	find_player_position(t_game *game);
void	free_game_copy(t_game *game);
int		copy_game(t_game *temp, t_game *game);
void	flood_fill(char **map, int x, int y);

//----------validate_map--------
int		validate_walls(t_game *game);
int		validate_elements(t_game *game);
int		validate_path(t_game *game);
int		validate_map(t_game *game);

//---------so_long---------------
int		so_long(t_game *game);
void	draw_map(t_game *game);
void	init_img(t_game *game);
void	place_img(t_game *game, int x, int y);
int		handle_close(t_game *game);
int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int right_left, int up_down);
void	free_all(t_game *game);

# endif
#endif
