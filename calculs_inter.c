#include "push_swap.h"


int     ft_position(int *tab, int inter)
{
    int     i;

    i = 0;
    while (tab[i] != inter)
        i++;
    return (i);
}

int     ft_take_inter(int *tab, int inter, int final, int size)
{
    int     i;
    int     j;
    int     reader;

    i = 0;
    j = 0;
    reader = 0;
    while (tab[i++] != inter)
    {
    }
    while (tab[j++] != final)
    {
    }
    printf("Entering take inter or not? inter is %d at %d position and final is %d at %d position\n", inter, i, final, j);
    if (j - 1 > size / 2)
        reader = ft_inter_calcul_backward(tab, i - 1, j - 1, size);
    if (j - 1 <= size / 2)
        reader = ft_inter_calcul_forward(tab, i - 1, j - 1, size);
    return (reader);
}

int     ft_inter_calcul_backward(int *tab, int inter, int final, int size)
{
    if (inter == final + 1)
        return (0);
    if (inter - 1 > final)
        return (1);
    else if (size - final - inter >= 1 && 2 * size - 3 * final + inter - 1 >= 1)
        return (1);
    else if (final - 3 * inter - 1 >= 1 && size - inter - final - 2 >= 1)
        return (1);
    else
        return (0);
}

int     ft_inter_calcul_forward(int *tab, int inter, int final, int size)
{
    if (inter < final)
        return (1);
    else if (inter + final - size - 2 >= 1 && 3 * final - inter - 1 >= 1)
        return (1);
    else if (3 * inter - 2 * size - final - 1 >= 1 && final - size + inter >= 1)
        return (1);
    else
        return (0);
}

int     ft_direction_after_inter(int *tab, int inter, int final, int size)
{
    int     index;
    int     tmpInter;
    int     tmpFinal;

    index = 0;
    while (tab[index] != '\0')
    {
        if (tab[index] == inter)
            tmpInter= index;
        if (tab[index] == final)
            tmpFinal = index;
        index++;
    }
    if ((tmpInter < tmpFinal && tmpFinal - tmpInter <= size / 2)
    || (tmpFinal < tmpInter && tmpInter - tmpFinal >= size / 2))
        return (1);
    else
        return (0);
}