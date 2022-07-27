/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-map-2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:42:53 by dapereir          #+#    #+#             */
/*   Updated: 2022/07/27 12:08:14 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_point		set_point(int x, int y);
t_square	set_square(int x, int y, int size);
int			is_obstacle(int x, int y, t_map map);
int			is_filled(int x, int y, t_map map);
int			next_obstacle_x(int ymin, int ymax, int xoffset, t_map map);

t_square	test_size(int size, t_map map)
{
	int			xi;
	int			yi;
	int			x_next;
	t_square	soluce;

	yi = 0;
	while (yi < map.height - size + 1)
	{
		xi = 0;
		x_next = 0;
		while (x_next < map.width)
		{
			x_next = next_obstacle_x(yi, yi + size - 1, xi, map);
			if (x_next - xi >= size && !is_obstacle(xi, yi, map))
			{
				soluce = set_square(xi, yi, size);
				return (soluce);
			}
			xi = x_next + 1;
		}
		yi++;
	}
	soluce.size = 0;
	return (soluce);
}

void	solve_map(t_map *map_ptr)
{
	t_map		map;
	int			size;
	t_square	soluce;

	map = *map_ptr;
	size = map.width;
	if (map.height < map.width)
		size = map.height;
	soluce.size = 0;
	while (!soluce.size && size > 0)
	{
		soluce = test_size(size, map);
		size--;
	}
	map.solution = soluce;
	*map_ptr = map;
}
