#include "push_swap.h"

long    long_atoi(char *str)
{
	long				atoi;
	long				neg;

	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
						|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	atoi = 0;
	while (*str >= '0' && *str <= '9')
	{
		atoi *= 10;
		atoi += *str - 48;
		str++;
	}
	return (atoi * neg);
}

int     ft_checker(char **argv, int argc)/* || ft_istoohigh(*argv)*/
{
    if (argc < 2)
        return (1);
    while (*argv)
    {
        if (long_atoi(*argv) > INT_MAX || long_atoi(*argv) < INT_MIN)
            return (1);
        while (**argv)
            if (!(**argv == '-' || (**argv >= '0' && **argv <= '9')))
                return (1);
            (*argv)++; 
        argv++;
    }
    return (0);
}

int     ft_isnumber(char *argv)
{
    while (*argv)
    {
        if (*argv < 0 || *argv > 9)
            return (1);
        argv++;
    }
    return (0);
}

int    ft_error()
{
    write(1, "Error\n", 6);
    return (1);
}