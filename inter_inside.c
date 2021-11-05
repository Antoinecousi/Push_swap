#include "push_swap.h"

int    ft_recursiveShitForwardA(dblist *dbla, dblist *dblb, int *tab, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dbla->first->content != tab[1] && ft_next_seeked(list_to_array(dbla), tab[1]) > 1)
        do_ra(dbla, dblb);
    while (dbla->first->content != tab[1] && ft_next_seeked(list_to_array(dbla), tab[1]) <= 1)
        do_rra(dbla, dblb);
    do_pb(dbla, dblb);
    tab = ft_bubble(list_to_array(dbla));
    if ((nbr_inter_forward(list_to_array(dbla), tab, final, lol - 1)) > 0)
        i = ft_recursiveShitForwardA(dbla, dblb, tab, final, lol);
    else
    {
        while (dbla->first->content != tab[0] && ft_next_seeked(list_to_array(dbla), tab[0]) > 1)
            do_ra(dbla, dblb);
        while (dbla->first->content != tab[0] && ft_next_seeked(list_to_array(dbla), tab[0]) <= 1)
            do_rra(dbla, dblb);
        do_pb(dbla, dblb);
    }
    do_sb(dbla, dblb);
    if (lol > 1)
    {
        do_rb(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_backwardA(dblist *dbla, dblist *dblb, int *tab, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dbla->first->content != tab[1] && ft_next_seeked(list_to_array(dbla), tab[1]) > 1)
        do_ra(dbla, dblb);
    while (dbla->first->content != tab[1] && ft_next_seeked(list_to_array(dbla), tab[1]) <= 1)
        do_rra(dbla, dblb);
    do_pb(dbla, dblb);
    tab = ft_bubble(list_to_array(dbla));
    if ((nbr_inter_backward(list_to_array(dbla), tab, final, lol - 1)) > 0)
        i = ft_backwardA(dbla, dblb, tab, final, lol);
    else
    {
        while (dbla->first->content != tab[0] && ft_next_seeked(list_to_array(dbla), tab[0]) > 1)
            do_ra(dbla, dblb);
        while (dbla->first->content != tab[0] && ft_next_seeked(list_to_array(dbla), tab[0]) <= 1)
            do_rra(dbla, dblb);
        do_pb(dbla, dblb);
    }
    do_sb(dbla, dblb);
    if (lol > 1)
    {
        do_rb(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_forwardB(dblist *dbla, dblist *dblb, int *tab, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dblb->first->content != tab[1] && ft_next_seeked(list_to_array(dblb), tab[1]) > 1)
        do_rb(dbla, dblb);
    while (dblb->first->content != tab[1] && ft_next_seeked(list_to_array(dblb), tab[1]) <= 1)
        do_rrb(dbla, dblb);
    if (dblb->first->content == tab[1])
        do_pa(dbla, dblb);
    tab = ft_reverse_bubble(list_to_array(dblb));
    if (nbr_inter_forward(list_to_array(dblb), tab, final, lol - 1) > 0)
        i = ft_forwardB(dbla, dblb, tab, final, lol);
    else
    {
        while (dblb->first->content != tab[0] && ft_next_seeked(list_to_array(dblb), tab[0]) > 1)
            do_rb(dbla, dblb);
        while (dblb->first->content != tab[0] && ft_next_seeked(list_to_array(dblb), tab[0]) <= 1)
            do_rrb(dbla, dblb);
        do_pa(dbla, dblb);
    }
    do_sa(dbla, dblb);
    if (lol > 1)
    {
        do_ra(dbla, dblb);
        i++;
    }
    return (i);
}

int    ft_backwardB(dblist *dbla, dblist *dblb, int *tab, int final, int lol)
{
    int     i = 1;

    lol++;
    while (dblb->first->content != tab[1] && ft_next_seeked(list_to_array(dblb), tab[1]) > 1)
        do_rb(dbla, dblb);
    while (dblb->first->content != tab[1] && ft_next_seeked(list_to_array(dblb), tab[1]) <= 1)
        do_rrb(dbla, dblb);
    if (dblb->first->content == tab[1])
        do_pa(dbla, dblb);
    tab = ft_reverse_bubble(list_to_array(dblb));
    if (nbr_inter_backward(list_to_array(dblb), tab, final, lol - 1) > 0)
        i = ft_backwardB(dbla, dblb, tab, final, lol);
    else
    {
        while (dblb->first->content != tab[0] && ft_next_seeked(list_to_array(dblb), tab[0]) > 1)
            do_rb(dbla, dblb);
        while (dblb->first->content != tab[0] && ft_next_seeked(list_to_array(dblb), tab[0]) <= 1)
            do_rrb(dbla, dblb);   
        do_pa(dbla, dblb);
    }
    do_sa(dbla, dblb);
    if (lol > 1)
    {
        do_ra(dbla, dblb);
        i++;
    }
    return (i);
}