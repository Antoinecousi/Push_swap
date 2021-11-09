#include "push_swap.h"

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