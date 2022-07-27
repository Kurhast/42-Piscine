/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:51:08 by dapereir          #+#    #+#             */
/*   Updated: 2022/07/27 12:58:14 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_square {
	t_point	start;
	int		size;
}	t_square;

typedef struct s_map {
	int			width;
	int			height;
	char		empty_c;
	char		obstacle_c;
	char		filled_c;
	t_point		*obstacles;
	int			obstacles_count;
	t_square	solution;
}	t_map;

int	is_obstacle(int x, int y, t_map map);
int	is_filled(int x, int y, t_map map);

#endif
