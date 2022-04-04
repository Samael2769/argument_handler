/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>
#include <string.h>

static int count_pars(char *str, char pars)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == pars) {
            count++;
        }
    }
    return (count + 1);
}

static int count_row(char *str, char pars)
{
    int i = 0;

    for (; str[i] != pars && str[i] != '\0'; ++i);
    return i;
}

static char **mem_tab(char *str, int len, char pars)
{
    char **tab = malloc(sizeof(char *) * (len + 1));
    int row = count_row(str, pars);

    for (int i = 0; i < len; i++) {
        tab[i] = malloc(sizeof(char) * (row + 1));
        if (str[row] != '\0')
            str += row + 1;
        tab[i][row] = '\0';
        row = count_row(str, pars);
    }
    tab[len] = NULL;
    return tab;
}

char **sm_strtoarr(char *str, char pars)
{
    char *dup = strdup(str);
    int len = count_pars(dup, pars);
    char **tab = mem_tab(dup, len, pars);
    int k = 0;

    for (int i = 0; i < len; i++, k++) {
        for (int j = 0; dup[k] != pars && dup[k] != '\0'; j++, k++) {
            tab[i][j] = dup[k];
        }
    }
    free(dup);
    return tab;
}