#include "push_swap.h"

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
    int     j = 0;
    c = ft_bubble(list_to_array(dbla));
    while (/*ft_same(dbla, c) &&*/ ft_dblist_size(dbla) > 1)
    {
        c = ft_bubble(list_to_array(dbla));
        if (dbla->first->content == c[0])
        {
            do_pb(dbla, dblb);
            i++;
        }
        else if (topOrBottomHard(list_to_array(dbla), c[1], c[0]) < topOrBottomHard(list_to_array(dbla), c[ft_dblist_size(dbla) - 2], c[ft_dblist_size(dbla) - 1]) + 2)
        {
            if (!ft_take_inter(list_to_array(dbla), c[1], c[0]))
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
        else
        {
            if (!ft_take_inter(list_to_array(dbla), c[size_array(c) - 2], c[size_array(c) - 1]))
            {
                while (dbla->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 1]) > 1)
                    do_ra(dbla, dblb);
                while (dbla->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 1]) <= 1)
                    do_rra(dbla, dblb);
                do_pb(dbla, dblb);
            }
            else
            {
                while (dbla->first->content != c[size_array(c) - 2] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 2]) > 1)
                    do_ra(dbla, dblb);
                while (dbla->first->content != c[size_array(c) - 2] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 2]) <= 1)
                    do_rra(dbla, dblb);
                do_pb(dbla, dblb);
                j++;
                i++;
                while (dbla->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 1]) > 1)
                    do_ra(dbla, dblb);
                while (dbla->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dbla), c[size_array(c) - 1]) <= 1)
                    do_rra(dbla, dblb);
                do_pb(dbla, dblb);
                do_rb(dbla, dblb);
            }
            do_rb(dbla, dblb);
            j++;
            i++;
        }
    }
    // ft_lowSampleSort(dbla, dblb, &coor);
    while (j--)
        do_rrb(dbla, dblb);
    while (i-- > 1)
        do_pa(dbla, dblb);
    // do_rra(dbla, dblb);
    j = 0;
    i = 0;
    while (dblb->first)
    {
        c = ft_reverse_bubble(list_to_array(dblb));
        if (dblb->first->content == c[0]) 
            do_pa(dbla, dblb);
        else if (topOrBottomHard(list_to_array(dblb), c[1], c[0]) < topOrBottomHard(list_to_array(dblb), c[ft_dblist_size(dblb) - 2], c[ft_dblist_size(dblb) - 1]) + 2)
            if (!ft_take_inter(list_to_array(dblb), c[1], c[0]))
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
        else
        {
            if (!ft_take_inter(list_to_array(dblb), c[size_array(c) - 2], c[size_array(c) - 1]))
            {
                while (dblb->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 1]) > 1)
                    do_rb(dbla, dblb);
                while (dblb->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 1]) <= 1)
                    do_rrb(dbla, dblb);
                do_pa(dbla, dblb);
            }
            else
            {
                while (dblb->first->content != c[size_array(c) - 2] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 2]) > 1)
                    do_rb(dbla, dblb);
                while (dblb->first->content != c[size_array(c) - 2] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 2]) <= 1)
                    do_rrb(dbla, dblb);
                do_pa(dbla, dblb);
                j++;
                i++;
                while (dblb->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 1]) > 1)
                    do_rb(dbla, dblb);
                while (dblb->first->content != c[size_array(c) - 1] && ft_next_seeked(list_to_array(dblb), c[size_array(c) - 1]) <= 1)
                    do_rrb(dbla, dblb);
                do_pa(dbla, dblb);
                do_ra(dbla, dblb);
            }
            do_ra(dbla, dblb);
            j++;
            i++;
        }
    }
    while (dblb->first)
        do_pa(dbla, dblb);
    display_lists(dbla, dblb);
    free(a);
    free(b);
}

int     size_array(int *tab)
{
    int     i;
    
    i = 0;
    while (tab[i])
        i++;
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
    // ft_quatre_split(&coor, dbla, dblb);
    // ft_cinq_split(&coor, dbla, dblb);
    // ft_six_split(&coor, dbla, dblb);
    // ft_sept_split(&coor, dbla, dblb);
    argc = 500;
    while (ft_dblist_size(dbla) > (argc - 1) / 24)
        ft_splitter(dbla, dblb, argc, argc - 1 - (4 * ft_dblist_size(dbla) / 5));
    while (ft_dblist_size(dblb) > (argc - 1) / 4)
        ft_splitterb(dbla, dblb, argc, argc - 1 - (9 / 10 * ft_dblist_size(dblb)));
    while (ft_dblist_size(dblb) > 1)
        ft_splitterbdeux(dbla, dblb, argc, argc - 1 - (3 / 4 * ft_dblist_size(dblb)));
    ft_decoupage(&coor, dbla, dblb, ft_dblist_size(dbla));
    ft_do(dbla, dblb, &coor);
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
    printf("prout");
    return (0);
}