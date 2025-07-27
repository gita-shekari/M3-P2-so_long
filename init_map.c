/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:44:17 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/27 19:50:29 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
int	validate_map(char **map, size_t row, size_t col)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if(map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E')
				return (0);
			if (map[0][j] != '1' || map[row-1][j] != '1')
				return (0);
			j++;
		}
		if (map[i][0] != '1' || map[i][col-1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_file (char *file_name)
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

int init_map(int fd, int count)
{
	char **map;
	char *line;
	int i;
	size_t line_size;

	line_size = 0;
	map = (char **)malloc(sizeof(char *)*(count));
	if (!map)
		return (perror("malloc failed"), 0);
	i = 0;
	while (i < count)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (line_size != 0 && line_size != ft_strlen(line) - 1)
			return (free(line), 0);
		line_size = ft_strlen(line) - 1;
		map[i] = ft_substr(line, 0, line_size);
		if (!map[i])
			return (free(line), 0);
		free(line);
		i++;
	}
	if(!validate_map(map, count, line_size))
		return (free(map), 0);
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
