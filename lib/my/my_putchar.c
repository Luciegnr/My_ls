/*
** ETNA PROJECT, 15/01/2021 by granie_l
** my_putchar
** File description:
**      puig_a granie_l
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
