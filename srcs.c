/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acousini <acousini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:16:43 by acousini          #+#    #+#             */
/*   Updated: 2021/11/23 17:46:49 by acousini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_next_seeked(int *tab, int c)
{
    int     i;
    int     pos;
    int     lol;

    i = 0;
    pos = -1;
    while (tab[i])
    {
        if (tab[i] == c)
            pos = i;
        i++;
    }
    // printf("RESULTAT DU NEXT UPPPER : %d \n", i / pos);
    if (!pos)
        return (0);
    // printf("prochain pos de lower : %d      donc i / pos = %d \n", pos, i / pos);
return (i / pos);
}

// int     ft_shorter(int *tab, int c, int d)
// {
//     int
// }

int     topOrBot(int *tab, int c)
{
    int     i;
    int     j;

    j = size_array(tab);
    i = 0;
    // if (j > 0)
    //     return (0);
    while (tab[i])
    {
        if (tab[i] == c)
            break;
        i++;
    }
    if (i > j - i)
        return (j - i);
    return (i);
}

int     ft_next_lower(int *tab)
{
    int     i;
    int     lower;
    int     pos;
    int     lol;

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
    // printf("prochain lower : %d \n", lower);
    // printf("RESULTAT DU NEXT UPPPER : %d \n", i / pos);
    if (!pos)
        return (0);
return (i / pos);
}

int     ft_next_upper(int *tab)
{
    int     i;
    int     lower;
    int     pos;
    int     lol;
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
    // printf("prochain lower : %d \n", lower);
    if (stop == 0)
        return (0);
    // printf("RESULTAT DU NEXT UPPPER : %d \n", i / stop);
    return (i / stop);
}

int     ft_next_lower_bis(int *tab, int c)
{
    int     i;
    int     lower;
    int     pos;
    int     lol;

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
    // printf("prochain lower : %d \n", lower);
    // printf("RESULTAT DU NEXT UPPPER : %d \n", i / pos);
    if (!pos)
        return (0);
return (i / pos);

}

int     ft_get_tier(int *tab)
{
        int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 3]);
}

int     ft_get_med_div(int *tab, int div_med)
{
    int     i;
    
    i = 0;
    while (tab[i])
    {
        i++;
    }
    tab = ft_bubble(tab);
    return (tab[(i - 1) / div_med]);
}

int     ft_get_med_div_b(int *tab, int div_med)
{
    int     i;
    
    i = 0;
    while (tab[i])
    {
        i++;
    }
    tab = ft_bubble(tab);
    // printf("MA MED POUR DIV MED = %d   ET MON MED = %d\n", div_med, tab[size_array(tab) - ((i - 1) / div_med)]);
    return (tab[size_array(tab) - ((i - 1) / div_med)]);
}

int     ft_fill_stack(char **argv, dblist *dbla)
{
    int     val;
    int     i;

    i = 0;
    while (argv[i])
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

int     ft_get_huitieme(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 8]);
}

int     ft_get_quarter(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    // printf("%d et %d \n", tab[(i - 1) / 4], (i - 1) / 4);
    return (tab[(i - 1) / 4]);
}

int     ft_get_secondhuitieme(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    // printf("%d et %d \n", tab[(i - 1) / 4 + (i - 1) / 8], (i - 1) / 4 + (i - 1) / 8);
    return (tab[(i - 1) / 4 + (i - 1) / 8]);
}

int     ft_get_med(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 2]);
}


int     ft_get_thirdhuitieme(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    // printf("%d et %d \n", tab[(i - 1) / 2 + (i - 1) / 8], (i - 1) / 2 + (i - 1) / 8);
    return (tab[(i - 1) / 2 + (i - 1) / 8]);
}

int     ft_get_thirdquarter(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 2 + (i - 1) / 4]);
}

int     ft_get_fourthhuitieme(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i++])
    tab = ft_bubble(tab);
    return (tab[(i - 1) / 2 + (i - 1) / 4 + (i - 1) / 8]);
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

int     *ft_reverse_bubble(int *tab)
{
    int     tmp;
    int     i;

    i = 0;
    while (tab[i + 1])
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

int     *ft_reverse_tab(int *tab)
{
    int     i;
    int     size;
    int     tmp;
    int     *copy;
    int     j;

    j = 0;
    size = size_array(tab) - 1;
    copy = malloc(8 * size + 9);
    i = 0;
    // printf("Here's my not tab      : ");
    // while (i < size)
    // {
    //     printf("%d ", tab[i]);
    //     i++;
    // }
    // ("\n");
    i = 1;
    copy[0] = tab[0];
    while (i < size)
    {
        copy[i] = tab[size - j - 1];
        i++;
        j++;
    }
    copy[i] = '\0';
    i = 0;
    // printf("Here's my reversed tab : ");
    while (copy[i])
    {
        // printf("%d ", copy[i]);
        i++;
    }
    // printf("\n");
    return (copy);
}

p_coor  ft_fill_coor(p_coor coor, dblist *dbl)
{
    int     i;
    int     *tab;

    // printf("COUCOU\n");
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
        i++;
    }
    // coor = ft_fill_coor_alt(coor, tab);
    coor.lowerMed = ft_get_quarter(tab);
    coor.upperMed = ft_get_thirdquarter(tab);
    return (coor);
}