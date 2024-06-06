/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libzip.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:18:06 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/06 14:36:55 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBZIP_H
# define LIBZIP_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <dirent.h>

# define DEF_COLOR "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"
# define MAX_PATH 4096
# define MAX_LINE_LENGTH 256
# define BUFFER_SIZE 128

// Declaraciones de las funciones
int		ft_input_ok(void);
int		ft_input_ok_fallback(void);
char	*ft_itoa(int n);
char	*ft_paco_argv0(char *name);
char    *ft_paco_argv1(char *name, char *argv1);
int		ft_paco_ok(char *name, char * argv1, int i, int show);
int		ft_paco_aff_a(int k, int show);

#endif
