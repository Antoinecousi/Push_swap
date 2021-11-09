#include "push_swap.h"

int     ft_decoupage(p_coor *coor, dblist *dbla, dblist *dblb, int size)
{ 
    int     i;
    int     total;

    i = 1;
    total = 0;
    total += ft_splitter(coor, dbla, dblb);
    while (i++ < size / 50)
    {
        while (ft_dblist_size(dbla) > 33)
                total += ft_splitter(coor, dbla, dblb);
        while (ft_dblist_size(dblb) > 33)
                total += ft_splitterb(coor, dbla, dblb);
    }
    // while (ft_dblist_size(dbla) > 50)
    //         total += ft_splitter(coor, dbla, dblb);
    printf("ITS THE END OF THE SPLITTING \n");
    printf("total is equal = %d\n", total);
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
    int b = 0;
    printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
    while (i < size)
    {
        i++;
        if (dbla->first->content < coor->med)
        {
            do_pb(dbla, dblb);
            b++;    
        }
        else
            do_ra(dbla, dblb);
    }
    printf("Chunk size is %d\n", b);
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
    int b = 0;
    printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
    while (i < size)
    {
        if (dblb->first->content > coor->med)
        {
            do_pa(dbla, dblb);
            b++;
        }
        else
            do_rb(dbla, dblb);
        i++;
    }
    printf("Chunk size is %d\n", b);
    return (i);
}