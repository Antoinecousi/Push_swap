#include "push_swap.h"

void    init_ins(i_coor *ins)
{
    ins->firstPos = -1;
    ins->lastPos = 0;
    ins->tot = 0;
    ins->totrr = 0;
    ins->distanceTot = 0;
}

// int     nbr_inter_backward(int *tab, int *bubbled, int last)
// {
//     i_coor  ins;
//     int     i;
//     int     posLast;
//     int     size;
//     int     *copy;
//     int     pipi;

//     posLast = 0;
//     i = 0;
//     init_ins(&ins);
//     copy = ft_reverse_tab(tab, size);
//     i = 0;
//     while (copy[i++] != last)
//         ins.distanceTot++;
//     i = 0;
//     while (i + 2 < ins.distanceTot)
//     {
//         pipi = 1;
//         int j = 0;
//         int antitotrr = 0;
//         while (pipi + 1 <= (ins.distanceTot - i) / 2)
//         {
//             size = size_array(copy) - 1;
//             if (i - pipi >= 0)
//                 size = i;
//             else
//                 j = i;
//             if (copy[size - pipi + j] >= last && copy[size - pipi + j] < bubbled[ins.tot + 1])
//                 antitotrr--;
//             if (copy[size - pipi + j] == bubbled[ins.tot + 1])
//             {
//                 if (ins.tot == 0)
//                     ins.firstPos = i;
//                 ins.tot++;
//                 ins.totrr += pipi;
//                 ins.totrr += antitotrr;
//                 ins.lastPos = i + 1;
//                 pipi = 2147483645;
//             }
//             pipi++;
//         }
//         if (copy[i] == bubbled[ins.tot + 1])
//         {
//             if (ins.tot == 0)
//             {
//                 ins.firstPos = i;
//             }
//             ins.tot++;
//             ins.lastPos = i;
//         }
//         i++;
//     }
//     int Insertion_normale = ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + 2 + ins.totrr;
//     int Insertion_améliorée = ins.distanceTot + ins.tot * 5 + ins.totrr + 1;
//     free(copy);
//     if (ins.firstPos == -1)
//     {
//         return (0);
//     }
//     return (Insertion_normale - Insertion_améliorée);
// }


// int     nbr_inter_forward(int *tab, int *bubbled, int last, int totInter)
// {
//     i_coor  ins;
//     int     i;
//     int     posLast;
//     int     size;
//     int     pipi;

//     posLast = 0;
//     i = 0;
//     init_ins(&ins);
//     while (tab[i++] != last)
//         ins.distanceTot++;
//     ins.distanceTot++;
//     i = 0;
//     while (i + 1 < ins.distanceTot)
//     {
//         pipi = 1;
//         int j = 0;
//         int antitotrr = 0;
//         while (pipi + 2 < (ins.distanceTot - i) / 2)
//         {
//             size = size_array(tab) - 1;
//             if (i - pipi >= 0)
//                 size = i;
//             else
//                 j = i;
//             if (tab[size - pipi + j] >= last && tab[size - pipi + j] < bubbled[ins.tot + 1])
//                 antitotrr--;
//             if (tab[size - pipi + j] == bubbled[ins.tot + 1])
//             {
//                 if (ins.tot == 0)
//                 {
//                     ins.firstPos = i;
//                 }
//                 ins.tot++;
//                 ins.totrr += pipi + 1;
//                 ins.totrr += antitotrr;
//                 ins.lastPos = i + 1;
//                 i = size - pipi + j;
//                 pipi = 2147483642;
//             }
//             pipi++;
//         }
//         if (tab[i] == bubbled[ins.tot + 1])
//         {
//             if (ins.tot == 0)
//             {
//                 ins.firstPos = i;
//             }
//             ins.tot++;
//             ins.lastPos = i;
//         }
//         if (i + 1 < size_array(tab))
//             i++;
//         else
//             i = 0;
//     }
//     ins.tot += totInter;
//     int Insertion_normale = ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + 1 + ins.totrr;
//     int Insertion_améliorée = ins.distanceTot + ins.tot * 3 + (ins.totrr * 2) + 1;
//     if (ins.firstPos == -1)
//     {
//         return (0);
//     }
//     return (Insertion_normale - Insertion_améliorée);
// }