/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map->c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:44:17 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/30 14:58:22 by gshekari         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int i;

	i = 0;
	while(i < game->row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	is_map_file(char *file_name)
{
	char	*format;

	format = ft_strrchr(file_name, '.');
	if (!format)
		return (ft_printf("Error\n"), exit(0), 1);
	if (ft_strncmp (format, ".ber", 4) == 0)
		return (1);
	else
		return (ft_printf("Error\n"), exit(0), 1);
	return (0);
}

int init_map(int fd, t_game *game)
{
	char	*line;
	int		i;

	game->col = 0;
	game->map = (char **)malloc(sizeof(char *)*(game->row + 1));
	if (!game->map)
		return (perror("malloc failed"), 0);
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
			return (free(line),free_map(game), 0);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	if(!validate_map(game))
		return (free_map(game), 0);
	return (1);
}

int count_lines(char *file_name)
{
	int count = 0;
	char *line;
	int fd_count;

	fd_count = open(file_name, O_RDONLY);
	if (fd_count == -1)
		return (ft_printf("Error: cannot open file\n"), exit(1), 0);
	while ((line = get_next_line(fd_count)))
	{
		free(line);
		count++;
	}
	close(fd_count);
	return (count);
}
