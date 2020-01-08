/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 20:11:51 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/08 16:53:03 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces_x(int realspace, t_listpf *p, int aux, int len)
{
	if (p->point == 1 && p->n_sp > 0 && len > p->n_sp)
	{
		realspace = p->ns - len;
		if (aux < 0)
			realspace--;
	}
	else if (p->point == 1 && p->n_sp > 0 && p->ns > p->n_sp)
	{
		realspace = p->ns - p->n_sp;
		if (aux < 0)
			realspace--;
	}
	else if (p->zeros == 1 && (p->ns > p->n_sp))
		realspace = 0;
	while (realspace > 0)
	{
		write(1, " ", 1);
		p->len++;
		realspace--;
	}
}

int		calcuate_space(t_listpf *p)
{
	int len;

	len = ft_strlen(p->aux);
	if (p->point > 0 && p->n_sp == 0)
	{
		p->realspace = p->ns;
		return (0);
	}
	else
		p->len += len;
	if (p->ns > 0 && p->n_sp == 0)
		p->realspace = p->ns - len;
	else if (p->n_sp > 0 && p->ns == 0)
		p->realspace = p->n_sp - len;
	return (len);
}

void	print_zeros(int realspace, t_listpf *p, int len)
{
	if (p->point == 1 && (p->ns < p->n_sp))
		realspace = p->n_sp - len;
	else if (p->point == 1 && (p->ns >= p->n_sp))
		realspace = p->n_sp - len;
	while (realspace > 0)
	{
		write(1, "0", 1);
		p->len++;
		realspace--;
	}
}

void	write_and_parse_x(t_listpf *p, const char *s)
{
	int len;
	int aux;

	p->i++;
	aux = va_arg(p->ap, int);
	p->aux = ft_itoahex(aux, s);
	len = calcuate_space(p);
	if (p->ns > 0 && p->less == 0 && (p->ns > p->n_sp))
		print_spaces_x(p->realspace, p, aux, len);
	if ((p->point > 0 && p->n_sp > 0) || p->zeros > 0)
		print_zeros(p->realspace, p, len);
	if (p->point > 0 && p->n_sp == 0)
	{
		if (p->ns > 0 && p->less == 1)
			print_spaces_x(p->realspace, p, aux, len);
		return ;
	}
	else
		ft_putstr_fd(p->aux, 1);
	if (p->ns > 0 && p->less > 0)
		print_spaces_x(p->realspace, p, aux, len);
}
