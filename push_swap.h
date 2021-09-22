#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/include/ft_printf.h"
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct      p_list
{
    int             content;
    struct p_list   *next;
    struct p_list   *prev;
}                   p_list;

typedef struct  dblist
{
    struct p_list  *first;
    struct p_list  *last;
}               dblist;

typedef struct  i_coor
{
    int     firstPos;
    int     lastPos;
    int     tot;
    int     totrr;
    int     distanceTot;
}               i_coor;

typedef struct      p_coor
{
    int     med;
    int     posMed;
    int     tier;
    int     postTier;
    int     first;
    int     posFirst;
    int     last;
    int     posLast;
    int     lowerMed;
    int     upperMed;
}                   p_coor;

int     nbr_inter(int *tab, int *bubbled, int last);
int     ft_intermed_lower(int *tab, int *bubbled);
int     size_array(int *tab);
void    display_tab(int *tab);
int     ft_get_tier(int *tab);
int     ft_next_lower(int *tab);
void    display_lists(dblist *dbla, dblist *dblb);
void    ft_do(dblist *dbla, dblist *dblb, p_coor *coor);
int     is_sup(dblist *dbl);
int     *list_to_array(dblist *dbl);
void    ft_first_split(p_coor *coor, dblist *dbla, dblist *dblb);
int     ft_same(dblist *dbla, int *bubbled);
void    ft_fill_stack(char **argv, dblist *dbla);
void    ft_fill_first_coor_alt(p_coor *coor, int *tab);
void    ft_fill_first_coor(p_coor *coor, dblist *dbl);
void    ft_init_first_coor(p_coor *coor);
int     *ft_bubble(int *tab);
p_coor  ft_fill_coor(p_coor coor, dblist *dbl);
p_coor  ft_fill_coor_alt(p_coor coor, int *tab);
int     ft_get_med(int *tab);
int     ft_isnumber(char *argv);
int     ft_istoohigh(char *argv);
int     ft_error();
int     ft_checker(char **argv, int argc);
void    ft_addbacklist(dblist *dbla, int val);
void    ft_addfrontlist(dblist *dbla, int val);
int     ft_dblist_size(dblist *dbl);
void    ft_init_dblist(dblist *dbla);
void    ft_sa(dblist *dbla);
void    ft_sb(dblist *dblb);
void    ft_ss(dblist *dbla, dblist *dblb);
void    ft_pa(dblist *dbla, dblist *dblb);
void    ft_pb(dblist *dbla, dblist *dblb);
void    ft_ra(dblist *dbla);
void    ft_rb(dblist *dbla);
void    ft_rr(dblist *dbla, dblist *dblb);
void    ft_rra(dblist *dbla);
void    ft_rrb(dblist *dbla);
void    ft_rrr(dblist *dbla, dblist *dblb);

#endif