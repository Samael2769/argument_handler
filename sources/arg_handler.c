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



/*
    type 1 = -x // movable
    type 2 = alpha // static
*/

//delete '[]()' from str 
char *epurator(char *str)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] != '[' && str[i] != ']' && str[i] != '(' && str[i] != ')') {
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = '\0';
    return new_str;
}

void create_head(args_list *list, char *str)
{
    node_args_t *new = malloc(sizeof(node_args_t));
    char **tab = sm_strtoarr(str, ' ');
    switch (tab[0][0]) {
        case '-':
            new->type = 1;
            new->is_mandatory = true;
            new->head = epurator(tab[0]);
            new->arg = NULL;
            new->isPlaced = false;
            new->place = -1;
            break;
        case '(':
            new->type = 1;
            if (tab[1][0] == '[') {
                new->is_arg_mandatory = false;
                new->arg = NULL;
            } else {
                new->is_arg_mandatory = true;
                new->arg = epurator(tab[1]);
            }
            new->is_mandatory = true;
            new->head = epurator(tab[0]);
            new->isPlaced = false;
            new->place = -1;
            break;
        case '[':
            if (tab[0][0] == '-') {
                new->head = epurator(tab[0]);
                new->arg = NULL;
                new->type = 1;
                new->isPlaced = false;
                new->place = -1;
            } else {
                new->head = NULL;
                new->arg = epurator(tab[0]);
                new->type = 2;
                new->isPlaced = true;
                new->place = list->placeNb + 1;
                list->placeNb++;
            }
            new->is_mandatory = false;
            break;
        default:
            new->head = NULL;
            new->arg = epurator(tab[0]);
            new->type = 2;
            new->isPlaced = true;
            new->place = list->placeNb + 1;
            list->placeNb++;
            new->is_mandatory = true;
            break;
    }
    new->next = NULL;
    list->head = new;
}

//parse the string and create a linked list
void push_new(args_list *list, char *str)
{
    node_args_t *new = malloc(sizeof(node_args_t));
    char **tab = sm_strtoarr(str, ' ');
    switch (tab[0][0]) {
        case '-':
            new->type = 1;
            new->is_mandatory = true;
            new->head = epurator(tab[0]);
            new->arg = NULL;
            new->isPlaced = false;
            new->place = -1;
            break;
        case '(':
            new->type = 1;
            if (tab[1][0] == '[') {
                new->is_arg_mandatory = false;
                new->arg = NULL;
            } else {
                new->is_arg_mandatory = true;
                new->arg = epurator(tab[1]);
            }
            new->is_mandatory = true;
            new->head = epurator(tab[0]);
            new->isPlaced = false;
            new->place = -1;
            break;
        case '[':
            if (tab[0][0] == '-') {
                new->head = epurator(tab[0]);
                new->arg = NULL;
                new->type = 1;
                new->isPlaced = false;
                new->place = -1;
            } else {
                new->head = NULL;
                new->arg = epurator(tab[0]);
                new->type = 2;
                new->isPlaced = true;
                new->place = list->placeNb + 1;
                list->placeNb++;
            }
            new->is_mandatory = false;
            break;
        default:
            new->head = NULL;
            new->arg = epurator(tab[0]);
            new->type = 2;
            new->isPlaced = true;
            new->place = list->placeNb + 1;
            list->placeNb++;
            new->is_mandatory = true;
            break;
    }
    node_args_t *dup;
    new->isGood = false;
    for (dup = list->head; dup->next != NULL; dup = dup->next);
    dup->next = new;
}

int make_list(args_list *list, char * arg_string)
{
    char **arg_tab = make_tab(arg_string, ' ');
    if (arg_tab == NULL)
        return -1;
    for (int i = 1; arg_tab[i] != NULL; ++i) {
        if (i == 1)
            create_head(list, arg_tab[i]);
        else
            push_new(list, arg_tab[i]);
        list->nb += 1;
    }
}

int arg_handler(char * arg_string, int ac, char **av)
{
    printf("%s\n", arg_string);
    args_list list = {NULL, 0, 0};
    if (make_list(&list, arg_string) != 0)
        return 0;
    for (int i = 1; i < ac; ++i) {
        if (av[i][0] == '-') {
            for (node_args_t *dup = list.head; dup != NULL; dup = dup->next) {
                if (dup->head != NULL && strncmp(av[i], dup->head, 2) == 0) {
                    dup->isGood = true;
                    if (dup->arg != NULL) {
                        if (i + 1 < ac)
                            i++;
                        else
                            dup->isGood = false;
                    } else
                        dup->isGood = true;
                    break;
                }
            }
        } else {
            for (node_args_t *dup = list.head; dup != NULL; dup = dup->next) {
                if (dup->isPlaced == true) {
                    dup->isPlaced = false;
                    dup->isGood = true;
                    break;
                }
            }
        }
    }
    //for (node_args_t *dup = list.head; dup != NULL; dup = dup->next) {
    //    if (dup->head != NULL)
    //        printf("head : %s\n", dup->head);
    //    if (dup->arg != NULL)
    //        printf("arg : %s\n", dup->arg);
    //    printf("type : %d\n", dup->type);
    //    printf("is_mandatory : %d\n", dup->is_mandatory);
    //    printf("isPlaced : %d\n", dup->isPlaced);
    //    printf("place : %d\n", dup->place);
    //    printf("isGood : %d\n", dup->isGood);
    //    printf("\n");
    //}
    for (node_args_t *dup = list.head; dup != NULL; dup = dup->next) {
        if (dup->is_mandatory == true && dup->isGood == false)
            return 1;
    }
    return 0;
}