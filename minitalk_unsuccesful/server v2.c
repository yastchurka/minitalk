#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h> //exit()

void	ft_get_pid(void)
{
    int	pidi;
	
	pidi = getpid();
	if (pidi == -1 || pidi == 0)
		return ;
	printf("%d\n", pidi); // change to ft_printf
}

int	ft_power(int bit_count)
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
}

static int	get_length(int param)
{
	static int		bit_count = 0;
	static char		byte = 0;
	static int		len = 0;

	if (param == SIGUSR1) //chagne to SIGUSR1
		bit_count++;
	else
	{
		bit_count++;
		byte = byte + ft_power(bit_count);
	}
	if (bit_count == 32)
	{
		len = byte;
		return (len);
	}
	return (0);
}

void showtime(char **string, int *i, int *len)
{
	printf("%s\n", *string);
	*i = 0;
	free(string);
	*string = 0;
	*len = 0;
}

static void create_string(char **string, int len)
{

}

void receive_signal_bits_and_convert_to_bytes(int param)
{
	static int		bit_count = 0;
	static char		byte = 0;
	static char		*string;
	static int		p = -1;
	static int		i = 0;
	static int		len = 0;

	if (++p < 32)
		len = get_length(param);
	else
	{
		string = malloc(len + 1);
		if (!string)
			
		if (param == 12) //chagne to SIGUSR1
			bit_count++;
		else
		{
			bit_count++;
			byte += ft_power(bit_count);
		}
		if (bit_count == 8)
		{
			string[i++] = byte;
			bit_count = 0;
			byte = 0;
			if (i == len)
			{
				showtime(&string, &i, &len);
				printf("MADAGAKA\n");
			}
		}
	}
} 

int main(void)
{
	ft_get_pid();
	signal(SIGUSR1, receive_signal_bits_and_convert_to_bytes);
	signal(SIGUSR2, receive_signal_bits_and_convert_to_bytes);
	while (1)
		usleep(200);
	return (0);
}