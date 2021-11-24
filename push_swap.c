#include "push_swap.h"

void    ft_do(dblist *dbla, dblist *dblb, p_coor *coor)
{   
    int     *c;
    int     i;

    i = 0;
    c = ft_bubble(list_to_array(dbla), ft_dblist_size(dbla));
    choose_sort_stack(dbla, dblb, coor);
    i = 0;
    while (dblb->first)
    {
        c = ft_reverse_bubble(list_to_array(dblb), ft_dblist_size(dblb));
        if (dblb->first->content == c[0]) 
            do_pa(dbla, dblb);
        else if (!ft_take_inter(list_to_array(dblb), c[1], c[0], ft_dblist_size(dblb)))
        {
            while (dblb->first->content != c[0] && ft_next_seeked(list_to_array(dblb), c[0]) > 1)
                do_rb(dbla, dblb);
            while (dblb->first->content != c[0] && ft_next_seeked(list_to_array(dblb), c[0]) <= 1)
                do_rrb(dbla, dblb);
            do_pa(dbla, dblb);
        }
        else
        {
            if (ft_direction_after_inter(list_to_array(dblb), c[1], c[0], ft_dblist_size(dblb)) >= 1)
            {
                int     b = ft_forwardB(dbla, dblb, c, c[0], 0);
                while (--b)
                    do_rra(dbla, dblb);
            }
            else
            {
                int     b = ft_backwardB(dbla, dblb, c, c[0], 0);
                while (--b)
                    do_rra(dbla, dblb);
            }
        }
    }
    while (dblb->first)
        do_pa(dbla, dblb);
    free(c);
}

int     size_array(int *tab, int size)
{
    int     i;
    
    i = 0;
    while (tab[i])
        i++;
    return (size);
}

int     ft_same(dblist *dbla, int *bubbled)
{
    int     i;
    p_list  *a;

    i = 0;
    a = dbla->first;
    while (a && bubbled[i])
    {
        if (a->content != bubbled[i])
            return (1);
        a = a->next;
        i++;
    }
    return (0);
}

int     ft_is_croissant(dblist *dbla)
{
    int     i;
    int     tmp;
    p_list  *a;

    i = 0;
    a = dbla->first;
    tmp = -2147483648;
    while (a)
    {
        if (a->content < tmp)
            return (1);
        tmp = a->content;
        a = a->next;
        i++;
    }
    return (0);
}

int     *list_to_array(dblist *dbl)
{
    int     i;
    int     *tab;
    p_list  *a;

    i = 0;
    tab = malloc((sizeof(int*) * ft_dblist_size(dbl)) + 8);
    a = malloc(sizeof(p_list));
    a = dbl->first;
    while (a != NULL)
    {
        tab[i] = a->content;
        i++;
        a = a->next;
    }
    tab[i] = '\0';
    return (tab);
}

int         main(int argc, char **argv)
{   
    p_coor  coor;
    dblist  *dbla;
    dblist  *dblb;

    dbla = malloc(sizeof(dblist));
    dblb = malloc(sizeof(dblist));
    char **splited = NULL;
    ft_init_dblist(dbla);
    ft_init_dblist(dblb);
    if (argc == 2)
    {
        splited = ft_split(argv[1], ' ');
        argc = ft_fill_stack(splited, dbla);
        argc++;
    }
    else
        ft_fill_stack(argv + 1, dbla);
    display_lists(dbla, dblb);
    display_tab(ft_reverse_bubble(list_to_array(dbla), ft_dblist_size(dbla)), ft_dblist_size(dbla));
    // display_listttttt(dbla, dblb);
    // ft_init_first_coor(&coor, argc);
    argc -= 1;
    ft_fill_first_coor(&coor, dbla);
    
    display_tab(list_to_array(dbla), ft_dblist_size(dbla));
    int *tab = ft_bubble(list_to_array(dbla), ft_dblist_size(dbla));
    display_tab(tab, ft_dblist_size(dbla));
    choose_sort_stack(dbla, dblb, &coor);
    display_lists(dbla, dblb);
    return (0);
}