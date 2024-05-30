/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:50:38 by ilastra-          #+#    #+#             */
/*   Updated: 2024/05/30 13:03:08 by ilastra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifndef CONTROL_H
#define CONTROL_H

char    *ft_itoa(int n);
int     control(const char get_write, int question);
char    *control_date(void);
int     check_file(const char *str);
int     copy_file(const char *src, const char *dst);
int     move_file(const char *src, const char *dst);
int     new_folder(const char *dir);
void    print_msg (const char *str1, const char *sfile);

#endif
