/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 17:24:24 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/30 18:53:58 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_spaces(int realspace, t_listpf *p)
{
	while (realspace > 0)
	{
		write(1, " ", 1);
		p->len++;
		realspace--;
	}
}

int		calculate(int *realspace, t_listpf *p)
{
	int len;

	p->string = va_arg(p->ap, char*);
	len = ft_strlen(p->string);
	if(p->n_sp > 0 && (p->ns > p->n_sp))
		*realspace = p->ns - p->n_sp;
	else 
		*realspace = p->ns - len;
	if (*realspace < 0)
		*realspace = 0;
	return (len);
}

void	write_and_parse_s(t_listpf *p)
{
	int realspace;
	int i;
	int total;
	int len;

	i = 0;
	realspace = 0;
	len = calculate(&realspace, p);
	if (p->ns > 0 && p->less == 0)
		print_spaces(realspace, p);
	if (p->ns < 0) 
		total = p->n_sp;
	else if (p->n_sp > 0)
		total = p->n_sp;
	else
		total = len;
	while (realspace != total && p->string[i] != '\0')
	{
		write(1, &p->string[i], 1);
		i++;
		realspace++;
	}
	p->i++;	
}