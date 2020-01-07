/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:24:04 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/07 16:10:29 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, t_listpf *p)
{
	char i;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		p->len++;
		write(fd, "2147483648", 10);
		p->len += 10;
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		p->len++;
		ft_putnbr_fd(n * (-1), fd, p);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd, p);
		i = (n % 10) + '0';
		write(fd, &i, 1);
		p->len++;
	}
}
