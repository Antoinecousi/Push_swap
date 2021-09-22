/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:16:43 by acousini          #+#    #+#             */
/*   Updated: 2021/09/15 19:11:11 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_next_lower(int *tab)
{
    int     i;
    int     lower;
    int     pos;
    int     lol;

    i = 0;
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
    if (pos == 1)
        return (1);
    lol = i / pos;
    if (lol > 1)
        return (pos);
    else
        return (pos - i);
}

int     ft_get_tier(int *tab)
{
        int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 3]);
}

void    ft_init_coor(p_coor coor)
{
    coor.first = INT_MAX;
    coor.posFirst = 0;
    coor.med = 0;
    coor.posMed = 0;
    coor.last = INT_MIN;
    coor.posLast = 0;
    coor.upperMed = 0;
    coor.lowerMed = 0;
}

void    ft_fill_stack(char **argv, dblist *dbla)
{
    int     val;
    int     i;

    i = 0;
    while (argv[++i])
    {
        val = ft_atoi(argv[i]);
        ft_addbacklist(dbla, val); 
    }
}

p_coor  ft_fill_coor(p_coor coor, dblist *dbl)
{
    int     i;
    int     *tab;

    i = 0;
    tab = list_to_array(dbl);
    coor.med = ft_get_med(tab);
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
        if (tab[i] == coor.med)
            coor.posMed = i + 1;
        i++;
    }
    coor = ft_fill_coor_alt(coor, tab);
    return (coor);
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

int     ft_get_med(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 2]);
}

int     *ft_bubble(int *tab)
{
    int     tmp;
    int     i;

    i = 0;
    while (tab[i + 1])
    {
        if (tab[i] > tab[i + 1])
        {
            tmp = tab[i];
            tab[i] = tab [i + 1];
            tab[i + 1] = tmp;
            if (i > 0)
                i--;
        }
        else
            i++;
    }
    return (tab);
}