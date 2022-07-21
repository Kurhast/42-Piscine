/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:48:01 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/09 11:48:43 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_line1(int x)
{
	int	size;
	int	b_length;

	size = 0;
	b_length = x - 2;
	ft_putchar('A');
	if (x > 1)
	{
		while (size < b_length)
		{
			ft_putchar('B');
			size++;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_line2(int y)
{
	int	size;
	int	spc_length;

	size = 0;
	spc_length = y - 2;
	ft_putchar('B');
	if (y > 1)
	{
		while (size < spc_length)
		{
			ft_putchar(' ');
			size++;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	ft_line3(int z)
{
	int	size;
	int	b_length;

	size = 0;
	b_length = z - 2;
	ft_putchar('A');
	if (z > 1)
	{
		while (size < b_length)
		{
			ft_putchar('B');
			size++;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	nb;

	nb = 0;
	if (x >= 1 && y >= 1)
	{
		ft_line1(x);
		if (y > 1)
		{
			while (nb < y - 2)
			{
				ft_line2(x);
				nb++;
			}
			ft_line3(x);
		}
	}
}
