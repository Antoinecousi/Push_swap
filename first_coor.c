#include "push_swap.h"

void    ft_init_first_coor(p_coor *coor)
{
    coor->first = INT_MAX;
    coor->posFirst = 0;
    coor->med = 0;
    coor->posMed = 0;
    coor->last = INT_MIN;
    coor->posLast = 0;
    coor->upperMed = 0;
    coor->lowerMed = 0;
    coor->Huitieme = 0;
    coor->secHuitieme = 0;
    coor->thiHuitieme = 0;
    coor->fouHuitieme = 0;
}

void    ft_fill_first_coor(p_coor *coor, dblist *dbl)
{
    int     i;
    int     *tab;
    p_list *a;

    /*a = dbl->first;
    while (a->next)
    {
        printf("%d ", a->content);
        a = a->next;
    }*/
    i = 0;
    tab = list_to_array(dbl);
    i = 0;
    coor->med = ft_get_med(tab);
    coor->tier = ft_get_tier(tab);
    while (tab[i])
    {
        if (tab[i] < coor->first)
        {
           coor->first = tab[i];
           coor->posFirst = i + 1;
        }
        if (tab[i] > coor->last)
        {           
            coor->last = tab[i];
            coor->posLast = i + 1;
        }
        if (tab[i] == coor->med)
            coor->posMed = i + 1;
        i++;
    }
    ft_fill_first_coor_alt(coor, tab);
    coor->lowerMed = ft_get_quarter(tab);
    coor->upperMed = ft_get_thirdquarter(tab);
    coor->Huitieme = ft_get_huitieme(tab);
    coor->secHuitieme = ft_get_secondhuitieme(tab);
    coor->thiHuitieme = ft_get_thirdhuitieme(tab);
    coor->fouHuitieme = ft_get_fourthhuitieme(tab);
}

void    ft_fill_first_coor_alt(p_coor *coor, int *tab)
{
    int     i;

    i = 0;
    while (tab[i] != coor->med)
    {
        if (tab[i] > coor->med)
            coor->upperMed++;
        else
            coor->lowerMed++;
        i++;
    }
}