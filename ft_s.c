/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:24:24 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/02 20:22:41 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces(int realspace, t_listpf *p)
{
	while (realspace > 0)
	{
		write(1, " ", 1);
		p->len++;
		realspace--;
	}
}

int		calculate(t_listpf *p)
{
	int	len;

	p->string = va_arg(p->ap, char*);
	len = ft_strlen(p->string);
	if ((p->n_sp > 0 && p->ns != 0) && (p->n_sp < p->ns))
	{
		if (p->n_sp < len)
			p->realspace = p->ns - p->n_sp;
		else
			p->realspace = p->ns - len;
	}
	else
		p->realspace = p->ns - len;
	if (p->realspace < 0)
		p->realspace = 0;
	return (len);
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
	if (p->ns > 0 && p->ns > len)
		total = p->ns;
	else if (p->n_sp > 0)
		total = p->n_sp;
	else
		total = len;
	while (p->realspace != total && p->string[i] != '\0')
	{
		write(1, &p->string[i], 1);
		i++;
		p->realspace++;
	}
	p->realspace -= i;
	if (p->ns > 0 && p->less == 1)
		print_spaces(p->realspace, p);
	p->i++;
}
