/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:43:08 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/27 19:26:49 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int fd;
	int count;

	if (argc != 2)
		return (ft_printf("Error\n"), 1);
	if (!is_map_file(argv[1]))
		return (ft_printf("Error: invalid file extension\n"), 1);
	count = count_lines(argv[1]);
	if (count == 0)
		return (ft_printf("Error: empty or unreadable file\n"), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error: failed to reopen file\n"), 1);
	if (!init_map(fd, count))
		return (ft_printf("Error: failed to initialize map\n"), 1);
	close(fd);
	return (0);
}

