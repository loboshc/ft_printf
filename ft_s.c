/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:24:24 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/15 16:28:13 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(int realspace, t_listpf *p)
{
	if (p->zeros == 1)
	{
		while (realspace > 0)
		{
			write(1, "0", 1);
			p->len++;
			realspace--;
		}
	}
	else
	{
		while (realspace > 0)
		{
			write(1, " ", 1);
			p->len++;
			realspace--;
		}
	}
}

int		calculate(t_listpf *p)
{
	int	len;

	p->aux = va_arg(p->ap, char*);
	if (p->aux == NULL)
		p->aux = "(null)";
	len = ft_strlen(p->aux);
	if ((p->n_sp > 0 && p->ns != 0) && (p->n_sp < p->ns))
	{
		if (p->n_sp < len)
			p->realspace = p->ns - p->n_sp;
		else
			p->realspace = p->ns - len;
	}
	else if (p->point > 0 && (p->ns > p->n_sp))
		p->realspace = p->ns;
	else
		p->realspace = p->ns - len;
	if (p->realspace < 0)
		p->realspace = 0;
	return (len);
}

void	calculate_total(t_listpf *p, int *total, int *len)
{
	if (p->ns > 0 && p->ns > *len && p->n_sp >= 0)
		*total = p->ns;
	else if (p->n_sp > 0 && p->ns > p->n_sp)
		*total = p->ns;
	else if (p->point > 0 && p->n_sp >= 0 && p->ns > p->n_sp)
		*total = p->ns;
	else if (p->n_sp > 0)
		*total = p->n_sp;
	else if (p->point == 1 && p->n_sp == 0)
		*total = 0;
	else
		*total = *len;
}

void	write_and_parse_s(t_listpf *p)
{
	int i;
	int total;
	int len;

	i = 0;
	len = calculate(p);
	if (p->ns > 0 && p->less == 0)
		print_spaces(p->realspace, p);
	calculate_total(p, &total, &len);
	while (p->realspace != total && p->aux[i] != '\0')
	{
		write(1, &p->aux[i], 1);
		p->len++;
		i++;
		p->realspace++;
	}
	if (p->n_sp >= 0)
		p->realspace -= i;
	else
		p->realspace -= i + len;
	if (p->ns > 0 && p->less == 1)
		print_spaces(p->realspace, p);
	p->i++;
}
