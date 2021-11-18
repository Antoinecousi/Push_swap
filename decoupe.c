#include "push_swap.h"

int     ft_decoupage(p_coor *coor, dblist *dbla, dblist *dblb, int size)
{ 
    int     i;
    int     total;

    int     *toto = ft_bubble(list_to_array(dbla));
    i = 1;
    // total = 0;
    // total += ft_splitter(coor, dbla, dblb);
    // while (i++ < 2)
    // {
    //     while (ft_dblist_size(dbla) > 2)
    //         total += ft_splitter(coor, dbla, dblb);
    //     if (dbla->first->content > dbla->first->next->content)
    //         do_sa(dbla, dblb);
    //     while (ft_dblist_size(dblb) > 2)
    //         total += ft_splitterb(coor, dbla, dblb);
    // }
    ft_recursiveshit(coor, dbla, dblb);
    // while (ft_dblist_size(dbla) > 50)
    //         total += ft_splitter(coor, dbla, dblb);
    // printf("ITS THE END OF THE SPLITTING \n");
    // printf("total is equal = %d\n", total);
    return (1);
}

int     *ft_tab_reducer(int lenght, int *tab)
{
    int     *copy;
    int     i;

	i = 0;
    if (!(copy = malloc(sizeof(int) * (lenght + 8))))
        return (0);
	if (!tab || !copy)
		return (NULL);
	if (lenght != 0)
	{
		while (tab[i] != '\0' && i < (lenght - 1))
		{
			copy[i] = tab[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}

int     ft_recursiveshit(p_coor *coor, dblist *dbla, dblist *dblb)
{
    int     size;
    int     i;

    size = ft_dblist_size(dbla);
    i = 0;
    // display_lists(dbla, dblb);
    coor->med = ft_get_med(list_to_array(dbla));
    int b = 0;
    // printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
    while (b < size / 2 && ft_dblist_size(dbla) > 2)
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
    if (ft_dblist_size(dbla) > 2 && ft_is_croissant(dbla))
        ft_recursiveshit(coor, dbla, dblb);
    // printf("My next chunk is : %d !!\n", b);
    ft_secondrecurs(coor, dbla, dblb, b, coor->med);
    return (1);
}

int     ft_secondrecurs(p_coor *coor, dblist *dbla, dblist *dblb, int size, int med)
{
    int     med2;
    int     j;
    int     i;
    int     *tab;

    i = 0;
    j = 0;
    tab = ft_tab_reducer(size, list_to_array(dblb));
    med2 = ft_get_med(tab);
    while (j < size / 2)
    {
        if (dblb->first->content >= med2)
        {
            do_pa(dbla, dblb);
            j++;
        }
        else
        {
            do_rb(dbla, dblb);
            i++;
        }
        //mettre une fonction rrb car si je reste ds la mm chunk javance qd cest en dessous, et je vais reparcourir toute la stack.
    }
    while (i--)
        do_rrb(dbla, dblb);
    if (size == 2)
        if (dblb->first->content < dblb->first->next->content)
            do_sb(dbla, dblb);
    if (size > 2)
        ft_secondrecurs(coor, dbla, dblb, size - j, med);
    if (size == 2)
        {
            do_pa(dbla, dblb);
            do_pa(dbla, dblb);
        }
    return (78);
}

int    ft_splitter(dblist *dbla, dblist *dblb, int size, int until, int div_med)
{
    int     size_list;
    int     i;
    int     med;

    size_list = ft_dblist_size(dbla);
    i = 0;
    // display_lists(dbla, dblb);
    int b = 0;
    while (ft_dblist_size(dbla) > 25)
    {
        med = ft_get_med_div(list_to_array(dbla), div_med);
        // printf("valeur de mediane = %d ///// size_list = %d et de until : %d \n", med, size_list, until);
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

int    ft_splitterb(dblist *dbla, dblist *dblb, int size, int until, int div_med)
{
    int     size_list;
    int     i;
    int     med;

    size_list = ft_dblist_size(dblb);
    med = ft_get_med_div_b(list_to_array(dblb), div_med);
    // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
    i = 0;
    // display_lists(dbla, dblb);
    int b = 0;
    while (b < until)
    {
        med = ft_get_med_div_b(list_to_array(dblb), div_med);
        // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
        if (dblb->first->content > med)
        {
            do_pa(dbla, dblb);
            b++;
        }
        else
            do_rb(dbla, dblb);
        i++;
    }
    // printf("B Chunk size is %d\n", b);
    return (i);
}

int    ft_splitterbdeux(dblist *dbla, dblist *dblb, int size, int until, int div_med)
{
    int     size_list;
    int     i;
    int     med;

    size_list = ft_dblist_size(dblb);
    i = 0;
    // display_lists(dbla, dblb);
    int b = 0;
    med = ft_get_med_div_b(list_to_array(dblb), div_med);
    // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
    while (b < until)
    {
        med = ft_get_med_div_b(list_to_array(dblb), div_med);
        // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
        if (dblb->first->content > med)
        {
            do_pa(dbla, dblb);
            b++;
        }
        else
            do_rb(dbla, dblb);
        i++;
    }
    // printf("B Chunk size is %d\n", b);
    return (i);
}

// int    ft_splitter(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;

//     size = ft_dblist_size(dbla);
//     i = 0;
//     display_lists(dbla, dblb);
//     coor->med = ft_get_med(list_to_array(dbla));
//     int b = 0;
//     printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
//     while (b + 1 < (size + 1) / 2)
//     {
//         i++;
//         if (dbla->first->content < coor->med)
//         {
//             do_pb(dbla, dblb);
//             b++;    
//         }
//         else
//             do_ra(dbla, dblb);
//     }
//     printf("A Chunk size is %d\n", b);
//     return (i);
// }

// int    ft_splitterb(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;

//     size = ft_dblist_size(dblb);
//     i = 0;
//     display_lists(dbla, dblb);
//     coor->med = ft_get_med(list_to_array(dblb));
//     int b = 0;
//     printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
//     while (b + 1 < (size + 1) / 2)
//     {
//         if (dblb->first->content > coor->med)
//         {
//             do_pa(dbla, dblb);
//             b++;
//         }
//         else
//             do_rb(dbla, dblb);
//         i++;
//     }
//     printf("B Chunk size is %d\n", b);
//     return (i);
// }