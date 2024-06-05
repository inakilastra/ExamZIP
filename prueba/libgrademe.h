/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgrademe.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:14:02 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/05 16:35:45 by ilastra-         ###   ########.fr       */
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
#  define FT_PRUEBA_PATH __FILE__ "/prueba/ft_prueba.c"
#  include FT_PRUEBA_PATH
# else
    void ft_prueba_fallback(char *str)
    {
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
    }
    #define ft_prueba ft_prueba_fallback
# endif


#ifdef _FILE_FT_PUTSTR_C
#  define FT_PUTSTR_PATH __FILE__ "/rendu/ft_putstr/ft_putstr.c"
    #include FT_PUTSTR_PATH
#endif

void ft_prueba(char *str);

#endif