/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 15:07:01 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/02 16:53:52 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(t_listpf *p)
{
	while (p->ns > 1)
	{
		write(1, " ", 1);
		p->len++;
		p->ns--;
	}
}

void	write_and_parse_c(t_listpf *p)
{
	char c;

	c = (char)va_arg(p->ap, int);
	if (p->less == 0 && p->ns > 0)
		print_space(p);
	write(1, &c, 1);
	p->len++;
	p->i++;
	if (p->less > 0 && p->ns > 0)
		print_space(p);
}
