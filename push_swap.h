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
    int     total;
    int     first;
    int     posFirst;
    int     last;
    int     posLast;
    int     lowerMed;
    int     upperMed;
    int     Huitieme;
    int     secHuitieme;
    int     thiHuitieme;
    int     fouHuitieme;
}                   p_coor;

void    sort_more_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor);
void    sort_one_hundred(dblist *dbla, dblist *dblb, p_coor *coor);
int	    utils_sort_three(dblist *dbla, dblist *dblb);
void	a_bigger_than_b(dblist *dbla, dblist *dblb);
void	sort_three_numbers(dblist *dbla, dblist *dblb);
void    move_smallest_nbr_to_top(dblist *dbla, dblist *dblb, int size);
void	sort_one_to_five(dblist *dbla, dblist *dblb);
void	choose_sort_stack(dblist *dbla, dblist *dblb, p_coor *coor);
int     ft_get_med_div_b(int *tab, int div_med, int size);
int     ft_splitterbdeux(dblist *dbla, dblist *dblb, int until, int div_med);
int     ft_get_med_div(int *tab, int div_med, int size);
int     *ft_tab_reducer(int lenght, int *tab);
int     ft_is_croissant(dblist *dbla);
int     ft_secondrecurs(p_coor *coor, dblist *dbla, dblist *dblb, int size, int med);
int     ft_recursiveshit(p_coor *coor, dblist *dbla, dblist *dblb);
int     ft_position(int *tab, int inter);
int     topOrBottomHard(int *tab, int inter, int final);
int     topOrBot(int *tab, int c);
int     ft_take_inter(int *tab, int inter, int final, int size);
int     ft_decoupage(p_coor *coor, dblist *dbla, dblist *dblb, int size);
int     ft_splitterb(dblist *dbla, dblist *dblb, int until, int div_med);
int     ft_get_med_div_b(int *tab, int div_med, int size);
int     ft_splitter(dblist *dbla, dblist *dblb, int until, int div_med);
int     ft_get_huitieme(int *tab);
int     ft_get_secondhuitieme(int *tab);
int     ft_get_thirdhuitieme(int *tab);
int     ft_get_fourthhuitieme(int *tab);
int     ft_get_quarter(int *tab);
int     ft_get_thirdquarter(int *tab);
int     ft_next_seeked(int *tab, int c);
int     ft_forwardA(dblist *dbla, dblist *dblb, int *bub, int final, int lol);
int     ft_backwardA(dblist *dbla, dblist *dblb, int *bub, int final, int lol);
int     ft_forwardB(dblist *dbla, dblist *dblb, int *bub, int final, int lol);
int     ft_backwardB(dblist *dbla, dblist *dblb, int *bub, int final, int lol);
int     ft_direction_after_inter(int *tab, int inter, int final, int size);
int     ft_inter_calcul_backward(int *tab, int inter, int final, int size);
int     ft_inter_calcul_forward(int *tab, int inter, int final, int size);
int     *ft_reverse_tab(int *tab, int size);
void    do_ra(dblist *dbla, dblist *dblb);
void    do_rra(dblist *dbla, dblist *dblb);
void    do_rb(dblist *dbla, dblist *dblb);
void    do_rrb(dblist *dbla, dblist *dblb);
void    do_pb(dblist *dbla, dblist *dblb);
void    do_pa(dblist *dbla, dblist *dblb);
void    do_rrr(dblist *dbla, dblist *dblb);
void    do_rr(dblist *dbla, dblist *dblb);
void    do_ss(dblist *dbla, dblist *dblb);
void    do_sa(dblist *dbla, dblist *dblb);
void    do_sb(dblist *dbla, dblist *dblb);
int     ft_next_lower_bis(int *tab);
int     nbr_inter_forward(int *tab, int *bubbled, int last, int totInter);
int     nbr_inter_backward(int *tab, int *bubbled, int last);
int     ft_intermed_lower(int *tab, int *bubbled);
int     size_array(int *tab, int size);
void    display_tab(int *tab, int size);
int     ft_get_tier(int *tab);
int     ft_next_lower(int *tab);
void    display_lists(dblist *dbla, dblist *dblb);
void    ft_do(dblist *dbla, dblist *dblb, p_coor *coor);
int     is_sup(dblist *dbl);
int     *list_to_array(dblist *dbl);
// void    ft_first_split(p_coor *coor, dblist *dbla, dblist *dblb);
// void    ft_second_split(p_coor *coor, dblist *dbla, dblist *dblb);
// void    ft_third_split(p_coor *coor, dblist *dbla, dblist *dblb);
void    ft_quatre_split(dblist *dbla, dblist *dblb);
// void    ft_cinq_split(p_coor *coor, dblist *dbla, dblist *dblb);
// void    ft_six_split(p_coor *coor, dblist *dbla, dblist *dblb);
// void    ft_sept_split(p_coor *coor, dblist *dbla, dblist *dblb);
int     ft_same(dblist *dbla, int *bubbled);
int     ft_fill_stack(char **argv, dblist *dbla);
void    ft_fill_first_coor_alt(p_coor *coor, int *tab);
void    ft_fill_first_coor(p_coor *coor, dblist *dbl);
void    ft_init_first_coor(p_coor *coor, int argc);
int     *ft_bubble(int *tab, int size);
p_coor  ft_fill_coor(p_coor coor, dblist *dbl);
p_coor  ft_fill_coor_alt(p_coor coor, int *tab);
int     ft_get_med(int *tab, int size);
int     ft_isnumber(char *argv);
int     ft_istoohigh(char *argv);
int     ft_error();
int     ft_next_upper(int *tab);
void    init_ins(i_coor *ins);
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
int     *ft_reverse_bubble(int *tab, int size);

#endif