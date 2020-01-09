/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:20:07 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/09 18:16:33 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{	
	/*
	unsigned int i = -98989;
	int c = -125448;
	
	char	ch = 'a';
	char	cj = 'h';

	char *s = "Hola";

	//PRUEBAS CON D, I
	
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

	//PRUEBA CON C
	
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


	//TEST DE S
	
	
	ft_printf("TEST 1\n");
	ft_printf("M: %s$\n", s);
	printf("O: %s$\n\n", s);
	
	ft_printf("TEST 2\n");
	ft_printf("M: %5s$\n", s);
	printf("O: %5s$\n\n", s);

	ft_printf("TEST 3\n");
	ft_printf("M: %*s$\n", 5,s);
	printf("O: %*s$\n\n", 5,s);

	ft_printf("TEST 4\n");
	ft_printf("M: %.1s$\n", s);
	printf("O: %.1s$\n\n", s);

	ft_printf("TEST 4.1\n");
	ft_printf("M: %.2s$\n", s);
	printf("O: %.2s$\n\n", s);


	ft_printf("TEST 5\n");
	ft_printf("M: %.17s$\n", s);
	printf("O: %.17s$\n\n", s);

	ft_printf("TEST 6\n");
	ft_printf("M: %18.17s$\n", s);
	printf("O: %18.17s$\n\n", s);

	ft_printf("TEST 7\n");
	ft_printf("M: %17.18s$\n", s);
	printf("O: %17.18s$\n\n", s);

	ft_printf("TEST 8\n");
	ft_printf("M: %-15s$\n", s);
	printf("O: %-15s$\n\n", s);

	ft_printf("TEST 9\n");
	ft_printf("M: %-1s$\n", s);
	printf("O: %-1s$\n\n", s);

	ft_printf("TEST 10\n");
	ft_printf("M: %-*s$\n", 5,s);
	printf("O: %-*s$\n\n", 5,s);

	ft_printf("TEST 11\n");
	ft_printf("M: %-*s$\n", 4,s);
	printf("O: %-*s$\n\n", 4,s);

	ft_printf("TEST 12\n");
	ft_printf("M: %-18.17s$\n", s);
	printf("O: %-18.17s$\n\n", s);

	ft_printf("TEST 13\n");
	ft_printf("M: %-*.*s$\n",18, 17, s);
	printf("O: %-*.*s$\n\n", 18, 17, s);
	
	ft_printf("TEST 14\n");
	ft_printf("M: %-*.*s$\n",18, 1, s);
	printf("O: %-*.*s$\n\n", 18, 1, s);

	ft_printf("TEST 15\n");
	ft_printf("M: %*.*s$\n",18, 17, s);
	printf("O: %*.*s$\n\n", 18, 17, s);

	ft_printf("TEST 16\n");
	ft_printf("M: %*.*s$\n",18, 1, s);
	printf("O: %*.*s$\n\n", 18, 1, s);

	ft_printf("TEST 17\n");
	ft_printf("M: %*.*s$\n",18, 3, s);
	printf("O: %*.*s$\n\n", 18, 3, s);

	ft_printf("TEST 18\n");
	ft_printf("M: %-*.*s$\n",18, 19, s);
	printf("O: %-*.*s$\n\n", 18, 19, s);

	ft_printf("TEST 18\n");
	ft_printf("M: %-*.*s$\n",	18, 19, s);
	printf("O: %-*.*s$\n\n", 18, 19, s);


	//TEST DE Xx

	
	ft_printf("TEST 1\n");
	ft_printf("M: %x$\n", i);
	printf("O: %x$\n\n", i);

	ft_printf("TEST 2\n");
	ft_printf("M: %x$\n", i);
	printf("0: %x$\n\n", i);

	ft_printf("TEST 3\n");
	ft_printf("M: %*x$\n",5 , i);
	printf("O: %*x$\n\n", 5, i);

	ft_printf("TEST 4\n");
	ft_printf("M: %-x$\n", i);
	printf("O: %-x$\n\n",i);

	ft_printf("TEST 5\n");
	ft_printf("M: %-5x$\n", i);
	printf("O: %-5x$\n\n",i);

	ft_printf("TEST 6\n");
	ft_printf("M: %-*x$\n", 5,i);
	printf("O: %-*x$\n\n", 5,i);

	ft_printf("TEST 7\n");
	ft_printf("M: %.7x$\n",i);
	printf("O: %.7x$\n\n",i);

	ft_printf("TEST 8\n");
	ft_printf("M: %.*x$\n", 7,i);
	printf("O: %.*x$\n\n", 7,i);

	ft_printf("TEST 9\n");
	ft_printf("M: %-.7x$\n",i);
	printf("O: %-.7x$\n\n",i);

	ft_printf("TEST 10\n");
	ft_printf("M: %-.*x$\n", 5,i);
	printf("O: %-.*x$\n\n", 5,i);

	ft_printf("TEST 11\n");
	ft_printf("M: %10.7x$\n",i);
	printf("O: %10.7x$\n\n",i);

	ft_printf("TEST 12\n");
	printf("M: %*.*x$\n", 10, 7,i);
	printf("O: %*.*x$\n\n", 10, 7,i);

	ft_printf("TEST 13\n");
	ft_printf("M: %-10.7x$\n", i);
	printf("O: %-10.7x$\n\n", i);

	ft_printf("TEST 14\n");
	ft_printf("M: %-*.*x$\n", 10, 7, i);
	printf("O: %-*.*x$\n\n", 10, 7, i);

	ft_printf("TEST 15\n");
	ft_printf("M: %5.x$\n", i);
	printf("O: %5.x$\n\n",i);

	ft_printf("TEST 16\n");
	ft_printf("M: %5.5x$\n", i);
	printf("O: %5.5x$\n\n",i);

	ft_printf("TEST 17\n");
	ft_printf("M: %-.5x$\n", i);
	printf("O: %-.5x$\n\n",i);
	
	ft_printf("TEST 18\n");
	ft_printf("M: %X$\n", i);
	printf("O: %X$\n\n", i);

	ft_printf("TEST 19\n");
	ft_printf("M: %X$\n", i);
	printf("0: %X$\n\n", i);

	ft_printf("TEST 20\n");
	ft_printf("M: %*X$\n",5 , i);
	printf("O: %*X$\n\n", 5, i);

	ft_printf("TEST 21\n");
	ft_printf("M: %-X$\n", i);
	printf("O: %-X$\n\n",i);

	ft_printf("TEST 22\n");
	ft_printf("M: %-5X$\n", i);
	printf("O: %-5X$\n\n",i);

	ft_printf("TEST 23\n");
	ft_printf("M: %-*X$\n", 5,i);
	printf("O: %-*X$\n\n", 5,i);

	ft_printf("TEST 24\n");
	ft_printf("M: %.7X$\n",i);
	printf("O: %.7X$\n\n",i);

	ft_printf("TEST 25\n");
	ft_printf("M: %.*X$\n", 7,i);
	printf("O: %.*X$\n\n", 7,i);

	ft_printf("TEST 26\n");
	ft_printf("M: %-.7X$\n",i);
	printf("O: %-.7X$\n\n",i);

	ft_printf("TEST 27\n");
	ft_printf("M: %-.*X$\n", 5,i);
	printf("O: %-.*X$\n\n", 5,i);

	ft_printf("TEST 28\n");
	ft_printf("M: %10.7X$\n",i);
	printf("O: %10.7X$\n\n",i);

	ft_printf("TEST 29\n");
	printf("M: %*.*X$\n", 10, 7,i);
	printf("O: %*.*X$\n\n", 10, 7,i);

	ft_printf("TEST 30\n");
	ft_printf("M: %-10.7X$\n", i);
	printf("O: %-10.7X$\n\n", i);

	ft_printf("TEST 31\n");
	ft_printf("M: %-*.*X$\n", 10, 7, i);
	printf("O: %-*.*X$\n\n", 10, 7, i);

	ft_printf("TEST 32\n");
	ft_printf("M: %5.X$\n", i);
	printf("O: %5.X$\n\n",i);

	ft_printf("TEST 33\n");
	ft_printf("M: %5.5X$\n", i);
	printf("O: %5.5X$\n\n",i);

	ft_printf("TEST 34\n");
	ft_printf("M: %-.5X$\n", i);
	printf("O: %-.5X$\n\n",i);
	*/


	ft_printf("M: %9.2p$\n", 1234);
	printf("O: %9.2p$", 1234);



	return (0);
}