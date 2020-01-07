/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:25:16 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/07 16:09:22 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct	s_listpf
{
	char *aux; // aux
	va_list ap;
	int zeros; // indicador para saber si tengo que rellenar con ceros o no;
	int less; // para el flag '-'. 0 no hay, 1 si hay.
	int i; // contador para leer la linea.
	int ns; // guardo el numero de espacios que tengo que imprimir para la funcion write_and_parse
	int width; // para el flag '*'. 1 si hay 0 si no hay
	int point; // para el flag de '.' 1 si hay 0 si no hay
	int realspace; // para guardar el valor real 
	int len; // leo los caracteres que imprimo
	int n_sp; // para los numeros de detras del punto en conversion D.
}				t_listpf;

int				ft_printf(const char *s, ...);
void 			checkflags(const char *s, t_listpf *p);
void			put_valors(t_listpf *p);
void			ft_putnbr_ptf(int n, t_listpf *p);
void 			parse_and_printd(t_listpf *p);
void			parse_and_print_lessd(t_listpf *p);
void			write_and_parsed(t_listpf *p);
void			write_and_parse_c(t_listpf *p);
void			write_and_parse_s(t_listpf *p);
void			write_and_parse_x(t_listpf *p, const char *s);
char			*ft_itoahex(int n, const char *s);
void			print_spaces(int realspace, t_listpf *p);
int				ft_atoi(const char *n);
char			*ft_itoa(int n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd, t_listpf *p);
void			ft_putchar_fd(char c, t_listpf *p);
#endif
