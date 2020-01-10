/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:49:31 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/10 20:27:34 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	calculate_u(int *realspace, unsigned long int *u, t_listpf *p)
{
	int		len;
	char	*temp;

	temp = ft_itoa(*u);
	len = ft_strlen(temp);
	free(temp);
	temp = NULL;
	if (*u == 0 && p->point == 1 && p->n_sp == 0)
		*realspace = p->ns;
	else if (len < 0)
		*realspace = 0;
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
		if (n >= 4294967296)
			n -= 4294967296;
		else if (n >= 10)
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
	long int			i;
	char				*pnt;
	unsigned long int	num;

	num = n;
	i = numcarhex(num);
	if (!(pnt = malloc((i + 1) * sizeof(char))))
		return (0);
	pnt[i] = '\0';
	pnt[0] = '0';
	if (n >= 4294967296 && *s != 'p')
		i = 1;
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
