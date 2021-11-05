#include "push_swap.h"

int     ft_dblist_size(dblist *dbl)
{
    int     i;
    p_list  *a;

    i = 0;
    a = dbl->first;
    while (a)
    {
        a = a->next;
        i++;
    }
    return (i);
}

void    ft_addfrontlist(dblist *dbl, int val)
{
    p_list  *a;
    
    a = malloc(sizeof(p_list));
    if (!a)
        exit(EXIT_FAILURE);
    a->content = val;
    a->prev = NULL;
    a->next = dbl->first;
    //TO LOOK IN DETAIL w/ chgi.developpez.com/dblist/
    if (dbl->first)
        dbl->first->prev = a;
    else
        dbl->last = a;
    dbl->first = a;
}

void    ft_addbacklist(dblist *dbla, int val)
{
    p_list  *a;
    
    a = malloc(sizeof(p_list));
    if (!a)
        exit(EXIT_FAILURE);
    a->content = val;
    a->prev = dbla->last;
    a->next = NULL;
    //TO LOOK IN DETAIL
    if (dbla->last)
        dbla->last->next = a;
    else
        dbla->first = a;
    dbla->last = a;
}

void    display_lists(dblist *dbla, dblist *dblb)
{
    p_list  *a;
    p_list  *b;

    a = dbla->first;
    b = dblb->first;

    printf("LIST A : ");
    while (a)
    {
        printf("%d ", a->content);
        a = a->next;
    }
    printf(" &&  ");
    printf("LIST B : ");
    while (b)
    {
        printf("%d ", b->content);
        b = b->next;
    }
    printf("\n");
}

void    display_tab(int *tab)
{
    while (*tab)
    {
        printf("%d ", *tab);
        tab++;
    }
}

void    ft_init_dblist(dblist *dbla)
{
    dbla->first = 0;
    dbla->last = 0;
}