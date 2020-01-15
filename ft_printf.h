/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:25:16 by dlobos-m          #+#    #+#             */
/*   Updated: 2020/01/15 16:03:39 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

typedef struct	s_listpf
{
	int			intaux;
	char		*aux;
	va_list		ap;
	int			zeros;
	int			less;
	int			i;
	int			ns;
	int			width;
	int			point;
	int			realspace;
	int			len;
	int			n_sp;
}				t_listpf;

int				ft_printf(const char *s, ...);
void			checkflags(const char *s, t_listpf *p);
void			put_valors(t_listpf *p);
void			ft_putnbr_ptf(int n, t_listpf *p);
void			parse_and_printd(t_listpf *p, const char *s);
void			parse_and_print_lessd(t_listpf *p, const char *s);
void			write_and_parsed(t_listpf *p, const char *s);
void			write_and_parse_c(t_listpf *p);
void			write_and_parse_s(t_listpf *p);
void			write_and_parse_x(t_listpf *p, const char *s);
char			*ft_itoahex(unsigned long int n, const char *s);
void			print_spaces(int realspace, t_listpf *p);
int				ft_atoi(const char *n);
char			*ft_itoa(long long n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd, t_listpf *p);
void			ft_putnbr_fd(intmax_t n, int fd, t_listpf *p);
void			ft_putchar_fd(char c, t_listpf *p);
void			ft_putnbr_ptfu(uintmax_t n, t_listpf *p);
void			calculate_u(int *realspace, unsigned int u, t_listpf *p);
void			parse_and_print_u(t_listpf *p);
void			write_and_parse_p(t_listpf *p);
void			write_pct(t_listpf *p);
void			ft_putchar_main(const char *s, t_listpf *p);
void			ft_del(char *temp, t_listpf *p, int len);
#endif
