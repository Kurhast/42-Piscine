/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-map-file-2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:13:26 by dapereir          #+#    #+#             */
/*   Updated: 2022/07/27 12:09:42 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_map.h"

int		is_numeric(char c);
int		is_printable(char c);
void	solve_map(t_map *map_ptr);
t_point	set_point(int x, int y);

char	get_next_char(int fd, char *c_ptr);
int		is_first_line_data_valid(t_map map);
int		scan_first_line(int fd, t_map *map_ptr);
void	free_map_obstacles(t_map *map_ptr);
void	push_obstacle(int x, int y, t_map *map_ptr);

int	scan_map_line(int fd, t_map *map_ptr, int y)
{
	char	c;
	int		x;
	t_map	map;

	map = *map_ptr;
	c = '\0';
	x = 0;
	while (get_next_char(fd, &c) != '\n')
	{
		if (c != map.empty_c && c != map.obstacle_c)
			return (0);
		if (c == map.obstacle_c)
			push_obstacle(x, y, &map);
		x++;
	}
	if (x == 0 || (map.width > 0 && map.width != x))
		return (0);
	else
		map.width = x;
	*map_ptr = map;
	return (1);
}

int	scan_map_lines(int fd, t_map *map_ptr)
{
	int		y;
	t_map	map;
	char	c;

	map = *map_ptr;
	map.obstacles = NULL;
	map.obstacles_count = 0;
	y = 0;
	while (y < map.height)
	{
		if (!scan_map_line(fd, &map, y))
			return (0);
		y++;
	}
	if (get_next_char(fd, &c))
		return (0);
	*map_ptr = map;
	return (1);
}

void	write_map(int fd, t_map map)
{
	int	x;
	int	y;

	if (fd < 0)
		return ;
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			if (is_filled(x, y, map))
				write(fd, &(map.filled_c), 1);
			else if (is_obstacle(x, y, map))
				write(fd, &(map.obstacle_c), 1);
			else
				write(fd, &(map.empty_c), 1);
			x++;
		}
		write(fd, "\n", 1);
		y++;
	}
}

int	process_map_file(char *filename)
{
	int		fd;
	t_map	map;

	fd = 0;
	if (filename)
		fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!scan_first_line(fd, &map))
		return (0);
	if (!scan_map_lines(fd, &map))
		return (0);
	if (filename && close(fd) == -1)
		return (0);
	solve_map(&map);
	write_map(1, map);
	free_map_obstacles(&map);
	return (1);
}
