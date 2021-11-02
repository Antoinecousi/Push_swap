#include "push_swap.h"

int     nbr_inter_backward(int *tab, int *bubbled, int last, int totInter)
{
    printf("ENTERING NBR INTER BACKWARD \n");
    i_coor  ins;
    int     i;
    int     posLast;
    int     size;
    int     *copy;
    int     pipi;

    ins.tot += totInter;
    posLast = 0;
    i = 0;
    ins = init_ins(ins);
    copy = ft_reverse_tab(tab);
    while (copy[i])
        printf("%d ", copy[i++]);
    i = 0;
    while (copy[i++] != last)
        ins.distanceTot++;
    ins.distanceTot++;
    i = 0;
    printf("current : %d\n", copy[i]);
    printf("ins.lastPos : %d\n", ins.lastPos);
    printf("ins.firstPos : %d\n", ins.firstPos);
    printf("ins.tot : %d\n", ins.tot);
    printf("ins.totrr : %d\n", ins.totrr);
    printf("ins.distanceTot : %d\n", ins.distanceTot);

    //amelioration de ca?
    while (i + 2 < ins.distanceTot)
    {
        display_tab(tab);
        printf("current : %d\n", copy[i]);
        pipi = 1;
        int j = 0;
        int antitotrr = 0;
        while (pipi + 1 <= (ins.distanceTot - i) / 2)
        {
            size = size_array(copy) - 1;
            if (i - pipi >= 0)
                size = i;
            else
                j = i;
            printf("\nsize = %d\n", size);
            printf("Searching for : %d     ", bubbled[ins.tot + 1]);
            printf("I : %d     ", i);
            printf("Index pour chercher : %d    ", size - pipi + j);
            printf("Pointing to : %d\n", copy[size - pipi + j]);
            if (copy[size - pipi + j] >= last && copy[size - pipi + j] < bubbled[ins.tot + 1])
                antitotrr--;
            if (copy[size - pipi + j] == bubbled[ins.tot + 1])
            {
                if (ins.tot == 0)
                {
                    printf("\n    First from behind : %d\n", copy[size - pipi + j]);
                    ins.firstPos = i;
                }
                printf("\n    take from behind : %d\n", copy[size - pipi + j]);
                ins.tot++;
                ins.totrr += pipi - 1;
                ins.totrr += antitotrr;
                printf("\t\t\t\t\t Totrr++\n");
                ins.lastPos = i + 1;
                pipi = 2147483642;
                // i = size - pipi + j;
            }
            pipi++;
            printf("Size of pipi : %d\n", pipi);
        }
        printf("Searching for : %d\n", bubbled[ins.tot + 1]);
        if (copy[i] == bubbled[ins.tot + 1])
        {
            if (ins.tot == 0)
            {
                ins.firstPos = i;
                printf("\n    First from front : %d\n", copy[i]);
            }
            printf("\n    take from front : %d\n\n", copy[i]);
            ins.tot++;
            ins.lastPos = i;
            // i--;
        }
        i++;
    }
    printf("ins.lastPos : %d\n", ins.lastPos);
    printf("ins.firstPos : %d\n", ins.firstPos);
    printf("ins.tot : %d\n", ins.tot);
    printf("ins.totrr : %d\n", ins.totrr);
    printf("ins.distanceTot : %d\n", ins.distanceTot);
    printf("Insertion normale = %d\n", ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + 1 + ins.totrr);
    printf("Insertion améliorée = %d\n", ins.distanceTot + ins.tot * 4 + ins.totrr + 1);
    int Insertion_normale = ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + 1 + ins.totrr;
    int Insertion_améliorée = ins.distanceTot + ins.tot * 4 + ins.totrr + 1;
    printf("%d\n", Insertion_normale - Insertion_améliorée);
    free(copy);
    if (ins.firstPos == -1)
    {
        printf("CEST EGALE A 0\n");
        return (0);
    }
    return (Insertion_normale - Insertion_améliorée);
}

int     nbr_inter_forward(int *tab, int *bubbled, int last, int totInter)
{
    printf("ENTERING NBR INTER FORWARD \n");
    i_coor  ins;
    int     i;
    int     posLast;
    int     size;
    int     pipi;
    int     distance;

    posLast = 0;
    i = 0;
    ins = init_ins(ins);
    while (tab[i++] != last)
        ins.distanceTot++;
    ins.distanceTot++;
    i = 0;
    printf("current : %d\n", tab[i]);
    printf("ins.lastPos : %d\n", ins.lastPos);
    printf("ins.firstPos : %d\n", ins.firstPos);
    printf("ins.tot : %d\n", ins.tot);
    printf("ins.totrr : %d\n", ins.totrr);
    printf("ins.distanceTot : %d\n", ins.distanceTot);

    //amelioration de ca?
    while (i + 1 < ins.distanceTot)
    {
        display_tab(tab);
        printf("current : %d\n", tab[i]);
        pipi = 1;
        int j = 0;
        int antitotrr = 0;
        while (pipi + 2 < (ins.distanceTot - i) / 2)
        {
            size = size_array(tab) - 1;
            if (i - pipi >= 0)
                size = i;
            else
                j = i;
            printf("\nsize = %d\n", size);
            printf("Searching for : %d     ", bubbled[ins.tot + 1]);
            printf("I : %d     ", i);
            printf("Index pour chercher : %d    ", size - pipi + j);
            printf("Pointing to : %d\n", tab[size - pipi + j]);
            if (tab[size - pipi + j] >= last && tab[size - pipi + j] < bubbled[ins.tot + 1])
                antitotrr--;
            if (tab[size - pipi + j] == bubbled[ins.tot + 1])
            {
                if (ins.tot == 0)
                {
                    printf("\n    First from behind : %d\n", tab[size - pipi + j]);
                    ins.firstPos = i;
                }
                printf("\n    take from behind : %d\n", tab[size - pipi + j]);
                ins.tot++;
                ins.totrr += pipi + 1;
                ins.totrr += antitotrr;
                printf("\t\t\t\t\t Totrr++\n");
                ins.lastPos = i + 1;
                i = size - pipi + j;
                pipi = 2147483642;
            }
            pipi++;
            printf("Size of pipi : %d\n", pipi);
        }
        printf("Searching for : %d\n", bubbled[ins.tot + 1]);
        if (tab[i] == bubbled[ins.tot + 1])
        {
            if (ins.tot == 0)
            {
                ins.firstPos = i;
                printf("\n    First from front : %d\n", tab[i]);
            }
            printf("\n    take from front : %d\n\n", tab[i]);
            ins.tot++;
            ins.lastPos = i;
        }
        if (i + 1 < size_array(tab))
            i++;
        else
            i = 0;
    }
    ins.tot += totInter;
    printf("Creer un posit");
    printf("ins.lastPos : %d\n", ins.lastPos);
    printf("ins.firstPos : %d\n", ins.firstPos);
    printf("ins.tot : %d\n", ins.tot);
    printf("ins.totrr : %d\n", ins.totrr);
    printf("ins.distanceTot : %d\n", ins.distanceTot);
    int Insertion_normale = ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + 1 + ins.totrr;
    int Insertion_améliorée = ins.distanceTot + ins.tot * 3 + (ins.totrr * 2) + 1;
    printf("Insertion normale = %d\n", Insertion_normale);
    printf("Insertion améliorée = %d\n", Insertion_améliorée);
    printf("%d\n", Insertion_normale - Insertion_améliorée);
    if (ins.firstPos == -1)
    {
        printf("CEST EGALE A  0\n");
        return (0);
    }
    return (Insertion_normale - Insertion_améliorée);
}