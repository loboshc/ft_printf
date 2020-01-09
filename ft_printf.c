/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:28:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/09 18:23:13 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	calculate_u(int *realspace, unsigned long int *u, t_listpf *p)
{
	int 	len;
	char	*temp;
	
	temp = ft_itoa(*u);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;

	if (*u == 0 && p->point == 1 && p->n_sp == 0)
		*realspace = p->ns;
	else if (p->ns != 0)
		*realspace = p->ns - len;
	else
		*realspace = p->n_sp - len;
}

void	ft_putnbr_ptfu(unsigned long int n, t_listpf *p)
{
	char i;

	if (n < 0)
		ft_putnbr_ptfu(n * (-1), p);
	else
	{
		if (n >= 10)
			ft_putnbr_ptfu((n / 10), p);
		i = (n % 10) + '0';
		write(1, &i, 1);
		p->len++;
	}
}

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

char	*ft_itoahex(unsigned long int n, const char *s)
{
	long int		i;
	char			*pnt;
	unsigned long int	num;

	num = n;
	i = numcarhex(num);
	if (!(pnt = malloc((i + 1) * sizeof(char))))
		return (0);
	pnt[i] = '\0';
	pnt[0] = '0';
	while (i-- > 0)
	{
		if (num % 16 < 10)
			pnt[i] = (num % 16) + '0';
		else if (num % 16 >= 10 && *s == 'X')
			pnt[i] = (num % 16) + 55;
		else if (num % 16 >= 10)
			pnt[i] = (num % 16) + 87;
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
	if (*s == 'd' || *s == 'i' || *s == 'u')
		write_and_parsed(p, s);
	if (*s == 's')
		write_and_parse_s(p);
	if (*s ==  'c')
		write_and_parse_c(p);
	if (*s == 'x' || *s == 'X' || *s == 'p')
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
