/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 15:43:15 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/30 14:48:24 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_and_print_lessd(t_listpf *p)
{
	int		aux;
	char	*temp;
	int		len;
	int		realspace;

	if (p->ns != 0)
	{
		aux = va_arg(p->ap, int);
		temp = ft_itoa(aux);
		len = ft_strlen(temp);
		free(temp);
		temp = NULL;
		realspace = p->ns - len;
		ft_putnbr_fd(aux, 1);
		while (realspace > 0)
		{
			write(1, " ", 1);
			realspace--;
		}
	}
}

void	calculated(int *realspace, char *temp, int *aux, t_listpf *p)
{
	int len;

	temp = ft_itoa(*aux);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	if (*aux < 0 && p->ns == 0)
		len--;
	if (p->ns != 0)
		*realspace =  p->ns - len;
	else
		*realspace = p->n_sp - len;
}

void	ft_negative(int *aux)
{
	write(1, "-", 1);
	*aux *= (-1);
}

void	parse_and_printd(t_listpf *p)
{
	int		aux;
	char	*temp;
	int		realspace;

	temp = NULL;
	aux = va_arg(p->ap, int);
	calculated(&realspace, temp, &aux, p);
	while (realspace > 0)
	{
		if (p->zeros == 1 || (p->point == 1 && p->ns == 0))
		{
			if (aux < 0)
				ft_negative(&aux);
			write(1, "0", 1);
		}
		else
			write(1, " ", 1);
		realspace--;
	}
	if (aux < 0)
		write(1, "-", 1);
	ft_putnbr_ptf(aux);
}
