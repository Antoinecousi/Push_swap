#include "push_swap.h"

void    sort_more_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor)
{
	while (ft_dblist_size(dbla) > coor->total / 6 && ft_dblist_size(dbla) > 9)
		ft_splitter(dbla, dblb, coor->total, ft_dblist_size(dbla) / 10, 12);
	while (ft_dblist_size(dbla) > coor->total / 20 && ft_dblist_size(dbla) > 9)
		ft_splitter(dbla, dblb, coor->total, ft_dblist_size(dbla) / 5, 4);
	if (ft_dblist_size(dbla) >= 6 && ft_dblist_size(dbla) <= 10)
		ft_quatre_split(coor, dbla, dblb);
	ft_do(dbla, dblb, coor);
}

void    sort_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor)
{
	while (ft_dblist_size(dbla) > coor->total / 4 && ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, coor->total, ft_dblist_size(dbla) / 10, 4);
	while (ft_dblist_size(dbla) > coor->total / 4 && ft_dblist_size(dbla) > 10)
		ft_splitter(dbla, dblb, coor->total, ft_dblist_size(dbla) / 5, 2);
	if (ft_dblist_size(dbla) >= 6 && ft_dblist_size(dbla) <= 10)
		ft_quatre_split(coor, dbla, dblb);
	ft_do(dbla, dblb, coor);
}