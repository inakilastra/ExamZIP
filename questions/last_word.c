
// Example:
// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>

void last_word(char *str)
{
	int i = 0;
	int j = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') && (str[i+1] >=33 && str[i+1] <= 126))
			j = i + 1;
		i++;
	}
	while (str[j] >= 33 && str[j] <= 126)
		write(1, &str[j++], 1);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		last_word(argv[1]);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }