#include "minitalk.h"

int ft_small_atoi(char* nb)
{
    int i;
    int number;

    i = -1;
    number = 0;
    while (nb[++i] != '\0')
        number = number * 10 + (nb[i] - '0');
    return (number);
}

void	convert_chars_to_bits_and_send(int pidi, char c)
{
    int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(pidi, SIGUSR1);
		else
			kill(pidi, SIGUSR2);
		c = c >> 1;
		usleep(WAIT_TIME1);
		i++;
	}
}

int	main(int argv, char* argc[])
{
    int		pidi;
	int		i;
    char*	string;
    
	i = 0;
	string = argc[2];
	pidi = ft_small_atoi(argc[1]);
	if (pidi <= 0)
		return (-1);
	if (argv == 3)
	{
		while (string[i] != '\0')
		{
			convert_chars_to_bits_and_send(pidi, string[i]);
			i++;
		}
	}
	return (0);
}
