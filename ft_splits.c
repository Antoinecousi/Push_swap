// #include "push_swap.h"

// void    ft_first_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;

//     size = ft_dblist_size(dbla);
//     i = 0;
//     // display_lists(dbla, dblb);
//     // printf(" ------ \n %d is my lower med \n", coor->Huitieme);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->Huitieme)
//             do_pb(dbla, dblb);
//         else
//             do_ra(dbla, dblb);
//     }
// }

// void    ft_second_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;

//     size = ft_dblist_size(dbla);
//     i = 0;
//     // display_lists(dbla, dblb);
//     // printf("%d is my med \n", coor->lowerMed);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->lowerMed)
//             do_pb(dbla, dblb);
//         else
//             do_ra(dbla, dblb);
//     }
// }

// void    ft_third_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;
//     int     j;

//     j = 0;
//     size = ft_dblist_size(dbla);
//     // printf("%d is my upper med \n", coor->secHuitieme);
//     i = 0;
//     // display_lists(dbla, dblb);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->secHuitieme)
//         {
//             do_pb(dbla, dblb);
//             j++;
//         }
//         else
//             do_ra(dbla, dblb);
//     }
//     // while (j--)
//     //     do_pa(dbla, dblb);
// }

// void    ft_cinq_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;
//     int     j;

//     j = 0;
//     size = ft_dblist_size(dbla);
//     // printf("%d is my upper med \n", coor->thiHuitieme);
//     i = 0;
//     // display_lists(dbla, dblb);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->thiHuitieme)
//         {
//             do_pb(dbla, dblb);
//             j++;
//         }
//         else
//             do_ra(dbla, dblb);
//     }
//     // while (j--)
//     //     do_pa(dbla, dblb);
// }

// void    ft_six_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;
//     int     j;

//     j = 0;
//     size = ft_dblist_size(dbla);
//     // printf("%d is my upper med \n", coor->upperMed);
//     i = 0;
//     // display_lists(dbla, dblb);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->upperMed)
//         {
//             do_pb(dbla, dblb);
//             j++;
//         }
//         else
//             do_ra(dbla, dblb);
//     }
//     // while (j--)
//     //     do_pa(dbla, dblb);
// }

// void    ft_sept_split(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;
//     int     j;

//     j = 0;
//     size = ft_dblist_size(dbla);
//     // printf("%d is my upper med \n", coor->fouHuitieme);
//     i = 0;
//     // display_lists(dbla, dblb);
//     while (i++ < size)
//     {
//         if (dbla->first->content < coor->fouHuitieme)
//         {
//             do_pb(dbla, dblb);
//             j++;
//         }
//         else
//             do_ra(dbla, dblb);
//     }
//     // while (j--)
//     //     do_pa(dbla, dblb);
// }