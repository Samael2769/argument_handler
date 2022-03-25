/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** arg_handler
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arg_handler.h"

//char ** make_tab(char * arg_string)
//{
//    char **tab = malloc(sizeof(char *) * 1);
//    int i = 0;
//    int a = 0;
//    int b = 0;
//
//    for (i = 0; arg_string[i] != ' ' && arg_string[i] != '\0'; ++i);
//    if (arg_string[i] != ' ') {
//        return NULL;
//    }
//    ++i;
//    for (; i < strlen(arg_string); ++i, ++a) {
//        if (arg_string[i] == ' ' && (arg_string[i -3] && arg_string[i - 3] != '(')) {
//            printf("arg_string[i] = %c\n", arg_string[i]);
//            printf("%d - %s\n", b, tab[b]);
//            printf("a = %d\n", a);
//            ++b;
//            a = 0;
//            tab = realloc(tab, sizeof(char * ) * (b + 1));
//            continue;
//        }
//        tab[b] = realloc(tab[b], sizeof(char) * (a + 1));
//        tab[b][a] = arg_string[i];
//        printf("%c - %c\n", tab[b][a], arg_string[i]);
//    }
//    printf("b = %d\n", b);
//    tab[b + 1] = NULL;
//    return tab;
//}

node_args_t * create_head(char *str)
{
    node_args_t *node = malloc(sizeof(node_args_t));

    
}

//parse the string and create a linked list
void push_new(node_args_t *head, char *str)
{
    
}

int make_list(args_list *list, char * arg_string)
{
    char **arg_tab = make_tab(arg_string, ' ');
    if (arg_tab == NULL)
        return -1;
    for (int i = 0; arg_tab[i] != NULL; ++i)
        printf("%s\n", arg_tab[i]);
}

int arg_handler(char * arg_string, int ac, char **av)
{
    printf("%s\n", arg_string);
    args_list list = {NULL, 0};
    if (make_list(&list, arg_string) != 0)
        return 0;
    return 0;
}