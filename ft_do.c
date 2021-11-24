#include "push_swap.h"

void    do_ra(dblist *dbla, dblist *dblb)
{
    printf("RA        ");
    ft_ra(dbla);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_rra(dblist *dbla, dblist *dblb)
{
    printf("RRA       ");
    ft_rra(dbla);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_rb(dblist *dbla, dblist *dblb)
{
    printf("RB        ");
    ft_rb(dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_rrb(dblist *dbla, dblist *dblb)
{
    printf("RRB       ");
    ft_rrb(dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_pb(dblist *dbla, dblist *dblb)
{
    printf("PB        ");
    ft_pb(dbla, dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_pa(dblist *dbla, dblist *dblb)
{
    printf("PA        ");
    ft_pa(dbla, dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_rrr(dblist *dbla, dblist *dblb)
{
    printf("RRR       ");
    ft_rrr(dbla, dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_rr(dblist *dbla, dblist *dblb)
{
    printf("RR        ");
    ft_rr(dbla, dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_ss(dblist *dbla, dblist *dblb)
{
    printf("SS        ");
    ft_ss(dbla, dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_sa(dblist *dbla, dblist *dblb)
{
    printf("SA        ");
    ft_sa(dbla);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}

void    do_sb(dblist *dbla, dblist *dblb)
{
    printf("SB        ");
    ft_sb(dblb);
    display_lists(dbla, dblb);
    // list_to_array(dbla);
    // list_to_array(dblb);
}