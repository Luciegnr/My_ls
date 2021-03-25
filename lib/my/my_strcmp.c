/*
** ETNA PROJECT, 15/01/2021 by granie_l
** my_strcmp
** File description:
**      puig_a granie_l
*/

int my_strcmp(const char *s1, const char *s2)
{
    int index;
    index = 0;

    while (s1[index] != '\0'){
        if (s1[index] != s2[index]){
            return (s1[index] - s2[index]);
        }
        index++;
    }
    if (s2[index] > s1[index]){
        return (s1[index] - s2[index]);
    }
    return (0);
}
