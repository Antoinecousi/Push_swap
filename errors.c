#include "push_swap.h"

int     ft_checker(char **argv, int argc)/* || ft_istoohigh(*argv)*/
{
    if (argc < 2)
        return (1);
    while (*argv)
    {
        if (ft_istoohigh(*argv))
            return (1);
        while (**argv)
            if (**argv < '0' || **argv > '9')
                return (1);
            (*argv)++; 
        argv++;
    }
    return (0);
}

int     ft_istoohigh(char *argv)
{
    return (0);
    //mettre un atoi avec long pour test int max;
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

int     ft_error()
{
    write(1, "Error\n", 6);
    return (0);
}