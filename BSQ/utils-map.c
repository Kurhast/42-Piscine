/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:42:53 by dapereir          #+#    #+#             */
/*   Updated: 2022/07/27 12:08:32 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_point	set_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_square	set_square(int x, int y, int size)
{
	t_square	square;

	square.start = set_point(x, y);
	square.size = size;
	return (square);
}

int	is_obstacle(int x, int y, t_map map)
{
	int	i;

	i = 0;
	while (i < map.obstacles_count)
	{
		if (map.obstacles[i].x == x && map.obstacles[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

int	is_filled(int x, int y, t_map map)
{
	return (
		map.solution.size > 0
		&& x >= map.solution.start.x
		&& x <= map.solution.start.x + map.solution.size - 1
		&& y >= map.solution.start.y
		&& y <= map.solution.start.y + map.solution.size - 1
	);
}

int	next_obstacle_x(int ymin, int ymax, int xoffset, t_map map)
{
	int		next_x;
	int		i;
	t_point	obs;

	next_x = map.width;
	i = 0;
	while (i < map.obstacles_count)
	{
		obs = map.obstacles[i];
		if (obs.y >= ymin && obs.y <= ymax && obs.x > xoffset && obs.x < next_x)
			next_x = obs.x;
		i++;
	}
	return (next_x);
}
