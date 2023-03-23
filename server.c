#include "minitalk.h"

void	ft_get_pid(void)
{
    int	pidi;
	
	pidi = getpid();
	if (pidi == -1 || pidi == 0)
		return ;
	printf("%d\n", pidi); // change to ft_printf
}

/* int	ft_power(int bit_count)
{
	int	score;
	int	i;
	int	p;

	score = 1;
	i = bit_count;
	p = 0;
	while (++p < i)
		score *= 2;
	return (score);
} */

void receive_signal_bits_and_convert_to_bytes(int param)
{
	static int		bit_count = 0;
	static char		byte = 0;
	
	if (param == SIGUSR2)
		bit_count++;
	else
	{
		byte = (1 << bit_count) | byte;
		bit_count++;
	}
	if (bit_count == 8)
	{
		write(1, &byte, 1);
		bit_count = 0;
		byte = 0;
	}
} 

int main(void)
{
	ft_get_pid();
	signal(SIGUSR1, receive_signal_bits_and_convert_to_bytes);
	signal(SIGUSR2, receive_signal_bits_and_convert_to_bytes);
	while (1)
		usleep(WAIT_TIME2);
	return (0);
}
