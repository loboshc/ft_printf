/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:20:07 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/21 21:06:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"
int		main()
{	
	int i = 10;
	int c = 98;


	ft_printf("M: %d\n", c);
	printf("O: %d\n\n",c);//1
	ft_printf("M: %d %d\n", c, i);
	printf("O: %d %d\n\n",c, i);//2
	
	ft_printf("M: %5d\n", c);
	printf("O: %5d\n\n",c);//3
	
	ft_printf("M: %.5d\n", c);
	printf("O: %.5d\n\n",c);//4
	
	ft_printf("M: %.*d\n",5, c);
	printf("O: %.*d\n\n", 5,c);//5
	ft_printf("M: %5.d\n",c);
	printf("O: %5.d\n\n",c);//6
	ft_printf("M: %*.d\n", 5,c);
	printf("O: %*.d\n\n", 5,c);//7
	ft_printf("M: %*.d\n", 5,c);
	printf("O: %*.d\n\n", 5,c);//8
	ft_printf("M: %-5d\n", c);
	printf("O: %-5d\n\n", c);//9
	ft_printf("M: %-*d\n", 5,c);
	printf("O: %-*d\n\n", 5,c);//10
	ft_printf("M: %10.5d\n", c);
	printf("O: %10.5d\n\n", c);//11
	ft_printf("M: %*.*d\n",10,5, c);
	printf("O: %*.*d\n\n",10,5, c);//12

	return (0);
}