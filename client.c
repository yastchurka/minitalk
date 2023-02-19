#include <stdio.h>
#include <unistd.h>
#include <signal.h>
/* ---------- Atoi to convert user input PID to actual integer ---------- */
int ft_small_atoi(char* nb)
{
    int i;
    int number;

    i = 0;
    number = 0;
    while (nb[i] != '\0')
    {
        number = number * 10 + (nb[i] - '0');
        i++;
    }
    return (number);
}

/* ---------- Convert a letter to bits ---------- */
/* ---------- And send to the process  ---------- */
int convert_a_to_bits(int pidi, char c)
{
    int i;
    
    i = 0;
    while (i < 8)
    {
		if (c & 0x80)
			kill(pidi, SIGUSR1);
		else
			kill(pidi, SIGUSR2);
        i++;
        c = c << 1;
        usleep(1000);
    }
    usleep(1000);
}

int main(int argv, char* argc[])
{
    int pidi;
    char c;
    
    c = argc[2][0];
    pidi = ft_small_atoi(argc[1]);
    if (argv == 3)
    {
        convert_a_to_bits(pidi, c);
    }
    return (0);
}