// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <stdlib.h>

int	nlen(int nbr)
{
	int n = 0;
	if (nbr <= 0)
		n++;
	while (nbr != 0)
	{
		n++;
		nbr = nbr / 10;
	}
	return (n);
	
}

char *ft_itoa(int nbr)
{
	char *digits = "0123456789";
	int	len = nlen(nbr);
	char *str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nbr == -2147483648)
		return ("-2147483648\0");
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
	{
		str[0] = '0';
	}
	while (nbr != 0)
	{
		str[--len] = digits[nbr % 10];
		nbr = nbr / 10;
	}
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int prueba = -2147483648;
// 	char *str = ft_itoa(prueba);
// 	printf("%s", str);
// 	return(0);
// }