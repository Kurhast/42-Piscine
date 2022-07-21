/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:53:37 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/09 11:54:30 by nibouniq         ###   ########lyon.fr   */
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
	ft_putchar('o');
	if (x > 1)
	{
		while (size < b_length)
		{
			ft_putchar('-');
			size++;
		}
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	ft_line2(int y)
{
	int	size;
	int	spc_length;

	size = 0;
	spc_length = y - 2;
	ft_putchar('|');
	if (y > 1)
	{
		while (size < spc_length)
		{
			ft_putchar(' ');
			size++;
		}
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	ft_line3(int z)
{
	int	size;
	int	b_length;

	size = 0;
	b_length = z - 2;
	ft_putchar('o');
	if (z > 1)
	{
		while (size < b_length)
		{
			ft_putchar('-');
			size++;
		}
		ft_putchar('o');
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
