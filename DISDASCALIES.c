// pour backward (i > moitié)
// final > inter back = size - inter + 2; 
// final > inter chan = 2 * (size - i) + inter + 1;
// inter > final forw = final + 2;
// inter > final chan = 2 * inter + (size - i) + 3;

// final > inter back - inter > final forw = size - inter + 2 - final - 1;                       = size - final - inter + 1;
// final > inter chan - inter > final forw = 2 * (size - i) + inter + 1 - final - 1;             = 2 * size - 3 * final + inter - 1;
// final > inter back - inter > final chan = size - inter + 2 - 2 inter - size + final - 3;              = final - 3 * inter - 1;
// final > inter chan - inter > final chan = 2 * size - (2 * i) + inter + 1 - (2 * inter) - size +final - 3;             = size - inter - final - 2;

// pour forward (i < moitié)
// final > inter forw = inter + 1;
// final > inter chan = 2 * final + (size - inter) + 2;
// inter > final back = (size - i) + 3;
// inter > final chan = 2 * (size - inter) +final + 2;

// final > inter forw - inter > final back = inter + 1 - size + final - 3;              = inter + final - size - 2;
// final > inter chan - inter > final back = 2 * final + (size - inter) + 2 - size + final - 3;              = 3 * final - inter - 1;
// final > inter forw - inter > final chan = inter + 1 - (2 * size) + (2 * inter) - final - 2;               = 3 * inter - 2 * size - final - 1;
// final > inter chan - inter >final chan = 2 *final + (size - inter) + 2 - (2 * size) + (2 * inter) -final - 2;             = final - size + inter;


// int     ft_direction_after_inter(int *tab, int inter, int final)
// {
//     int     index;
//     int     size;
//     int     result;

//     size = size_array(tab);
//     index = 0;
//     while (tab[index] != '\0')
//     {
//         if (tab[index] == inter)
//             inter = index;
//         if (tab[index] == final)
//             final = index;
//         index++;
//     }
//     if ((inter < final && final - inter <= size / 2) || (final < inter && inter - final > size / 2))
//     {
//         printf("Direction is ra after car inter = %d et final = %d et size = %d\n", inter, final, size);
//         return (1);
//     }
//     else
//     {
//         printf("Direction is rra after car inter = %d et final = %d et size = %d\n", inter, final, size);
//         return (0);
//     }
// }
