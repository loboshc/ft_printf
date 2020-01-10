/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:04:38 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 20:23:24 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numcar(long int n)
{
	long int i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long long n)
{
	long int	i;
	char		*pnt;
	long long	num;

	num = n;
	i = numcar(num);
	if (!(pnt = malloc((i + 1) * sizeof(char))))
		return (0);
	pnt[i] = '\0';
	pnt[0] = '0';
	if (num < 0)
		num *= -1;
	while (i-- > 0)
	{
		pnt[i] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		pnt[0] = '-';
	return (pnt);
}
