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

int     ft_intermed_first(int *tab, int *bubbled, int final)
{
    int     i = 0;
    int     posInterm = 0;

    while (tab[posInterm] != final)
    {
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
        if (tab[posInterm] == bubbled[1])
        {
            posInterm++;
            return (posInterm);
        }
        posInterm++;
    }
    return (0);
}

i_coor  init_ins(i_coor ins)
{
    ins.firstPos = -1;
    ins.lastPos = 0;
    ins.tot = 0;
    ins.totrr = 0;
    ins.distanceTot = 0;
    return (ins);
}

void    ft_do(dblist *dbla, dblist *dblb, p_coor *coor)
{
    int     *a;
    int     *b;
    int     *c;
    a = ft_bubble(list_to_array(dbla));
    b = ft_bubble(list_to_array(dblb));
    int     i;
    int     lower = a[0];
    i = 0;
    c = ft_bubble(list_to_array(dbla));
    while (ft_same(dbla, c) && ft_dblist_size(dbla) > 5)
    {
        c = ft_bubble(list_to_array(dbla));
        if (dbla->first->content == c[0])
        {
            do_pb(dbla, dblb);
            i++;
        }
        else if (!ft_take_inter(list_to_array(dbla), c[1], c[0]))
        {
            while (dbla->first->content != c[0] && ft_next_seeked(list_to_array(dbla), c[0]) > 1)
                do_ra(dbla, dblb);
            while (dbla->first->content != c[0] && ft_next_seeked(list_to_array(dbla), c[0]) <= 1)
                do_rra(dbla, dblb);
            do_pb(dbla, dblb);
        }
        else 
        {
            if (ft_direction_after_inter(list_to_array(dbla), c[1], c[0]) >= 1)
            {
                printf("ENTERING FORWARD A : \n");
                int     b = ft_recursiveShitForwardA(dbla, dblb, c, c[0], 0);
                while (--b)
                    do_rrb(dbla, dblb);
                printf("END OF FORWARD A\n");
            }
            else 
            {
                printf("ENTERING BACKWARD A : \n");
                int     b = ft_backwardA(dbla, dblb, c, c[0], 0);
                while (--b)
                    do_rrb(dbla, dblb);
                printf("END OF BACKWARD A\n");
            }
        }
    }
    // ft_lowSampleSort(dbla, dblb, &coor);
    while (i-- > 1)
        do_pa(dbla, dblb);
    i = 0;
    while (dblb->first)
    {
        c = ft_reverse_bubble(list_to_array(dblb));
        if (dblb->first->content == c[0]) 
            do_pa(dbla, dblb);
        else if (!ft_take_inter(list_to_array(dblb), c[1], c[0]))
        {
            while (dblb->first->content != c[0] && ft_next_seeked(list_to_array(dblb), c[0]) > 1)
                do_rb(dbla, dblb);
            while (dblb->first->content != c[0] && ft_next_seeked(list_to_array(dblb), c[0]) <= 1)
                do_rrb(dbla, dblb);
            do_pa(dbla, dblb);
        }
        else
        {
            if (ft_direction_after_inter(list_to_array(dblb), c[1], c[0]) >= 1)
            {
                printf("ENTERING FORWARD B : \n");
                int     b = ft_forwardB(dbla, dblb, c, c[0], 0);
                while (--b)
                    do_rra(dbla, dblb);
                printf("END OF FORWARD B\n");
            }
            else
            {
                printf("ENTERING BACKWARD B : \n");
                int     b = ft_backwardB(dbla, dblb, c, c[0], 0);
                while (--b)
                
                    do_rra(dbla, dblb);
                printf("END OF BACKWARD B\n");
            }
        }
    }
    while (dblb->first)
        do_pa(dbla, dblb);
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

    size = ft_dblist_size(dbla);
    i = 0;
    display_lists(dbla, dblb);
    printf(" ------ \n %d is my lower med \n", coor->Huitieme);
    while (i++ < size)
    {
        if (dbla->first->content < coor->Huitieme)
            do_pb(dbla, dblb);
        else
            do_ra(dbla, dblb);
    }
}

void    ft_second_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;

    size = ft_dblist_size(dbla);
    i = 0;
    display_lists(dbla, dblb);
    printf("%d is my med \n", coor->lowerMed);
    while (i++ < size)
    {
        if (dbla->first->content < coor->lowerMed)
            do_pb(dbla, dblb);
        else
            do_ra(dbla, dblb);
    }
}

void    ft_third_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;

    j = 0;
    size = ft_dblist_size(dbla);
    printf("%d is my upper med \n", coor->secHuitieme);
    i = 0;
    display_lists(dbla, dblb);
    while (i++ < size)
    {
        if (dbla->first->content < coor->secHuitieme)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
    }
    // while (j--)
    //     do_pa(dbla, dblb);
}

void    ft_quatre_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;

    j = 0;
    size = ft_dblist_size(dbla);
    printf("%d is my upper med \n", coor->med);
    i = 0;
    display_lists(dbla, dblb);
    while (i++ < size)
    {
        if (dbla->first->content < coor->med)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
    }
    // while (j--)
    //     do_pa(dbla, dblb);
}

void    ft_cinq_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;

    j = 0;
    size = ft_dblist_size(dbla);
    printf("%d is my upper med \n", coor->thiHuitieme);
    i = 0;
    display_lists(dbla, dblb);
    while (i++ < size)
    {
        if (dbla->first->content < coor->thiHuitieme)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
    }
    // while (j--)
    //     do_pa(dbla, dblb);
}

void    ft_six_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;

    j = 0;
    size = ft_dblist_size(dbla);
    printf("%d is my upper med \n", coor->upperMed);
    i = 0;
    display_lists(dbla, dblb);
    while (i++ < size)
    {
        if (dbla->first->content < coor->upperMed)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
    }
    // while (j--)
    //     do_pa(dbla, dblb);
}

void    ft_sept_split(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;

    j = 0;
    size = ft_dblist_size(dbla);
    printf("%d is my upper med \n", coor->fouHuitieme);
    i = 0;
    display_lists(dbla, dblb);
    while (i++ < size)
    {
        if (dbla->first->content < coor->fouHuitieme)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
    }
    // while (j--)
    //     do_pa(dbla, dblb);
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
    tab = malloc(1000000);
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

    dbla = malloc(1000000);
    dblb = malloc(1000000);
    char **splited = NULL;
    // if (ft_checker(argv, argc))
    //    return (ft_error);
    ft_init_first_coor(&coor);
    ft_init_dblist(dbla);
    ft_init_dblist(dblb);
    if (argc == 2)
    {
        splited = ft_split(argv[1], ' ');
        ft_fill_stack(splited, dbla);
    }
    else
        ft_fill_stack(argv + 1, dbla);
    //ft_fill_coor(&coor, argv, argc);
    //list_to_array(dbla);
    ft_fill_first_coor(&coor, dbla);
    // if (argc > 4)
    // {
    //    ft_pretri(&coor, dbla, dblb);
    // ft_first_split(&coor, dbla, dblb);
    // ft_second_split(&coor, dbla, dblb);
    // ft_third_split(&coor, dbla, dblb);
    ft_quatre_split(&coor, dbla, dblb);
    // ft_cinq_split(&coor, dbla, dblb);
    // ft_six_split(&coor, dbla, dblb);
    // ft_sept_split(&coor, dbla, dblb);
    ft_do(dbla, dblb, &coor);
    // }
    p_list *a;
    p_list *b;
    a = dbla->first;
    b = dblb->first;
    while (a)
    {
        // printf("%d ", a->content);
        a = a->next;
    }
    // printf("\n");
    while (b)
    {
        // printf("%d ", b->content);
        
        b = b->next;
    }
    return (0);
}