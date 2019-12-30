/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:20:07 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/30 17:02:54 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"
int		main()
{	
	int i = 10;
	int c = -125448;
	
	char	ch = 'a';
	char	cj = 'h';

	
	
	/*PRUEBAS CON D, I*/ 
	
	printf("test 1\n");
	ft_printf("M: %d$\n", c);
	printf("O: %d$\n\n",c);//1

	printf("test 2\n");
	ft_printf("M: %d %d$\n", c, i);
	printf("O: %d %d$\n\n",c, i);//2
	
	printf("test 3\n");
	ft_printf("M: %5d$\n", c);
	printf("O: %5d$\n\n",c);//3
	
	printf("test 4\n");
	ft_printf("M: %.5d$\n", c);
	printf("O: %.5d$\n\n",c);//4

	printf("test 5\n");
	ft_printf("M: %.*d$\n",5, c);
	printf("O: %.*d$\n\n", 5,c);//5
	
	printf("test 6\n");
	ft_printf("M: %5.d$\n",c);
	printf("O: %5.d$\n\n",c);//6
	
	printf("test 7\n");
	ft_printf("M: %*.d$\n", 5,c);
	printf("O: %*.d$\n\n", 5,c);//7

	printf("test 8\n");
	ft_printf("M: %*.d$\n", 5,c);
	printf("O: %*.d$\n\n", 5,c);//8
	
	printf("test 9\n");
	ft_printf("M: %-5d$\n", c);
	printf("O: %-5d$\n\n", c);//9

	printf("test 10\n");
	ft_printf("M: %-*d$\n", 5,c);
	printf("O: %-*d$\n\n", 5,c);//10
	
	printf("test 11\n");
	ft_printf("M:%10.5d$\n", c);
	printf("O:%10.5d$\n\n", c);//11

	printf("test 12\n");
	ft_printf("M: %*.*d$\n",10,5, c);
	printf("O: %*.*d$\n\n",10,5, c);//12
	
	printf("test 13\n");
	ft_printf("M: %*.*d$\n",5,10, c);
	printf("O: %*.*d$\n\n",5,10, c);//13
	
	printf("test 14\n");
	ft_printf("M: %-*.*d$\n",10,5, c);
	printf("O: %-*.*d$\n\n",10,5, c);//14
	
	printf("test 15\n");
	ft_printf("M: %-*.*d$\n",5,10, c);
	printf("O: %-*.*d$\n\n",5,10, c);//15
	
	printf("test 16\n");
	ft_printf("M: %000007d$\n", c);
	printf("O: %000007d$\n\n", c);// 16

	printf("test 17\n");
	ft_printf("M: %.0000007d$\n", c);
	printf("O: %.0000007d$\n\n", c);// 17

	ft_printf("test 18\n");
	ft_printf("M: %-7.7d$\n", c);
	printf("O: %-7.7d$\n\n", c);// 18

	ft_printf("test 19\n");
	ft_printf("M: %9.*d$\n",10,c);
	printf("O: %9.*d$\n\n", 10,c);// 19

	
	ft_printf("TEST 1\n");
	ft_printf("M: %c$ %c$\n", ch, cj);
	printf("O: %c$ %c$\n\n",  ch, cj);

	ft_printf("TEST 2\n");
	ft_printf("M: %c$\n", ch);
	printf("O: %c$\n\n",  ch);

	ft_printf("TEST 3\n");
	ft_printf("M: %10c$ %5c$\n", ch, cj);
	printf("O: %10c$ %5c$\n\n",  ch, cj);

	ft_printf("TEST 4\n");
	ft_printf("M: %*c$ %*c$\n", 10, ch, 5, cj);
	printf("O: %*c$ %*c$\n\n", 10, ch, 5, cj);

	ft_printf("TEST 5\n");
	ft_printf("M: %-5c$\n", ch);
	printf("O: %-5c$\n\n", ch);

	ft_printf("TEST 6\n");
	ft_printf("M: %-*c$\n", 10,ch);
	printf("0: %-*c$\n\n", 10,ch);

	ft_printf("TEST 7\n");
	ft_printf("M: %-*c$ %-*c$\n", 10,ch, 5, cj);
	printf("0: %-*c$ %-*c$\n\n", 10,ch, 5, cj);
	

	return (0);
}