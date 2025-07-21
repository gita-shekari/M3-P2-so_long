/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:43:08 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/21 20:59:00 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	validate_map (int fd)
{
	char **map;
	char *line;
	int i;

	i = 0;
	map = NULL;
	line = get_next_line(fd);
	printf("%s\n" ,line);
	map[i] = line;
	printf("%s\n" ,map[i]);
	//map[i] = ft_substr(line, 0, (ft_strlen(line) - 1));
	i++;
	while (line)
	{
		printf("%s\n" ,"e");
		line = get_next_line(fd);
		map[i] = line;
		//map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		i++;
	}
	return (1);
}
int main (int argc, char **argv)
{
	int fd;

	fd = -1;
	if (argc != 2)
		return (0);
	if(is_map_file(argv[1]))
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\n"), exit(0), 1);
	if (!validate_map(fd))
		return (ft_printf("Error\n"), exit(0), 1);
	return (0);
}
