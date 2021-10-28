#include "push_swap.h"

int     ft_inter_calcul_backward(int *tab, int inter, int final)
{
    int     size;

    size = size_array(tab);
    if (inter == final + 1)
        return (0);
    if (inter - 1 > final)
        return (1);
    else if (size - final- inter + 1 >= 1 && 2 * size - 3 * final + inter - 1 >= 1)
        return (1);
    else if (final - 3 * inter - 1 >= 1 && size - inter - final- 2 >= 1)
        return (1);
    else
        return (0);
}

int     ft_inter_calcul_forward(int *tab, int inter, int final)
{
    int     size;

    size = size_array(tab);
    printf("VALEURS INTER : %d \n VALEUR FINAL : %d\n", inter, final);
    printf("VOICI LES VALEURS %d \n %d \n %d \n %d \n",inter + final - size - 2, 3 * final - inter - 1, final - size + inter, 3 * inter - 2 * size - final - 1);
    if (inter < final)
        return (1);
    else if (inter + final - size - 2 >= 1 && 3 * final - inter - 1 >= 1)
        return (1);
    else if (3 * inter - 2 * size - final - 1 >= 1 && final - size + inter >= 1)
        return (1);
    else
        return (0);
}

// pour forward (i < moitié)
// i > j forw = j + 1;
// i > j chan = 2 * i + (size - j) + 2;
// j > i back = (size - i) + 3;
// j > i chan = 2 * (size - j) + i + 2;

// i > j forw - j > i back = j + 1 - size + i - 3;
//                            = j + i - size - 2;
// // i > j chan - j > i back = 2 * i + (size - j) + 2 - size + i - 3;
//                            = 3 * i - j - 1;
// // i > j forw - j > i chan = j + 1 - (2 * size) + (2 * j) - i - 2;
//                            = 3 * j - 2 * size - i - 1;
// // i > j chan - j > i chan = 2 * i + (size - j) + 2 - (2 * size) + (2 * j) - i - 2;
//                            = i - size + j;

// // pour backward (i > moitié)
// // i > j back = size - j + 2; 
// // i > j chan = 2 * (size - i) + j + 1;
// // j > i forw = i + 2;
// // j > i chan = 2 * j + (size - i) + 3;

// // i > j back - j > i forw = size - j + 2 - i - 1;
//                            = size - i - j + 1;
// // i > j chan - j > i forw = 2 * (size - i) + j + 1 - i - 1;
//                            = 2 * size - 3 * i + j - 1;
// // i > j back - j > i chan = size - j + 2 - 2 j - size + i - 3;
//                            = i - 3 * j - 1;
// // i > j chan - j > i chan = 2 * size - (2 * i) + j + 1 - (2 * j) - size + i - 3;
//                            = size - j - i - 2;

int     ft_direction_after_inter(int *tab, int inter, int final)
{
    int     index;
    int     size;
    int     result;

    size = size_array(tab);
    index = 0;
    while (tab[index] != '\0')
    {
        if (tab[index] == inter)
            inter = index;
        if (tab[index] == final)
            final = index;
        index++;
    }
    if ((inter < final && final - inter <= size / 2) || (final < inter && inter - final > size / 2))
    {
        printf("Direction is ra after\n");
        return (1);
    }
    else
    {
        return (0);
    }
}