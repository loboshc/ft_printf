/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 16:10:36 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/30 14:48:22 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print2(t_listpf *p, int *realspace, int *aux, int *len)
{
	while (*realspace > 0)
	{
		write(1, " ", 1);
		(*realspace)--;
	}
	if (*aux < 0)
	{
		write(1, "-", 1);
		*aux *= (-1);
	}
	while ((p->n_sp - *len) > 0)
	{
		write(1, "0", 1);
		p->n_sp--;
	}
}

void	parse_and_print_2(t_listpf *p)
{
	int		aux;
	char	*temp;
	int		len;
	int		realspace;

	aux = va_arg(p->ap, int);
	temp = ft_itoa(aux);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	if (len > p->n_sp)
		realspace = (aux < 0) ? (p->ns - len) + 1 : (p->ns - len);
	else
		realspace = p->ns - p->n_sp;
	if (aux < 0)
	{
		len--;
		realspace--;
	}
	print2(p, &realspace, &aux, &len);
	ft_putnbr_ptf(aux);
}

void	print3(t_listpf *p, int *aux, int *len)
{
	if (*aux < 0)
	{
		write(1, "-", 1);
		*aux *= (-1);
	}
	while ((p->n_sp - *len) > 0)
	{
		write(1, "0", 1);
		p->n_sp--;
	}
	ft_putnbr_ptf(*aux);
}

void	parse_and_print_3(t_listpf *p)
{
	int		aux;
	char	*temp;
	int		len;
	int		realspace;

	aux = va_arg(p->ap, int);
	temp = ft_itoa(aux);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	if (len > p->n_sp)
		realspace = (aux < 0) ? (p->ns - len) + 1 : (p->ns - len);
	else
		realspace = p->ns - p->n_sp;
	if (aux < 0)
	{
		len--;
		realspace--;
	}
	print3(p, &aux, &len);
	while (realspace > 0)
	{
		write(1, " ", 1);
		realspace--;
	}
}

void	write_and_parsed(t_listpf *p)
{
	if (p->n_sp != 0 && (p->ns >= p->n_sp) && p->less == 0)
		parse_and_print_2(p);
	else if (p->ns < p->n_sp)
	{
		p->ns = 0;
		parse_and_printd(p);
	}
	else if (p->less == 1 && p->n_sp == 0)
		parse_and_print_lessd(p);
	else if (p->ns == 0 || p->n_sp == 0)
		parse_and_printd(p);
	else if (p->less == 1 && (p->ns >= p->n_sp))
		parse_and_print_3(p);
	p->i++;
}
