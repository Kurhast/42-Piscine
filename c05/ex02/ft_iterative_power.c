/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:25:06 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/18 17:56:11 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	powlen;
	int	nbr;

	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	if (power == 0)
		return (1);
	powlen = power;
	nbr = nb;
	while (powlen > 1)
	{
		nbr = nbr * nb;
		powlen--;
	}
	return (nbr);
}
