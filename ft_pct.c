/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 20:19:47 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 17:38:41 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero_pct(t_listpf *p)
{
	while (p->ns > 1)
	{
		ft_putchar_fd('0', p);
		p->ns--;
	}
}

void	print_spaces_pct(t_listpf *p)
{
	while (p->ns > 1)
	{
		ft_putchar_fd(' ', p);
		p->ns--;
	}
}

void	write_pct(t_listpf *p)
{
	p->i++;
	if (p->ns > 0 && p->less == 0 && p->zeros == 0)
		print_spaces_pct(p);
	if (p->ns > 0 && p->zeros == 1)
		print_zero_pct(p);
	ft_putchar_fd('%', p);
	if (p->ns && p->less > 0)
		print_spaces_pct(p);
}
