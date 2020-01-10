/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:43:15 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 20:27:40 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_and_print_lessd(t_listpf *p, const char *s)
{
	long long	aux;
	char		*temp;
	int			len;

	if (*s == 'u')
		aux = va_arg(p->ap, long long);
	else
		aux = va_arg(p->ap, int);
	if (p->ns != 0)
	{
		temp = ft_itoa(aux);
		len = ft_strlen(temp);
		ft_del(temp, p, len);
		if (p->point == 1 && p->n_sp == 0)
			p->realspace = p->ns;
		else
			ft_putnbr_fd(aux, 1, p);
		while (p->realspace > 0)
		{
			ft_putchar_fd(' ', p);
			p->realspace--;
		}
	}
	else
		ft_putnbr_fd(aux, 1, p);
}

void	calculated(t_listpf *p)
{
	int		len;
	char	*temp;

	temp = ft_itoa(p->intaux);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	if (p->intaux < 0 && p->ns == 0)
		len--;
	if (p->intaux == 0 && p->point == 1 && p->n_sp == 0)
		p->realspace = p->ns;
	else if (p->ns != 0)
		p->realspace = p->ns - len;
	else
		p->realspace = p->n_sp - len;
}

void	ft_negative(t_listpf *p)
{
	write(1, "-", 1);
	p->len++;
	p->intaux *= (-1);
}

void	parse_and_printd(t_listpf *p, const char *s)
{
	if (*s == 'u')
	{
		parse_and_print_u(p);
		return ;
	}
	p->intaux = va_arg(p->ap, int);
	calculated(p);
	while (p->realspace-- > 0)
	{
		if (p->zeros == 1 || (p->point == 1 && p->ns == 0))
		{
			if (p->intaux < 0)
				ft_negative(p);
			ft_putchar_fd('0', p);
		}
		else
			ft_putchar_fd(' ', p);
	}
	if (p->intaux < 0)
		ft_putchar_fd('-', p);
	if (p->point == 1 && p->n_sp == 0)
		return ;
	else
		ft_putnbr_ptf(p->intaux, p);
}

void	parse_and_print_u(t_listpf *p)
{
	int					realspace;
	unsigned long int	u;

	u = va_arg(p->ap, unsigned long int);
	calculate_u(&realspace, &u, p);
	while (realspace > 0)
	{
		if (p->zeros == 1 || (p->point == 1 && p->ns == 0))
			ft_putchar_fd('0', p);
		else
			ft_putchar_fd(' ', p);
		realspace--;
	}
	if (p->point == 1 && p->n_sp == 0)
		return ;
	else
		ft_putnbr_ptfu(u, p);
}
