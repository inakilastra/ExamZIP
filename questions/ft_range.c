// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
// Write the following function:
// int     *ft_range(int start, int end);
// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.
// Examples:
// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	long	i;
	long len;
	
	if (end > start)
		len = (long)end - (long)start + 1;
	if (start> end)
		len = (long)start - (long)end + 1;

	int *numbers;
	i = 0;
	numbers = (int *)malloc(sizeof(int) * len);
	if (!numbers)
		return (NULL);
	
	while (i < len)
	{
		if (start <= end)
			numbers[i++] = start++;
		else
			numbers[i++] = start--;
	}
	return (numbers);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// int start = -2;
// 	// int end = 2;
// 	int start = -2147483648;
// 	int end = 2147483647;
// 	int *prueba = ft_range(start, end);
// 	int i = 0;
// 	while (i < 4)
// 		printf("%d |", prueba[i++]);
// 	return (0);
// }