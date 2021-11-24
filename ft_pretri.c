#include "push_swap.h"

void    ft_quatre_split(dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;
    int     j;
    int     med;

    j = 0;
    size = ft_dblist_size(dbla);
    i = 0;
    med = ft_get_med(list_to_array(dbla), size);
    printf(" MA MEDIANE DANS SPOLIT 4%d \n", ft_get_med(list_to_array(dbla), size));
    while (j <= size / 2 && i - 1 < size)
    {
        if (dbla->first->content <= med)
        {
            do_pb(dbla, dblb);
            j++;
        }
        else
            do_ra(dbla, dblb);
        i++;
    }
}

int    ft_splitter(dblist *dbla, dblist *dblb, int until, int div_med)
{
    int     size_list;
    int     i;
    int     med;

    size_list = ft_dblist_size(dbla);
    i = 0;
    // display_lists(dbla, dblb);
    int b = 0;
    
    while (ft_dblist_size(dbla) >= until)
    {
        if (ft_dblist_size(dbla) <= 10)
            return (0);
        med = ft_get_med_div(list_to_array(dbla), div_med, ft_dblist_size(dbla));
        printf("valeur de mediane = %d ///// size_list = %d et de until : %d \n", med, size_list, until);
        i++;
        if (dbla->first->content <= med)
        {
            do_pb(dbla, dblb);
            b++;    
        }
        else
            do_ra(dbla, dblb);
    }
    // printf("A Chunk size is %d\n", b);
    return (i); 
}

void    sort_more_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor)
{
	while (ft_dblist_size(dbla) > coor->total / 6 && ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, ft_dblist_size(dbla) / 10, 12);
    while (ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, ft_dblist_size(dbla) / 5, 2);
    if (ft_dblist_size(dbla) >= 6 && ft_dblist_size(dbla) <= 10)
		ft_quatre_split(dbla, dblb);
	ft_do(dbla, dblb, coor);
}

void    sort_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor)
{
    //REGARDER ICI ENTRE /2 et /4
	while (ft_dblist_size(dbla) > coor->total / 2 && ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, ft_dblist_size(dbla) / 10, 5);
	while (ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, ft_dblist_size(dbla) / 5, 2);
	if (ft_dblist_size(dbla) >= 6 && ft_dblist_size(dbla) <= 10)
		ft_quatre_split(dbla, dblb);
    printf("HELLO");
	ft_do(dbla, dblb, coor);
}