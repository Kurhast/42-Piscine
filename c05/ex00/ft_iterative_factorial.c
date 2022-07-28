/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:09:07 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/28 07:35:39 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	nbr;

	if (nb < 0)
	{
		return (0);
	}
	i = 1;
	nbr = 1;
	while (i <= nb)
	{
			nbr = nbr * i;
			i++;
	}
	return (nbr);
}
