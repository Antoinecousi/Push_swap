#include "push_swap.h"

void    ft_sa(dblist *dbla)
{   
	p_list  *a;
	int     copy;
	int     copy2;

	if (ft_dblist_size(dbla) < 2)
		return  ;
	a = dbla->first;
	copy = a->content;
	a = a->next;
	copy2 = a->content;
	a->content = copy;
	a = dbla->first;
	a->content = copy2;
}

void    ft_sb(dblist *dblb)
{   
	p_list  *b;
	int     copy;
	int     copy2;

	if (ft_dblist_size(dblb) < 2)
		return  ;
	b = dblb->first;
	copy = b->content;
	b = b->next;
	copy2 = b->content;
	b->content = copy;
	b = dblb->first;
	b->content = copy2;
}

void    ft_ss(dblist *dbla, dblist *dblb)
{
	ft_sa(dbla);
	ft_sb(dblb);
}

void    ft_pa(dblist *dbla, dblist *dblb)
{
	p_list  *b;

	if (ft_dblist_size(dblb) < 1)
		return  ;
	b = dblb->first;
	ft_addfrontlist(dbla, b->content);
	dblb->first = b->next;
	if (!b->next)
		dblb->last = NULL;
	free(b);
}

void    ft_pb(dblist *dbla, dblist *dblb)
{
	p_list  *a;

	if (ft_dblist_size(dbla) < 1)
		return  ;
	a = dbla->first;
	ft_addfrontlist(dblb, a->content);
	dbla->first = a->next;
	if (!a->next)
		dbla->last = NULL;
	free(a);
}

void    ft_ra(dblist *dbla)
{
	p_list  *a;

	if (ft_dblist_size(dbla) < 2)
		return  ;
	a = dbla->first;
	ft_addbacklist(dbla, a->content);
	dbla->first = a->next;
	free(a);
}

void    ft_rb(dblist *dbla)
{
	p_list  *a;

	if (ft_dblist_size(dbla) < 2)
		return  ;
	a = dbla->first;
	ft_addbacklist(dbla, a->content);
	dbla->first = a->next;
	free(a);
}

void    ft_rr(dblist *dbla, dblist *dblb)
{
	ft_ra(dbla);
	ft_rb(dblb);
}

void    ft_rra(dblist *dbla)
{
	p_list  *a;

	if (ft_dblist_size(dbla) < 2)
		return  ;
	a = dbla->last;
	ft_addfrontlist(dbla, a->content);
	dbla->last = a->prev;
	a->prev->next = NULL;
	free(a);
}

void    ft_rrb(dblist *dbla)
{
	p_list  *a;

	if (ft_dblist_size(dbla) < 2)
		return  ;
	a = dbla->last;
	ft_addfrontlist(dbla, a->content);
	dbla->last = a->prev;
	a->prev->next = NULL;
	free(a);
}

void    ft_rrr(dblist *dbla, dblist *dblb)
{
	ft_rra(dbla);
	ft_rrb(dblb);
}