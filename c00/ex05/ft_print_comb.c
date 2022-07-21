/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:32:18 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/07 14:58:20 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_charascii(int a, int b, int c)

{
	char	charascii;

	charascii = a + '0';
	write(1, &charascii, 1);
	charascii = b + '0';
	write(1, &charascii, 1);
	charascii = c + '0';
	write(1, &charascii, 1);
	if (a != 7)
		write(1, ", ", 2);
}

void	ft_print_comb(void)

{
	int	c;
	int	d;
	int	u;

	c = 0;
	while (c < 10)
	{
		d = c + 1;
		while (d < 10)
		{
			u = d + 1;
			while (u < 10)
			{
				ft_charascii(c, d, u);
				u++;
			}
			d++;
		}
		c++;
	}
}
