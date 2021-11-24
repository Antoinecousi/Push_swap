// int     ft_intermed_first(int *tab, int *bubbled, int final)
// {
//     int     i = 0;
//     int     posInterm = 0;

//     while (tab[posInterm] != final)
//     {
//         if (tab[posInterm] == bubbled[1])
//         {
//             posInterm++;
//             return (posInterm);
//         }
//         posInterm++;
//     }
//     return (0);
// }

// int     ft_intermed_backward(int *tab, int *bubbled, int final)
// {
//     int     i = 0;
//     int     posInterm = 0;

//     while (tab[posInterm] != final)
//     {
//         if (tab[posInterm] == bubbled[1])
//         {
//             posInterm++;
//             return (posInterm);
//         }
//         posInterm++;
//     }
//     return (0);
// }

// #include "push_swap.h"

// int     *ft_tab_reducer(int lenght, int *tab)
// {
//     int     *copy;
//     int     i;

// 	i = 0;
//     if (!(copy = malloc(sizeof(int) * (lenght + 8))))
//         return (0);
// 	if (!tab || !copy)
// 		return (NULL);
// 	if (lenght != 0)
// 	{
// 		while (tab[i] != '\0' && i < (lenght - 1))
// 		{
// 			copy[i] = tab[i];
// 			i++;
// 		}
// 		copy[i] = '\0';
// 	}
// 	return (copy);
// }


// int     ft_intermed_lower(int *tab, int *bubbled)
// { 
//     int     posInterm = 0;

//     if (ft_next_lower(tab) > 1)
//     {
//         while (tab[posInterm] != bubbled[0])
//         {
//             if (tab[posInterm] == bubbled[1])
//                 return (posInterm);
//             posInterm++;
//         }
//     }
//     else
//     {
//         int size = size_array(tab);
//         while (tab[size] != bubbled[0])
//         {
//             if (tab[size] == bubbled[1])
//                 return (posInterm);
//             posInterm++;
//             size--;
//         }
//     }
//     return (0);
// }

// int     ft_get_thirdhuitieme(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     // printf("%d et %d \n", tab[(i - 1) / 2 + (i - 1) / 8], (i - 1) / 2 + (i - 1) / 8);
//     return (tab[(i - 1) / 2 + (i - 1) / 8]);
// }

// int     ft_get_thirdquarter(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     return (tab[(i - 1) / 2 + (i - 1) / 4]);
// }

// int     ft_get_fourthhuitieme(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     return (tab[(i - 1) / 2 + (i - 1) / 4 + (i - 1) / 8]);
    

// int     ft_get_huitieme(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     return (tab[(i - 1) / 8]);
// }

// int     ft_get_quarter(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     // printf("%d et %d \n", tab[(i - 1) / 4], (i - 1) / 4);
//     return (tab[(i - 1) / 4]);
// }

// int     ft_get_secondhuitieme(int *tab)
// {
//     int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     // printf("%d et %d \n", tab[(i - 1) / 4 + (i - 1) / 8], (i - 1) / 4 + (i - 1) / 8);
//     return (tab[(i - 1) / 4 + (i - 1) / 8]);
// }

// int     ft_get_tier(int *tab)
// {
//         int     i;
    
//     i = 0;
//     while (tab[i++])
//     tab = ft_bubble(tab);
//     return (tab[(i - 1) / 3]);
// }


// int     ft_decoupage(p_coor *coor, dblist *dbla, dblist *dblb, int size)
// { 
//     int     i;
//     int     total;

//     int     *toto = ft_bubble(list_to_array(dbla));
//     i = 1;
//     // total = 0;
//     // total += ft_splitter(coor, dbla, dblb);
//     // while (i++ < 2)
//     // {
//     //     while (ft_dblist_size(dbla) > 2)
//     //         total += ft_splitter(coor, dbla, dblb);
//     //     if (dbla->first->content > dbla->first->next->content)
//     //         do_sa(dbla, dblb);
//     //     while (ft_dblist_size(dblb) > 2)
//     //         total += ft_splitterb(coor, dbla, dblb);
//     // }
//     ft_recursiveshit(coor, dbla, dblb);
//     // while (ft_dblist_size(dbla) > 50)
//     //         total += ft_splitter(coor, dbla, dblb);
//     // printf("ITS THE END OF THE SPLITTING \n");
//     // printf("total is equal = %d\n", total);
//     return (1);
// }

// int    ft_splitterb(dblist *dbla, dblist *dblb, int until, int div_med)
// {
//     int     size_list;
//     int     i;
//     int     med;

//     size_list = ft_dblist_size(dblb);
//     med = ft_get_med_div_b(list_to_array(dblb), div_med);
//     // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
//     i = 0;
//     // display_lists(dbla, dblb);
//     int b = 0;
//     while (b < until)
//     {
//         med = ft_get_med_div_b(list_to_array(dblb), div_med);
//         // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
//         if (dblb->first->content > med)
//         {
//             do_pa(dbla, dblb);
//             b++;
//         }
//         else
//             do_rb(dbla, dblb);
//         i++;
//     }
//     // printf("B Chunk size is %d\n", b);
//     return (i);
// }

// int    ft_splitterbdeux(dblist *dbla, dblist *dblb, int until, int div_med)
// {
//     int     size_list;
//     int     i;
//     int     med;

//     size_list = ft_dblist_size(dblb);
//     i = 0;
//     // display_lists(dbla, dblb);
//     int b = 0;
//     med = ft_get_med_div_b(list_to_array(dblb), div_med);
//     // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
//     while (b < until)
//     {
//         med = ft_get_med_div_b(list_to_array(dblb), div_med);
//         // printf("valeur de mediane = %d ///// size = %d et de until : %d \n", med, size_list, until);
//         if (dblb->first->content > med)
//         {
//             do_pa(dbla, dblb);
//             b++;
//         }
//         else
//             do_rb(dbla, dblb);
//         i++;
//     }
//     // printf("B Chunk size is %d\n", b);
//     return (i);
// }

// // int    ft_splitter(p_coor *coor, dblist *dbla, dblist *dblb)
// // {
// //     int     size;
// //     int     i;

// //     size = ft_dblist_size(dbla);
// //     i = 0;
// //     display_lists(dbla, dblb);
// //     coor->med = ft_get_med(list_to_array(dbla));
// //     int b = 0;
// //     printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
// //     while (b + 1 < (size + 1) / 2)
// //     {
// //         i++;
// //         if (dbla->first->content < coor->med)
// //         {
// //             do_pb(dbla, dblb);
// //             b++;    
// //         }
// //         else
// //             do_ra(dbla, dblb);
// //     }
// //     printf("A Chunk size is %d\n", b);
// //     return (i);
// // }

// // int    ft_splitterb(p_coor *coor, dblist *dbla, dblist *dblb)
// // {
// //     int     size;
// //     int     i;

// //     size = ft_dblist_size(dblb);
// //     i = 0;
// //     display_lists(dbla, dblb);
// //     coor->med = ft_get_med(list_to_array(dblb));
// //     int b = 0;
// //     printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
// //     while (b + 1 < (size + 1) / 2)
// //     {
// //         if (dblb->first->content > coor->med)
// //         {
// //             do_pa(dbla, dblb);
// //             b++;
// //         }
// //         else
// //             do_rb(dbla, dblb);
// //         i++;
// //     }
// //     printf("B Chunk size is %d\n", b);
// //     return (i);
// // }


// int     ft_recursiveshit(p_coor *coor, dblist *dbla, dblist *dblb)
// {
//     int     size;
//     int     i;

//     size = ft_dblist_size(dbla);
//     i = 0;
//     // display_lists(dbla, dblb);
//     coor->med = ft_get_med(list_to_array(dbla));
//     int b = 0;
//     // printf("valeur de mediane = %d ///// size = %d \n", coor->med, size);
//     while (b < size / 2 && ft_dblist_size(dbla) > 2)
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
//     if (ft_dblist_size(dbla) > 2 && ft_is_croissant(dbla))
//         ft_recursiveshit(coor, dbla, dblb);
//     // printf("My next chunk is : %d !!\n", b);
//     ft_secondrecurs(coor, dbla, dblb, b, coor->med);
//     return (1);
// }


// int     topOrBottomHardBack(int *tab, int inter, int final, int size)
// {
//     int     allOperations[4];
//     int     size;
//     int     tmp;
//     int     i;

//     inter = ft_position(tab, inter);
//     final = ft_position(tab, final);
//     size = size_array(tab);
//     i = 0;
//     tmp = INT_MAX;
//     allOperations[0] = size - inter + 2;
//     allOperations[1] = 2 * (size - final) + inter + 1;
//     allOperations[2] = final + 2;
//     allOperations[3] = 2 * inter + (size - final) + 3;
//     while (i < 4)
//     {
//         if (allOperations[i] < tmp)
//             tmp = allOperations[i];
//         i++;
//     }
//     return (tmp);
// }

// int     topOrBottomHardFor(int *tab, int inter, int final, int size)
// {
//     int     allOperations[4];
//     int     tmp;
//     int     i;

//     inter = ft_position(tab, inter);
//     final = ft_position(tab, final);
//     i = 0;
//     tmp = INT_MAX;
//     allOperations[0] = inter + 1;
//     allOperations[1] = 2 * final + (size - inter) + 2;
//     allOperations[2] = (size - i) + 3;
//     allOperations[3] = 2 * (size - inter) + final + 2;
//     while (i < 4)
//     {
//         if (allOperations[i] < tmp)
//             tmp = allOperations[i];
//         i++;
//     }
//     return (tmp);
// }

// int     topOrBottomHard(int *tab, int inter, int final, int size)
// {
//     int     result;

//     if (ft_position(tab, final) > size)
//         result = topOrBottomHardBack(tab, inter, final);
//     else
//         result = topOrBottomHardFor(tab, inter, final);
//     return (0);
// // }


// int     topOrBot(int *tab, int c)
// {
//     int     i;
//     int     j;

//     j = size_array(tab);
//     i = 0;
//     while (tab[i])
//     {
//         if (tab[i] == c)
//             break;
//         i++;
//     }
//     if (i > j - i)
//         return (j - i);
//     return (i);
// }
