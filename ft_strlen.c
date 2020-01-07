/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:47 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/07 15:09:26 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;
	const char		*cad;

	i = 0;
	cad = s;
	while (cad[i] != '\0')
		i++;
	return (i);
}
