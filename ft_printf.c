/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:28:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/07 16:05:57 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		numcarhex(long int n)
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
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_itoahex(int n, const char *s)
{
	long int		i;
	char			*pnt;
	unsigned int	num;

	num = (long int)n;
	i = numcarhex(num);
	if (!(pnt = malloc((i + 1) * sizeof(char))))
		return (0);
	pnt[i] = '\0';
	pnt[0] = '0';
	while (i-- > 0)
	{
		if (num % 16 < 10)
			pnt[i] = (num % 16) + '0';
		else if (num % 16 >= 10 && *s == 'x')
			pnt[i] = (num % 16) + 87;
		else if (num % 16 >= 10 && *s == 'X')
			pnt[i] = (num % 16) + 55;
		num = num / 16;
	}
	return (pnt);
}

void	ft_putnbr_ptf(int n, t_listpf *p)
{
	char i;

	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		p->len += 10;
		return ;
	}
	if (n < 0)
		ft_putnbr_ptf(n * (-1), p);
	else
	{
		if (n >= 10)
			ft_putnbr_ptf((n / 10), p);
		i = (n % 10) + '0';
		write(1, &i, 1);
		p->len++;
	}
}

void	write_and_parse(const char *s, t_listpf *p)
{
	if (*s == 'd' || *s == 'i')
		write_and_parsed(p);
	if (*s == 's')
		write_and_parse_s(p);
	if (*s ==  'c')
		write_and_parse_c(p);
	if (*s == 'x' || *s == 'X')
		write_and_parse_x(p, s);
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
}

int		ft_printf(const char *s, ...)
{
	t_listpf	*p;
	
	if (!(p = (t_listpf*)malloc(sizeof(t_listpf))))
		return (-1);
	va_start(p->ap, s);
	p->i = 0;
	p->len = 0;
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
			p->len++;
		}
	}
	free(p);
	va_end(p->ap);
	return (p->len);
}
