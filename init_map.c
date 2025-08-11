/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:50:12 by gshekari          #+#    #+#             */
/*   Updated: 2025/08/11 20:40:34 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_file(char *file_name)
{
	char	*format;

	format = ft_strrchr(file_name, '.');
	if (!format)
		return (0);
	if (ft_strncmp(format, ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

int	init_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	game->map = (char **)malloc(sizeof(char *) * (game->row + 1));
	if (!game->map)
		return (ft_printf("malloc failed"), 0);
	i = 0;
	while (i < game->row)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (game->col != 0 && game->col != (int)ft_strlen(line) - 1)
			return (free(line), 0);
		game->col = ft_strlen(line) - 1;
		game->map[i] = ft_substr(line, 0, game->col);
		if (!game->map[i])
			return (free(line), free_map(game), 0);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	if (!validate_map(game))
		return (free_map(game), 0);
	return (1);
}

int	count_lines(char *file_name)
{
	int		count;
	char	*line;
	int		fd_count;

	count = 0;
	fd_count = open(file_name, O_RDONLY);
	if (fd_count == -1)
		return (0);
	line = get_next_line(fd_count);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd_count);
	}
	free(line);
	close(fd_count);
	return (count);
}
