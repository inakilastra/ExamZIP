/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grademe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilastra- <ilastra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:50:00 by inaki             #+#    #+#             */
/*   Updated: 2024/05/29 09:41:10 by ilastra-         ###   ########.fr       */
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

	printf("\033[H\033[J");
	printf("%s******************************************************\n", CYAN);
	printf("%s***************GRADEMEZIP*****************************\n", CYAN);
	printf("%s******************************************************\n", CYAN);		
	color = get_color(2);
	printf("%s1-1 aff_a.c\t\t1-2 aff_z.c\t\t1-3 ft_putstr.c\n", color);
	printf("%s2-1 aff_first_param.c\t2-2 aff_last_param.c\t2-3 ft_strlen.c\n", color);
	printf("%s3-1 rotone.c\t\t3-2 rot_13.c\t\t3-3 rev_print.c\n", color);
	printf("%s4-1 first_word.c\t4-2 last_word.c\n", color);
	printf("%s5-1 union.c\t\t5-2 inter.c\n", color);
	printf("%s6-1 expand_str.c\t6-2 fizzbuzz.c\n", color);
	printf("%s7-1 ft_range.c\t\t7-2 ft_rrange_z.c\n", color);
	printf("%s8-1 ft_itoa.c\t\t8-2 ft_split.c\n", color);
	printf("%sgrademe\n", color);
	return (0);
}
