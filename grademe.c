/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaki <inaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:50:00 by inaki             #+#    #+#             */
/*   Updated: 2024/05/29 00:14:19 by inaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
	
#define DEF_COLOR "\033[0;39m"
#define GRAY "\033[0;90m"
#define RED "\033[0;91m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define BLUE "\033[0;94m"
#define MAGENTA "\033[0;95m"
#define CYAN "\033[0;96m"
#define WHITE "\033[0;97m"

const char* get_color(int value)
{
    switch (value) 
	{
        case 0:
            return GRAY;
        case 1:
            return RED;
        case 2:
            return GREEN;
        case 3:
            return YELLOW;
        case 4:
            return BLUE;
        case 5:
            return MAGENTA;
        case 6:
            return CYAN;
        case 7:
            return WHITE;												
        default:
            return DEF_COLOR;
    }
}

int	main(void)
{
	const char *color;
		
	color = get_color(2);
	printf("%s1-1 aff_a.c\t1-2 aff_z.c\n", color);
	printf("%s2-1 aff_first.c\t2-2 aff_z.c\n", color);
	printf("%s3-1 aff_a.c\t3-2 aff_z.c\n", color);
	printf("%s4-1 aff_a.c\t4-2 aff_z.c\n", color);
	printf("%s5-1 aff_a.c\t5-2 aff_z.c\n", color);
	printf("%s6-1 aff_a.c\t6-2 aff_z.c\n", color);
	printf("%s7-1 aff_a.c\t7-2 aff_z.c\n", color);
	printf("%s8-1 ft_itoa.c\t8-2 ft_split.c\n", color);
	printf("%sgrademe\n", color);
	return (0);
}

/* aff_first_param.c
aff_last_param.c
last_word.c
expand_str.c
fizzbuzz.c
ft_putstr.c
ft_range.c
ft_revprint.c
ft_rrange.c
ft_strlen.c
inter.c
rot_13.c
rotone.c
union.c */