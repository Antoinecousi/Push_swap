#include "push_swap.h"


int     ft_position(int *tab, int inter)
{
    int     i;

    i = 0;
    while (tab[i] != inter)
    {
        i++;
    }
    return (i);
}

int     topOrBottomHardBack(int *tab, int inter, int final)
{
    int     allOperations[4];
    int     size;
    int     tmp;
    int     i;

    printf("\t\t\t\t\t\tSALUT FRERE VOICI LE CALCUL POUR %d et %d ", inter, final);
    inter = ft_position(tab, inter);
    final = ft_position(tab, final);
    printf("qui sont aux index: %d et %d ", inter, final);
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
    printf("ce qui donne le meilleur à %d pour une size de %d \n", tmp, size);
    return (tmp);
}
// final > inter forw = inter + 1;
// final > inter chan = 2 * final + (size - inter) + 2;
// inter > final back = (size - i) + 3;
// inter > final chan = 2 * (size - inter) + final + 2;

int     topOrBottomHardFor(int *tab, int inter, int final)
{
    int     allOperations[4];
    int     size;
    int     tmp;
    int     i;

    printf("\t\t\t\t\t\tSALUT FRERE VOICI LE CALCUL POUR %d et %d ", inter, final);
    inter = ft_position(tab, inter);
    final = ft_position(tab, final);
    printf("qui sont aux index: %d et %d ", inter, final);
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
    printf("ce qui donne le meilleur à %d pour une size de %d \n", tmp, size);
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
    return (0);
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
    printf("VALEURS INTER : %d  VALEUR FINAL : %d\n", inter, final);
    while (tab[i++] != inter)
    {
    }
    while (tab[j++] != final)
    {
    }
    printf("POSITION INTER : %d  POSITION FINAL : %d\n", i - 1, j - 1);
    if (j - 1 > size)
        reader = ft_inter_calcul_backward(tab, i - 1, j - 1);
    if (j - 1 <= size)
        reader = ft_inter_calcul_forward(tab, i - 1, j - 1);
    // if (size / 2 - i > j)
    
    printf("MON READER EST A %d   MON SIZE A %d\n", reader, size);
    return (reader);
}

int     ft_inter_calcul_backward(int *tab, int inter, int final)
{
    int     size;

    size = size_array(tab);
    display_tab(tab);
    printf("\n%d size", size_array(tab));
    printf("VALEURS INTER : %d \n VALEUR FINAL : %d\n", inter, final);
    printf("VOICI LES VALEURS %d \n %d \n %d \n %d \n", size - final - inter, 2 * size - 3 * final + inter - 1, final - 3 * inter - 1, size - inter - final - 2);
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
    printf("VALEURS INTER : %d \n VALEUR FINAL : %d\n", inter, final);
    printf("VOICI LES VALEURS %d \n %d \n %d \n %d \n", inter + final - size - 2, 3 * final - inter - 1, final - size + inter, 3 * inter - 2 * size - final - 1);
    if (inter < final)
        return (1);
    else if (inter + final - size - 2 >= 1 && 3 * final - inter - 1 >= 1)
        return (1);
    else if (3 * inter - 2 * size - final - 1 >= 1 && final - size + inter >= 1)
        return (1);
    else
        return (0);
}
// pour backward (i > moitié)
// final > inter back = size - inter + 2; 
// final > inter chan = 2 * (size - i) + inter + 1;
// inter > final forw = final + 2;
// inter > final chan = 2 * inter + (size - i) + 3;

// final > inter back - inter > final forw = size - inter + 2 - final - 1;                       = size - final - inter + 1;
// final > inter chan - inter > final forw = 2 * (size - i) + inter + 1 - final - 1;             = 2 * size - 3 * final + inter - 1;
// final > inter back - inter > final chan = size - inter + 2 - 2 inter - size + final - 3;              = final - 3 * inter - 1;
// final > inter chan - inter > final chan = 2 * size - (2 * i) + inter + 1 - (2 * inter) - size +final - 3;             = size - inter - final - 2;

// pour forward (i < moitié)
// final > inter forw = inter + 1;
// final > inter chan = 2 * final + (size - inter) + 2;
// inter > final back = (size - i) + 3;
// inter > final chan = 2 * (size - inter) +final + 2;

// final > inter forw - inter > final back = inter + 1 - size + final - 3;              = inter + final - size - 2;
// final > inter chan - inter > final back = 2 * final + (size - inter) + 2 - size + final - 3;              = 3 * final - inter - 1;
// final > inter forw - inter > final chan = inter + 1 - (2 * size) + (2 * inter) - final - 2;               = 3 * inter - 2 * size - final - 1;
// final > inter chan - inter >final chan = 2 *final + (size - inter) + 2 - (2 * size) + (2 * inter) -final - 2;             = final - size + inter;


// int     ft_direction_after_inter(int *tab, int inter, int final)
// {
//     int     index;
//     int     size;
//     int     result;

//     size = size_array(tab);
//     index = 0;
//     while (tab[index] != '\0')
//     {
//         if (tab[index] == inter)
//             inter = index;
//         if (tab[index] == final)
//             final = index;
//         index++;
//     }
//     if ((inter < final && final - inter <= size / 2) || (final < inter && inter - final > size / 2))
//     {
//         printf("Direction is ra after car inter = %d et final = %d et size = %d\n", inter, final, size);
//         return (1);
//     }
//     else
//     {
//         printf("Direction is rra after car inter = %d et final = %d et size = %d\n", inter, final, size);
//         return (0);
//     }
// }

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
    {
        printf("Direction is ra after car tmpInter = %d et tmpFinal = %d et size = %d\n", tmpInter, tmpFinal, size);
        return (1);
    }
    else
    {
        printf("Direction is rra after car tmpInter = %d et tmpFinal = %d et size = %d\n", tmpInter, tmpFinal, size);
        return (0);
    }
}