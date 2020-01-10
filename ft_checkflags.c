/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 14:59:52 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 20:27:38 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	save_data_flags_num(t_listpf *p, const char *s)
{
	char	*temp;
	int		aux;
	int		i;

	i = 0;
	p->ns = ft_atoi(s);
	temp = ft_itoa(p->ns);
	aux = ft_strlen(temp);
	p->i += aux;
	free(temp);
	temp = NULL;
}

void	save_data_num_point(t_listpf *p, const char *s)
{
	char	*temp;
	int		aux;
	int		i;

	i = 0;
	if (s[p->i] == '*')
	{
		p->n_sp = va_arg(p->ap, int);
		p->i++;
		return ;
	}
	p->n_sp = ft_atoi(&s[p->i]);
	temp = ft_itoa(p->n_sp);
	aux = ft_strlen(temp);
	while (s[p->i] == '0')
		p->i++;
	if (p->n_sp != 0)
		p->i += aux;
	free(temp);
	temp = NULL;
}

int		isflag(const char *s)
{
	if (*s == '0' || *s == '-')
		return (1);
	return (0);
}

void	activate_flag(const char *s, t_listpf *p)
{
	if (*s == '0')
	{
		if (p->less == 0)
			p->zeros = 1;
		p->i++;
	}
	if (*s == '-')
	{
		p->less = 1;
		p->i++;
		p->zeros = 0;
	}
}

void	checkflags(const char *s, t_listpf *p)
{
	put_valors(p);
	while (isflag(&s[p->i]))
		activate_flag(&s[p->i], p);
	if (s[p->i] == '*' || ft_isdigit(s[p->i]))
	{
		if (s[p->i] == '*')
		{
			p->ns = va_arg(p->ap, int);
			if (p->ns < 0)
			{
				p->less = 1;
				p->ns *= (-1);
			}
			p->i++;
		}
		if (ft_isdigit(s[p->i]))
			save_data_flags_num(p, &s[p->i]);
	}
	if (s[p->i] == '.')
	{
		p->point = 1;
		p->i++;
		if (ft_isdigit(s[p->i]) || s[p->i] == '*')
			save_data_num_point(p, s);
	}
}
