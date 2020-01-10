/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:28:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 20:27:36 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_del(char *temp, t_listpf *p, int len)
{
	free(temp);
	temp = NULL;
	p->realspace = p->ns - len;
}

void	write_and_parse(const char *s, t_listpf *p)
{
	if (*s == 'd' || *s == 'i' || *s == 'u')
		write_and_parsed(p, s);
	if (*s == 's')
		write_and_parse_s(p);
	if (*s == 'c')
		write_and_parse_c(p);
	if (*s == 'x' || *s == 'X' || *s == 'p')
	{
		write_and_parse_x(p, s);
		if (p->aux != NULL)
		{
			free(p->aux);
			p->aux = NULL;
		}
	}
	if (*s == '%')
		write_pct(p);
}

void	put_valors(t_listpf *p)
{
	p->ns = 0;
	p->less = 0;
	p->point = 0;
	p->width = 0;
	p->zeros = 0;
	p->n_sp = 0;
	p->realspace = 0;
	p->aux = NULL;
	p->i++;
}

int		ft_printf(const char *s, ...)
{
	t_listpf	*p;
	int			aux;

	if (!(p = (t_listpf*)malloc(sizeof(t_listpf))))
		return (-1);
	va_start(p->ap, s);
	p->i = 0;
	p->len = 0;
	aux = 0;
	while (s[p->i])
	{
		if (s[p->i] == '%')
		{
			checkflags(s, p);
			write_and_parse(&s[p->i], p);
		}
		else
			ft_putchar_main(&s[p->i], p);
	}
	va_end(p->ap);
	aux = p->len;
	free(p);
	return (aux);
}
