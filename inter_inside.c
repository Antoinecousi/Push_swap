#include "push_swap.h"

int    ft_forwardA(dblist *dbla, dblist *dblb, int *bub, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dbla->first->content != bub[1] && ft_next_seeked(list_to_array(dbla), bub[1]) > 1)
        do_ra(dbla, dblb);
    while (dbla->first->content != bub[1] && ft_next_seeked(list_to_array(dbla), bub[1]) <= 1)
        do_rra(dbla, dblb);
    do_pb(dbla, dblb);
    bub = ft_bubble(list_to_array(dbla), ft_dblist_size(dbla));
    // if ((nbr_inter_forward(list_to_array(dbla), bub, final, lol - 1)) > 0)
    //     i = ft_forwardA(dbla, dblb, bub, final, lol);
    // else
    // {
        while (dbla->first->content != bub[0] && ft_next_seeked(list_to_array(dbla), bub[0]) > 1)
            do_ra(dbla, dblb);
        while (dbla->first->content != bub[0] && ft_next_seeked(list_to_array(dbla), bub[0]) <= 1)
            do_rra(dbla, dblb);
        do_pb(dbla, dblb);
    // }
    do_sb(dbla, dblb);
    if (lol > 1)
    {
        do_rb(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_backwardA(dblist *dbla, dblist *dblb, int *bub, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dbla->first->content != bub[1] && ft_next_seeked(list_to_array(dbla), bub[1]) > 1)
        do_ra(dbla, dblb);
    while (dbla->first->content != bub[1] && ft_next_seeked(list_to_array(dbla), bub[1]) <= 1)
        do_rra(dbla, dblb);
    do_pb(dbla, dblb);
    bub = ft_bubble(list_to_array(dbla), ft_dblist_size(dbla));
    // if ((nbr_inter_backward(list_to_array(dbla), bub, final)) > 0)
    //     i = ft_backwardA(dbla, dblb, bub, final, lol);
    // else
    // {
        while (dbla->first->content != bub[0] && ft_next_seeked(list_to_array(dbla), bub[0]) > 1)
            do_ra(dbla, dblb);
        while (dbla->first->content != bub[0] && ft_next_seeked(list_to_array(dbla), bub[0]) <= 1)
            do_rra(dbla, dblb);
        do_pb(dbla, dblb);
    // }
    do_sb(dbla, dblb);
    if (lol > 1)
    {
        do_rb(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_forwardB(dblist *dbla, dblist *dblb, int *bub, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dblb->first->content != bub[1] && ft_next_seeked(list_to_array(dblb), bub[1]) > 1)
        do_rb(dbla, dblb);
    while (dblb->first->content != bub[1] && ft_next_seeked(list_to_array(dblb), bub[1]) <= 1)
        do_rrb(dbla, dblb);
    if (dblb->first->content == bub[1])
        do_pa(dbla, dblb);
    bub = ft_reverse_bubble(list_to_array(dblb), ft_dblist_size(dblb));
    // if (nbr_inter_forward(list_to_array(dblb), bub, final, lol - 1) > 0)
    //     i = ft_forwardB(dbla, dblb, bub, final, lol);
    // else
    // {
        while (dblb->first->content != bub[0] && ft_next_seeked(list_to_array(dblb), bub[0]) > 1)
            do_rb(dbla, dblb);
        while (dblb->first->content != bub[0] && ft_next_seeked(list_to_array(dblb), bub[0]) <= 1)
            do_rrb(dbla, dblb);
        do_pa(dbla, dblb);
    // }
    do_sa(dbla, dblb);
    if (lol > 1)
    {
        do_ra(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_backwardB(dblist *dbla, dblist *dblb, int *bub, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dblb->first->content != bub[1] && ft_next_seeked(list_to_array(dblb), bub[1]) > 1)
        do_rb(dbla, dblb);
    while (dblb->first->content != bub[1] && ft_next_seeked(list_to_array(dblb), bub[1]) <= 1)
        do_rrb(dbla, dblb);
    if (dblb->first->content == bub[1])
        do_pa(dbla, dblb);
    bub = ft_reverse_bubble(list_to_array(dblb), ft_dblist_size(dblb));
    // if (nbr_inter_backward(list_to_array(dblb), bub, final) > 0)
    //     i = ft_backwardB(dbla, dblb, bub, final, lol);
    // else
    // {
        while (dblb->first->content != bub[0] && ft_next_seeked(list_to_array(dblb), bub[0]) > 1)
            do_rb(dbla, dblb);
        while (dblb->first->content != bub[0] && ft_next_seeked(list_to_array(dblb), bub[0]) <= 1)
            do_rrb(dbla, dblb);   
        do_pa(dbla, dblb);
    // }
    do_sa(dbla, dblb);
    if (lol > 1)
    {
        do_ra(dbla, dblb);
        i++;
    }
    return (i);
}