#include "push_swap.h"

int     ft_decoupage(p_coor *coor, dblist *dbla, dblist *dblb)
{
    while (ft_dblist_size(dbla) > 10)
            ft_splitter(coor, dbla, dblb);
    while (ft_dblist_size(dblb) > 4)
            ft_splitterb(coor, dbla, dblb);
    while (ft_dblist_size(dbla) > 4)
            ft_splitter(coor, dbla, dblb);
    while (ft_dblist_size(dblb) > 50)
            ft_splitterb(coor, dbla, dblb);
    return (1);
}

int    ft_splitter(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;

    size = ft_dblist_size(dbla);
    i = 0;
    display_lists(dbla, dblb);
    coor->med = ft_get_med(list_to_array(dbla));
    printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
    while (i < size)
    {
        i++;
        if (dbla->first->content < coor->med)
        {
            do_pb(dbla, dblb);
        }
        else
            do_ra(dbla, dblb);
    }
    return (i);
}

int    ft_splitterb(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;

    size = ft_dblist_size(dblb);
    i = 0;
    display_lists(dbla, dblb);
    coor->med = ft_get_med(list_to_array(dblb));
    while (i < size)
    {
        if (dblb->first->content > coor->med)
        {
            do_pa(dbla, dblb);
        }
        else
            do_rb(dbla, dblb);
        i++;
    }
    return (i);
}