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