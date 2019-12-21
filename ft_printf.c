/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:28:28 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/21 21:06:54 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_putnbr_ptf(int n)
{
	char i;

	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		ft_putnbr_ptf(n * (-1));
	else
	{
		if (n >= 10)
			ft_putnbr_ptf((n / 10));
		i = (n % 10) + '0';
		write(1, &i, 1);
	}
}

void parse_and_print_lessD(p_list *p)
{
	int aux;
	char *temp;
	int len;
	int realspace;

	if (p->num_space != 0)
	{
		aux = va_arg(p->ap, int);
		temp = ft_itoa(aux);
		len = ft_strlen(temp);
		free(temp);
		temp = NULL;
		realspace = p->num_space - len;
		ft_putnbr_fd(aux, 1);
		while (realspace > 0)
		{
			write(1, " ", 1);
			realspace--;
		}
	}
}

void parse_and_printD(p_list *p)
{
	int aux;
	char *temp;
	int len;
	int realspace;

	aux = va_arg(p->ap, int);
	if (p->num_space != 0 || p->num_space_point != 0)
	{
		temp = ft_itoa(aux);
		len = ft_strlen(temp);
		free(temp);
		temp = NULL;
		if (p->num_space != 0)
			realspace = p->num_space - len;
		else
			realspace = p->num_space_point - len;
		if (aux < 0)
			len--;
		while (realspace > 0)
		{
			if (p->zeros == 1 || (p->point == 1 && p->num_space == 0))
			{
				if (aux < 0)
				{
					write(1, "-", 1);
					aux *= (-1);
					realspace++;
				}
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
	else
		ft_putnbr_fd(aux, 1);	
}

void parse_and_print_2(p_list *p)
{
	int aux;
	char *temp;
	int len;
	int realspace;

	aux = va_arg(p->ap, int);
	temp = ft_itoa(aux);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	realspace = p->num_space - p->num_space_point;
	if (aux < 0)
	{
		len--;
		realspace--;
	}
	while (realspace > 0)
	{	
		write(1, " ", 1);
		realspace--;
	}
	while((p->num_space_point - len) > 0)
	{
		if (aux < 0)
		{
			write(1, "-", 1);
			aux *= (-1);
		}
		write(1, "0", 1);
		p->num_space_point--;
	}
	ft_putnbr_ptf(aux);
}

void write_and_parse(const char *s, p_list *p)
{
	if(*s == 'd' || *s == 'D')
	{
		if (p->num_space_point != 0 && (p->num_space > p->num_space_point))
			parse_and_print_2(p);
		else if (p->num_space < p->num_space_point)
		{
			p->num_space = 0;
			parse_and_printD(p);
		}
		else if (p->less == 0)
			parse_and_printD(p);
		else
			parse_and_print_lessD(p);
		p->i++;
	}
	if (*s == 's' || *s == 'S')
	{}
}

void put_valors(p_list *p)
{
	p->num_space = 0;
	p->less = 0;
	p->point = 0;
	p->width = 0;
	p->zeros = 0;
	p->len = 0;
	p->num_space_point = 0;
}
void save_data_flags_num(p_list *p, const char *s)
{
	char *temp;
	int aux;
	int i;

	i = 0; 
	p->num_space = ft_atoi(s);
	temp = ft_itoa(p->num_space);
	aux = ft_strlen(temp);
	p->i += aux;
	free(temp);
	temp = NULL;
}

void save_data_num_point(p_list *p, const char *s)
{
	char *temp;
	int aux;
	int i;

	i = 0;
	if (s[p->i] == '*')
	{
		p->num_space_point = va_arg(p->ap, int);
		p->i++;
		return ;
	}
	p->num_space_point = ft_atoi(&s[p->i]);
	temp = ft_itoa(p->num_space_point);
	aux = ft_strlen(temp);
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

void	activate_flag(const char *s, p_list *p)
{
	if (*s  == '0')
	{
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

void save_width(const char *s, p_list *p)
{
	if (*s == '*')
	{
		p->num_space = va_arg(p->ap, int);
		p->width = 1;
		p->i++;
	}
	if (ft_isdigit(*s))
		save_data_flags_num(p, s);
}

void checkflags(const char *s, p_list *p)
{
	put_valors(p);
	while (isflag(&s[p->i]))
		activate_flag(&s[p->i], p);
	if (s[p->i] == '*' || ft_isdigit(s[p->i]))
		save_width(&s[p->i], p);
	if (s[p->i] == '.')
	{
		p->point = 1;
		p->i++;
		if (ft_isdigit(s[p->i]) || s[p->i] == '*')
			save_data_num_point(p, s);
	}
}
int		ft_printf(const char *s, ...)
{
	p_list	*p;
	
	if (!(p = (p_list*)malloc(sizeof(p_list))))
		return (-1);
	va_start(p->ap, s);
	p->i = 0;
	while(s[p->i])
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
		}
	}
	free(p);
	va_end(p->ap);
	return (1);
}
