/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libzip.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:18:06 by ilastra-          #+#    #+#             */
/*   Updated: 2024/06/20 23:39:30 by inaki            ###   ########.fr       */
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
//  ft_ctr_txt.c
char    *ctr_txt(const char *sfile_txt, const char get_write, char mode, int question , const char *question_name);
//  ft_files.c
int		ft_check_file(const char *str);
int		ft_copy_file(const char *src, const char *dst);
void	ft_file(const char *sfile);
int		ft_new_folder(const char *dir);
void	ft_remove_directory(const char *path);


int		ft_input_ok(void);
int		ft_input_ok_fallback(void);
char	*ft_myitoa(int n);

char *get_date(void);
void calculate_time_difference(const char *start_str);
void replaceHomeWithTilde(char *path);
void    print_msg (const char *str1, const char *sfile);



char	*paco_argv0(char *name);
char    *paco_argv1(char *name, char *argv1);
int		paco_ok(char *name, char *argv1, int i, int show);
int		paco_aff_a(int k, int show);
int     paco_aff_z(int k, int show);
#ifdef _FILE_FT_PUTSTR_C 
 void   ft_putstr(char *str);
#endif
int     paco_ft_putstr(int k, int show);
#ifdef _FILE_FT_STRLEN_C 
 int	ft_strlen(char *str);
#endif
int     paco_ft_strlen(int k, int show);
int     paco_rev_print(int k, int show);
int     paco_fizzbuzz(int k, int show);
int     paco_buzzfizz(int k, int show);
int     paco_aff_first_param(int k, int show);
int     paco_aff_last_param(int k, int show);
int     paco_rotone(int k, int show);
int     paco_first_word(int k, int show);
int     paco_rot_13(int k, int show);
int     paco_last_word(int k, int show);
int     paco_inter(int k, int show);
int     paco_union(int k, int show);
int     *ft_rrange(int start, int end);
int     paco_ft_rrange(int k, int show);
int     *ft_range(int start, int end);
int     paco_ft_range(int k, int show);
char    *ft_itoa(int nbr);
int     paco_ft_itoa(int k, int show);
int     paco_expand_str(int k, int show);
char    **ft_split(char *str);
int     paco_ft_split(int k, int show);
int     ft_success_del_subject(char *name, int show, int i, int grade);
void	ft_failure(int show, int try);
void    ft_failure_check_file(char *name, int show, int try);

#endif
