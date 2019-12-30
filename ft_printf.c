/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:28:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/30 14:48:21 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_putnbr_ptf(int n)
{
	char i;

	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		ft_putnbr_ptf(n * (-1));
	else
	{
		if (n >= 10)
			ft_putnbr_ptf((n / 10));
		i = (n % 10) + '0';
		write(1, &i, 1);
	}
}

void	write_and_parse(const char *s, t_listpf *p)
{
	if (*s == 'd' || *s == 'i')
		write_and_parsed(p);
	if (*s == 's' || *s == 'S')
	{}
}

void	put_valors(t_listpf *p)
{
	p->ns = 0;
	p->less = 0;
	p->point = 0;
	p->width = 0;
	p->zeros = 0;
	p->len = 0;
	p->n_sp = 0;
}

int		ft_printf(const char *s, ...)
{
	t_listpf	*p;
	
	if (!(p = (t_listpf*)malloc(sizeof(t_listpf))))
		return (-1);
	va_start(p->ap, s);
	p->i = 0;
	while (s[p->i])
	{
		if (s[p->i] == '%')
		{	
			p->i++;
			checkflags(s, p); // funcion para manejar las flags
			write_and_parse(&s[p->i], p); // la cadena apunta ya a al tipo que tiene que parsear por eso la paso por el parametro 
		}
		else
		{
			write(1, &s[p->i], 1);
			p->i++;
		}
	}
	free(p);
	va_end(p->ap);
	return (1);
}
