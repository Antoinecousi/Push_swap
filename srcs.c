/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:16:43 by acousini          #+#    #+#             */
/*   Updated: 2021/11/24 21:26:55 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_next_seeked(int *tab, int c)
{
    int     i;
    int     pos;

    i = 0;
    pos = -1;
    while (tab[i])
    {
        if (tab[i] == c)
            pos = i;
        i++;
    }
    if (!pos)
        return (0);
    return (i / pos);
}

int     ft_next_lower(int *tab)
{
    int     i;
    int     lower;
    int     pos;

    i = 0;
    lower = INT_MAX;
    pos = -1;
    while (tab[i])
    {
        if (tab[i] < lower)
        {
            lower = tab[i];
            pos = i;
        }
        i++;
    }
    if (!pos)
        return (0);
return (i / pos);
}

int     ft_next_upper(int *tab)
{
    int     i;
    int     lower;
    int     pos;
    int     stop;

    i = 0;
    pos = 0;
    lower = INT_MIN;
    while (tab[i])
    {
        if (tab[i] > lower)
        {
            lower = tab[i];
            pos = i;
        }
        i++;
    }
    stop = pos;
    if (stop == 0)
        return (0);
    return (i / stop);
}

int     ft_next_lower_bis(int *tab)
{
    int     i;
    int     lower;
    int     pos;

    i = 0;
    pos = -1;
    lower = INT_MAX;
    while (tab[i])
    {
        if (tab[i] < lower)
        {
            lower = tab[i];
            pos = i;
        }
        i++;
    }
    if (!pos)
        return (0);
return (i / pos);

}

int     ft_get_med_div(int *tab, int div_med, int size)
{
    tab = ft_bubble(tab, size);
    return (tab[(size - 1) / div_med]);
}

int     ft_get_med_div_b(int *tab, int div_med, int size)
{
    tab = ft_bubble(tab, size);
    return (tab[size - ((size - 1) / div_med)]);
}

int     ft_fill_stack(char **argv, dblist *dbla)
{
    int     val;
    int     i;

    i = 0;
    while (argv[i] != '\0')
    {
        val = atoi(argv[i]);
        ft_addbacklist(dbla, val); 
        i++;
    }
    return (i);
}


p_coor    ft_fill_coor_alt(p_coor coor, int *tab)
{
    int     i;

    i = 0;
    while (tab[i] != coor.med)
    {
        if (tab[i] > coor.med)
            coor.upperMed++;
        else
            coor.lowerMed++;
        i++;
    }
    return (coor);
}

int     ft_get_med(int *tab, int size)
{
    int     i;
    
    i = 0;
    while (tab[i])
        i++;
    tab = ft_bubble(tab, size);
    return (tab[(i - 1) / 2]);
}

int     *ft_bubble(int *tab, int size)
{
    int     tmp;
    int     i;

    i = 0;
    while (i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            if (i > 0)
                i--;
        }
        else
            i++;
    }
    return (tab);
}

int     *ft_reverse_bubble(int *tab, int size)
{
    int     tmp;
    int     i;

    i = 0;
    while (i < size - 1)
    {
        if (tab[i] < tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
            if (i > 0)
                i--;
        }
        else
            i++;
    }
    return (tab);
}

// int     *ft_reverse_tab(int *tab, int size)
// {
//     int     i;
//     int     *copy;
//     int     j;

//     j = 0;
//     copy = malloc(8 * size + 8);
//     i = 1;
//     copy[0] = tab[0];
//     while (i < size)
//     {
//         copy[i] = tab[size - j - 1];
//         i++;
//         j++;
//     }
//     copy[i] = '\0';
//     i = 0;
//     while (copy[i])
//         i++;
//     return (copy);
// }

p_coor  ft_fill_coor(p_coor coor, dblist *dbl)
{
    int     i;
    int     *tab;

    i = 0;
    tab = list_to_array(dbl);
    coor.med = ft_get_med(tab, ft_dblist_size(dbl));
    while (tab[i])
    {
        if (tab[i] < coor.first)
        {
           coor.first = tab[i];
           coor.posFirst = i + 1;
        }
        if (tab[i] > coor.last)
        {
            coor.last = tab[i];
            coor.posLast = i + 1;
        }
        i++;
    }
    return (coor);
}