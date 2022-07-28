/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibouniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:27:29 by nibouniq          #+#    #+#             */
/*   Updated: 2022/07/18 16:24:21 by nibouniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	nbr;

	nbr = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb > 0)
	{
		nbr = nb * ft_recursive_factorial(nb - 1);
	}
	return (nbr);
}
