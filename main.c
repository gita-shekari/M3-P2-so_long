/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:43:08 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/30 21:41:21 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int 	fd;
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\n"), 1);
	if (!is_map_file(argv[1]))
		return (ft_printf("Error: invalid file extension\n"), 1);
	game.row = count_lines(argv[1]);
	if (game.row == 0)
		return (ft_printf("Error: empty or unreadable file\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: failed to reopen file\n"), 1);
	if (!init_map(fd, &game))
		return (ft_printf("Error: failed to initialize map\n"), exit(0), 1);
	//so_long(&game);
	close(fd);
	return (0);
}

