#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h> //exit()

static char	string[1000000];

int my_function(int zero_or_one);

void	ft_get_pid(void)
{
    int	pidi;
	
	pidi = getpid();
	if (pidi == -1)
		return ;
	// we need one more safety condition if (pidi == 0)
	printf("%d\n", pidi);
}

int	ft_power(int bit_count)
{
	int	score;
	int	i;
	int	p;

	score = 1;
	i = bit_count;
	p = 1;
	while (p < i)
	{
		score *= 2;
		p++;
	}
	return (score);
}

void	my_handler(int param)
{
	if (param == 12) /* corresponding to 0 bit */
		my_function(0);
	else
		my_function(1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	my_function(int zero_or_one)
{
	static int		bit_count = 0;
	static char		byte = 0;
	static char		string[1];
	static int		i = 0;
	
	if (zero_or_one == 0)
		bit_count++;
	else
	{
		bit_count++;
		byte = byte + ft_power(bit_count);
	}
	if (bit_count == 8)
	{
		string[0] = byte;
		bit_count = 0;
		byte = 0;
		ft_putchar(string[0]);
	}
	return (0);
} 

int main(void)
{
	int	i;

	i = 0;
	ft_get_pid();
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		usleep(300);
	//printf("%s", string);
	return (0);
}