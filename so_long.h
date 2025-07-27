/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gshekari <gshekari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:39:10 by gshekari          #+#    #+#             */
/*   Updated: 2025/07/27 19:54:04 by gshekari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>


//---------init_map-------------
int	is_map_file (char *file_name);
int init_map (int fd, int count);
int count_lines(char *file_name);
int	validate_map(char **map, size_t row,  size_t col);
void free_map(char **map);

#endif
