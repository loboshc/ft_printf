/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:02:16 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 17:37:21 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, t_listpf *p)
{
	write(1, &c, 1);
	p->len++;
}

void	ft_putchar_main(const char *s, t_listpf *p)
{
	write(1, s, 1);
	p->i++;
	p->len++;
}
