/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgrademe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:14:02 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 22:55:06 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRADEMEX_H
# define LIBGRADEMEX_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>

# ifdef _FILE_FT_PRUEBA_C
#  include "ft_prueba.c"
# else
    void ft_prueba_fallback(char *str)
    {
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
        write(1, "\n", 1);
    }
    #define ft_prueba ft_prueba_fallback
# endif

#ifdef _FILE_FT_PUTSTR_C
#  define FT_PUTSTR_PATH __FILE__ "/rendu/ft_putstr/ft_putstr.c"
#  include FT_PUTSTR_PATH
#endif

void ft_prueba(char *str);

#endif