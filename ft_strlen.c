// Assignment name  : ft_strlen
// Expected files   : ft_strlen.c
// Allowed functions: 
// --------------------------------------------------------------------------------
// Write a function that returns the length of a string.
// Your function must be declared as follows:
// int	ft_strlen(char *str);

int ft_strlen(char *str)
{
	int n = 0;
	while (str[n])
		n++;
	return (n);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_strlen("hola"));
// 	return (0);
// }