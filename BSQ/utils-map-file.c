/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-map-file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:13:26 by dapereir          #+#    #+#             */
/*   Updated: 2022/07/27 12:02:26 by dapereir         ###   ########.fr       */
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

char	get_next_char(int fd, char *c_ptr)
{
	if (!read(fd, c_ptr, 1))
		*c_ptr = '\0';
	return (*c_ptr);
}

int	is_first_line_data_valid(t_map map)
{
	return (
		map.height > 0
		&& map.empty_c && is_printable(map.empty_c)
		&& map.obstacle_c && is_printable(map.obstacle_c)
		&& map.filled_c && is_printable(map.filled_c)
		&& map.empty_c != map.obstacle_c
		&& map.empty_c != map.filled_c
		&& map.filled_c != map.obstacle_c
	);
}

int	scan_first_line(int fd, t_map *map_ptr)
{
	char	c;
	t_map	map;

	c = '\0';
	map.height = 0;
	get_next_char(fd, &c);
	while (c && is_numeric(c))
	{
		map.height = map.height * 10 + (c - '0');
		get_next_char(fd, &c);
	}
	map.empty_c = c;
	map.obstacle_c = get_next_char(fd, &c);
	map.filled_c = get_next_char(fd, &c);
	if (!is_first_line_data_valid(map))
		return (0);
	if (!get_next_char(fd, &c) || c != '\n')
		return (0);
	*map_ptr = map;
	return (1);
}

void	free_map_obstacles(t_map *map_ptr)
{
	free(map_ptr->obstacles);
	map_ptr->obstacles = NULL;
}

void	push_obstacle(int x, int y, t_map *map_ptr)
{
	t_map	map;
	int		i;
	t_point	*obstacles;

	map = *map_ptr;
	map.obstacles_count += 1;
	obstacles = (t_point *)malloc(sizeof(t_point) * (map.obstacles_count));
	i = 0;
	while (i < map.obstacles_count - 1)
	{
		obstacles[i] = map.obstacles[i];
		i++;
	}
	obstacles[i] = set_point(x, y);
	free_map_obstacles(map_ptr);
	map.obstacles = obstacles;
	*map_ptr = map;
}
