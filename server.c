#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h> //exit()

static int		bit_count = 7;
static char		byte = 0;

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

	score = 1;
	i = bit_count;
	while (i >= 0)
	{
		score *= 2;
		i--;
	}
	printf("SCORE : %d\n", score);
	return (score);
}
//  
void	my_handler(int param)
{
	if (param == 12) /* corresponding to 0 bit */
	{
		printf("0 ");
		printf("BIT COUNT: %d ", bit_count);
		bit_count--;
	}
	else
	{
		printf("BIT COUNT: %d\n", bit_count);
		bit_count--;
		byte = byte + ft_power(bit_count); /* 2 to the power bit_count */ 
		printf("1 ");
	}
	printf("Byte: %c\n", byte);
}

int main(void)
{
	int	i;

	i = 0;
	ft_get_pid();	
	while (i < 20)
	{
		signal(SIGUSR1, my_handler);
		signal(SIGUSR2, my_handler);
		sleep(1);
		i++;
	}
	return (0);
}

/* 
	1. How to determine how long is the message
	2. How to send more than one sign
	3. How to send the lenght
	4. How to convert binary to numbers?
 */