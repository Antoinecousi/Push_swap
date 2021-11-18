#include "push_swap.h"

int	    utils_sort_three(dblist *dbla, dblist *dblb)
{
	if (ft_dblist_size(dbla) == 1)
		return (0);
	if (ft_dblist_size(dbla) == 2)
	{
		if (dbla->first->content > dbla->first->next->content)
			do_sa(dbla, dblb);
		return (-1);
	}
	if (dbla->first->content < dbla->first->next->content
		&& dbla->first->next->content < dbla->first->next->next->content)
		return (-1);
	return (0);
}

void	a_bigger_than_b(dblist *dbla, dblist *dblb)
{
	if (dbla->first->next->content > dbla->first->next->next->content)
	{
		do_sa(dbla, dblb);
		do_rra(dbla, dblb);
	}
	else
	{
		if (dbla->first->content > dbla->first->next->next->content)
			do_ra(dbla, dblb);
		else
			do_sa(dbla, dblb);
	}
}

void	sort_three_numbers(dblist *dbla, dblist *dblb)
{
	if (utils_sort_three(dbla, dblb) == -1)
		return ;
	if (ft_dblist_size(dbla) == 1)
		return ;
	if (dbla->first->content > dbla->first->next->content)
		a_bigger_than_b(dbla, dblb);
	else
	{
		if (dbla->first->content > dbla->first->next->next->content)
			do_rra(dbla, dblb);
		else
		{
			do_sa(dbla, dblb);
			do_ra(dbla, dblb);
		}
	}
}

void	move_smallest_nbr_to_top(dblist *dbla, dblist *dblb, int size)
{
    int     *tab;
    int     *bubbled;

    tab = list_to_array(dbla);
    bubbled = ft_bubble(tab);
	if ((bubbled[0] == tab[3] && bubbled[1] == tab[4]) 
    || (bubbled[0] == tab[4] && bubbled[1] == tab[3]))
    {
        do_rra(dbla, dblb);
        do_rra(dbla, dblb);
        do_pb(dbla, dblb);
        do_pb(dbla, dblb);
    }
    else
        while (ft_dblist_size(dbla) > 3)
            if (dbla->first->content == bubbled[0] 
            || dbla->first->content == bubbled[1])
                do_pb(dbla, dblb);
            else
                do_ra(dbla, dblb);
}

void	sort_five_numbers(dblist *dbla, dblist *dblb)
{
	while (ft_dblist_size(dbla) > 3 && ft_same(dbla, ft_bubble(list_to_array(dbla))))
		move_smallest_nbr_to_top(dbla, dblb, ft_dblist_size(dbla));
	sort_three_numbers(dbla, dblb);
	while (ft_dblist_size(dblb) > 0 && ft_dblist_size(dbla) < 5)
		do_pa(dbla, dblb);
	if (dbla->first->content > dbla->first->next->content)
		do_sa(dbla, dblb);
}

void	choose_sort_stack(dblist *dbla, dblist *dblb)
{
	if (ft_dblist_size(dbla) <= 3)
		sort_three_numbers(dbla, dblb);
	else if (ft_dblist_size(dbla) > 3 && ft_dblist_size(dbla) <= 5)
		sort_five_numbers(dbla, dblb);
	// else if (ft_dblist_size(dbla) > 5 && ft_dblist_size(dbla) <= 500)
	// 	sort_more_than_five_numbers(dbla, dblb);
	else
		return ;
}