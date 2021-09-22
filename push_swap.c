#include "push_swap.h"

int     ft_intermed_second(int *tab, int *bubbled, int final, int max)
{
    int     i = 0;
    int     posInterm = 0;
    int     wesh = 0;

    
    while (tab[i] != final)
        if (tab[i] == bubbled[1])
            posInterm = i + 1;
        i++;
    if (posInterm == 0)
    {
        int     size = size_array(bubbled);
        while (tab[size - wesh] != final)
            if (tab[size - wesh] == bubbled[1])
                posInterm = (wesh * (-1)) - 1;
            wesh++;
    }
    if (posInterm < i - max && posInterm > 0)
        return (posInterm);
    printf("%d\n", posInterm);
    printf("%d\n", i - max);
    if ((-1) * posInterm < i - max && posInterm < 0)
        return (posInterm);
    return (0);
}

int     ft_intermed_first(int *tab, int *bubbled, int final)
{
    int     i = 0;
    int     posInterm = 0;

    while (tab[posInterm] != final)
    {
        // printf("Is %d == %d?\n", tab[posInterm], final);
        if (tab[posInterm] == bubbled[1])
        {
            posInterm++;
            return (posInterm);
        }
        posInterm++;
    }
    return (0);
}

int     ft_intermed_backward(int *tab, int *bubbled, int final)
{
    int     i = 0;
    int     posInterm = 0;

    while (tab[posInterm] != final)
    {
        // printf("Is %d == %d?\n", tab[posInterm], final);
        if (tab[posInterm] == bubbled[1])
        {
            posInterm++;
            return (posInterm);
        }
        posInterm++;
    }
    return (0);
}

int     nbr_inter(int *tab, int *bubbled, int last)
{
    i_coor  ins;
    int     i;
    int     posLast;
    int     size;
    int     pipi;
    int     distance;
    
    size = (tab);
    posLast = 0;
    i = 0;
    while (tab[i++] != last)
        ins.distanceTot++;
    i = 0;
    //amelioration de ca?
    while (tab[i] != last && i < posLast - 2)
    {
        pipi = 1;
        while (pipi + 3 < (posLast - i) / 2)
        {
            size = size_array(tab);
            if (i - pipi >= 0)
                size = i;
            if (tab[size - pipi] == bubbled[ins.tot + 1])
            {
                if (ins.tot == 0)
                    ins.firstPos = i + 1;
                ins.tot++;
                ins.totrr += pipi;
                pipi = 214647483642;
            }
            pipi++;
        }
        if (tab[i] == bubbled[ins.tot + 1])
        {
            if (ins.tot == 0)
                ins.firstPos = i + 1;
            ins.tot++;
            ins.lastPos = i;
        }
        i++;
    }
    if (ins.firstPos == 0)
        return (0);
    int algoenpassant = ins.distanceTot + (3 * ins.tot) + ins.totrr * 2 + 2;
    int normal = ins.distanceTot * 2 - ins.firstPos * 2 + ins.lastPos + ins.totrr;
    return (ins.distanceTot - (3 * ins.tot) - ins.firstPos * 2 + ins.lastPos - ins.totrr - 1);
}

int    ft_recursiveShitForwardA(dblist *dbla, dblist *dblb, int *tab, int final, int lol, int dir, int total)
{
    int     i = 1;

    lol++;
    while (dbla->first->content != tab[1] && dir > 0)
    {
        printf("RA       ");
        ft_ra(dbla);
        display_lists(dbla, dblb);
    }
    while (dbla->first->content != tab[1] && dir < 0)
    {
        printf("RRA       ");
        ft_rra(dbla);
        display_lists(dbla, dblb);
    }
    printf("PB       ");
    ft_pb(dbla, dblb);
    display_lists(dbla, dblb);
    tab = ft_bubble(list_to_array(dbla));
    if ((dir = nbr_inter(list_to_array(dbla), tab, final)) > 0)
        i = ft_recursiveShitForwardA(dbla, dblb, tab, final, lol, dir, total);
    else
    {
        while (dbla->first->content != final)
        {
            printf("RA       ");
            ft_ra(dbla);
            display_lists(dbla, dblb);
        }
        printf("PB       ");
        ft_pb(dbla, dblb);
        display_lists(dbla, dblb);
    }
        printf("SB       ");
        ft_sb(dblb);
        display_lists(dbla, dblb);
    if (lol > 1)
    {
        printf("RB       ");
        ft_rb(dblb);
        display_lists(dbla, dblb);
        i++;
    }
    return (i);
}
    
void    ft_do(dblist *dbla, dblist *dblb, p_coor *coor) 
{
    printf("\nENTERING FT_DO : \n");
    int     *a;
    int     *b;
    int     *c;
    a = ft_bubble(list_to_array(dbla));
    b = ft_bubble(list_to_array(dblb));
    int     i;
    int     lower = a[0];
    i = 0;
    c = ft_bubble(list_to_array(dbla));
    // ft_preworkout()
    while (ft_same(dbla, c))
    {
        c = ft_bubble(list_to_array(dbla));
        if (dbla->first->content == c[0])
        {
            printf("PB        ");
            ft_pb(dbla, dblb);
            display_lists(dbla, dblb);
            i++;
        }
        else if (ft_next_lower(list_to_array(dbla)) > 0)
        {
            if (!ft_intermed_first(list_to_array(dbla), c, c[0]))
            {
                while (dbla->first->content != c[0])
                {
                    printf("RA       ");
                    ft_ra(dbla);
                    display_lists(dbla, dblb);
                }  
            }
            else 
            {
                printf("ENTERING RECURSIVE : \n");
                int     b = ft_recursiveShitForwardA(dbla, dblb, c, c[0], 0, 1, ft_next_lower(list_to_array(dbla)));
                while (--b)
                {
                    printf("RRB       ");
                    ft_rrb(dblb);
                    display_lists(dbla, dblb);
                }
                printf("END OF RECURSIVE LOL\n");
            }
        }
        else 
        {
            if (!ft_intermed_lower(list_to_array(dbla), c))
                while (dbla->first->content != c[0])
                {
                    printf("RRA      ");
                    ft_rra(dbla);
                    display_lists(dbla, dblb);
                }  
            else 
            {
                while (dbla->first->content != c[1])
                {
                    printf("RRA      ");
                    ft_rra(dbla);
                    display_lists(dbla, dblb);
                }
                printf("PB        ");
                ft_pb(dbla, dblb);
                display_lists(dbla, dblb);
                i++;
                while (dbla->first->content != c[0])
                {
                    printf("RRA       ");
                    ft_rra(dbla);
                    display_lists(dbla, dblb);
                }
                printf("PB        ");
                ft_pb(dbla, dblb);
                display_lists(dbla, dblb);
                i++;
                printf("SB        ");
                ft_sb(dblb);
                display_lists(dbla, dblb);
            }
        }
    }
    while (i-- > 1)
    {            
        printf("PA        ");
        ft_pa(dbla, dblb);
        display_lists(dbla, dblb);
    }
    i = 0;
    while (dblb->first)
    {
        c = ft_bubble(list_to_array(dblb));
        if (dblb->first->content == c[ft_dblist_size(dblb) - 1])
        {
            printf("PA        ");
            ft_pa(dbla, dblb);
            display_lists(dbla, dblb);
            i++;
        }
        else if (ft_next_lower(list_to_array(dblb)) > 1)
        {
            while (dblb->first->content != c[ft_dblist_size(dblb) - 1])
            {
                printf("RRB       ");
                ft_rrb(dblb);
                display_lists(dbla, dblb);
            }
        }
        else 
            while (dblb->first->content != c[ft_dblist_size(dblb) - 1])
            {
                printf("RB       ");
                ft_rb(dblb);
                display_lists(dbla, dblb);
            }
    }
    while (dblb->first)
    {            
        printf("PA        ");
        ft_pa(dbla, dblb);
        display_lists(dbla, dblb);
    }
    printf("RESULTATS FINAUX \n \n");
    display_lists(dbla, dblb);
    free(a);
    free(b);
}

int     ft_intermed_lower(int *tab, int *bubbled)
{
    int     posInterm = 0;

    if (ft_next_lower(tab) > 1)
    {
        while (tab[posInterm] != bubbled[0])
        {
            if (tab[posInterm] == bubbled[1])
                return (posInterm);
            posInterm++;
        }
    }
    else
    {
        int size = size_array(tab);
        while (tab[size] != bubbled[0])
        {
            if (tab[size] == bubbled[1])
                return (posInterm);
            posInterm++;
            size--;
        }
    }
    return (0);
}

int     size_array(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i])
    {
        i++;
    }
    return (i);
}

int     is_sup(dblist *dbl)
{
    p_list  *a;

    a = dbl->first;
    if (ft_dblist_size(dbl) < 2)
        return (0);
    if (a->content > a->next->content)
        return (1);
    return (0);
}

void    ft_first_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     *tab;

    tab = ft_bubble(list_to_array(dbla));
    size = ft_dblist_size(dbla);
    i = 0;
    printf("Base is :");
    display_lists(dbla, dblb);
    while (size / 2 > i)
    {
        if (dbla->first->content < coor->med)
        {
            printf("PB       ");
            ft_pb(dbla, dblb);
            display_lists(dbla, dblb);
            i++;
        }
        else
        {
            printf("RA       ");
            ft_ra(dbla);
            display_lists(dbla, dblb);
        }
        tab = ft_bubble(list_to_array(dbla));
    }
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

int     *list_to_array(dblist *dbl)
{
    int     i;
    int     *tab;
    p_list  *a;

    i = 0;
    tab = malloc(1000);
    a = dbl->first;
    while (a)
    {
        tab[i] = a->content;
        i++;
        a = a->next;
    }
    tab[i] = '\0';
    return (tab);
}

int     main(int argc, char **argv)
{   

    p_coor  coor;
    dblist *dbla;
    dblist *dblb;

    dbla = malloc(1000);
    dblb = malloc(1000);
   // if (ft_checker(argv, argc))
    //    return (ft_error);
    ft_init_first_coor(&coor);
    ft_init_dblist(dbla);
    ft_init_dblist(dblb);
    //ft_fill_coor(&coor, argv, argc);
    ft_fill_stack(argv, dbla);
    //list_to_array(dbla);
    ft_fill_first_coor(&coor, dbla);
    if (argc > 4)
    {
        ft_first_split(&coor, dbla, dblb);
        ft_do(dbla, dblb, &coor);
    }
    p_list *a;
    p_list *b;
    a = dbla->first;
    b = dblb->first;
    while (a)
    {
        printf("%d ", a->content);
        a = a->next;
    }
    printf("\n");
    while (b)
    {
        printf("%d ", b->content);
        b = b->next;
    }
    return (0);
}