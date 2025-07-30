/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:39:10 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/30 21:51:40 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"


typedef struct s_game
{
	char	**map;
	size_t	row;
	size_t	col;
	void	*mlx;
	void	*win;
	void	*bg_img;
	int		width;
	int		height;
	int		collectibles;
}	t_game;

//---------init_map-------------
int		is_map_file (char *file_name);
int		init_map (int fd,t_game *game);
int		count_lines(char *file_name);
void	free_map(t_game *game);

//----------validate_map--------
int		validate_walls(t_game *game);
int		validate_elements(t_game *game);
int		validate_path(t_game *game);
int		validate_map(t_game *game);

//---------so_long---------------
void	so_long(t_game *game);

#endif
