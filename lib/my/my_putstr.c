/*
** ETNA PROJECT, 15/01/2021 by granie_l
** my_putstr
** File description:
**      puig_a granie_l
*/

void my_putchar(char c);
int my_putstr(char *str)
{
    int index;
    
    index = 0;
    while (str[index] != '\0')
        {
            my_putchar(str[index]);
            index++;
        }
    return 0;
}

