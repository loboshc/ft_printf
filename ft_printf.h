/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:25:16 by dlobos-m          #+#    #+#             */
/*   Updated: 2019/12/21 21:06:55 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct k_list
{
	char *string; // cargo una cadena para modificarla
	va_list ap;
	int zeros; // indicador para saber si tengo que rellenar con ceros o no;
	int less; // para el flag '-'. 0 no hay, 1 si hay.
	int i; // contador para leer la linea.
	int num_space; // guardo el numero de espacios que tengo que imprimir para la funcion write_and_parse
	int width; // para el flag '*'. 1 si hay 0 si no hay
	int point; // para el flag de '.' 1 si hay 0 si no hay
	int realspace; // para guardar el valor real 
	int len; // leo los caracteres que imprimo
	int num_space_point; // para los numeros de detras del punto en conversion D.
}p_list;

int		ft_printf(const char *s, ...);

#endif
