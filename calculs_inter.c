#include "push_swap.h"


int     ft_position(int *tab, int inter)
{
    int     i;

    i = 0;
    while (tab[i] != inter)
        i++;
    return (i);
}

int     topOrBottomHardBack(int *tab, int inter, int final)
{
    int     allOperations[4];
    int     size;
    int     tmp;
    int     i;

    inter = ft_position(tab, inter);
    final = ft_position(tab, final);
    size = size_array(tab);
    i = 0;
    tmp = INT_MAX;
    allOperations[0] = size - inter + 2;
    allOperations[1] = 2 * (size - final) + inter + 1;
    allOperations[2] = final + 2;
    allOperations[3] = 2 * inter + (size - final) + 3;
    while (i < 4)
    {
        if (allOperations[i] < tmp)
            tmp = allOperations[i];
        i++;
    }
    return (tmp);
}

int     topOrBottomHardFor(int *tab, int inter, int final)
{
    int     allOperations[4];
    int     size;
    int     tmp;
    int     i;

    inter = ft_position(tab, inter);
    final = ft_position(tab, final);
    size = size_array(tab);
    i = 0;
    tmp = INT_MAX;
    allOperations[0] = inter + 1;
    allOperations[1] = 2 * final + (size - inter) + 2;
    allOperations[2] = (size - i) + 3;
    allOperations[3] = 2 * (size - inter) + final + 2;
    while (i < 4)
    {
        if (allOperations[i] < tmp)
            tmp = allOperations[i];
        i++;
    }
    return (tmp);
}

int     topOrBottomHard(int *tab, int inter, int final)
{
    int     size;
    int     result;

    size = size_array(tab) / 2;

    if (ft_position(tab, final) > size)
        result = topOrBottomHardBack(tab, inter, final);
    else
        result = topOrBottomHardFor(tab, inter, final);
    return (result);
}

int     ft_take_inter(int *tab, int inter, int final)
{
    int     i;
    int     j;
    int     size;
    int     reader;

    i = 0;
    j = 0;
    reader = 0;
    size = size_array(tab) / 2;
    while (tab[i++] != inter)
    {
    }
    while (tab[j++] != final)
    {
    }
    if (j - 1 > size)
        reader = ft_inter_calcul_backward(tab, i - 1, j - 1);
    if (j - 1 <= size)
        reader = ft_inter_calcul_forward(tab, i - 1, j - 1);
    
    return (reader);
}

int     ft_inter_calcul_backward(int *tab, int inter, int final)
{
    int     size;

    size = size_array(tab);
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

int     ft_inter_calcul_forward(int *tab, int inter, int final)
{
    int     size;

    size = size_array(tab);
    if (inter < final)
        return (1);
    else if (inter + final - size - 2 >= 1 && 3 * final - inter - 1 >= 1)
        return (1);
    else if (3 * inter - 2 * size - final - 1 >= 1 && final - size + inter >= 1)
        return (1);
    else
        return (0);
}

int     ft_direction_after_inter(int *tab, int inter, int final)
{
    int     index;
    int     size;
    int     result;
    int     tmpInter;
    int     tmpFinal;

    size = size_array(tab);
    index = 0;
    while (tab[index] != '\0')
    {
        if (tab[index] == inter)
            tmpInter= index;
        if (tab[index] == final)
            tmpFinal = index;
        index++;
    }
    if ((tmpInter < tmpFinal && tmpFinal - tmpInter <= size / 2) || (tmpFinal < tmpInter && tmpInter - tmpFinal >= size / 2))
        return (1);
    else
        return (0);
}