/*
** EPITECH PROJECT, 2022
** $$
** File description:
** include
*/

#ifndef ARG_HANDLER_H_
#define ARG_HANDLER_H_

#include <stdbool.h>

typedef struct node_args_s {
    char * head;
    char * arg;
    int place;
    bool isPlaced;
    bool is_mandatory;
    int type;
    struct node_args_s * next;
} node_args_t;

typedef struct args_list_s {
    node_args_t *head;
    int nb;
    int placeNb;
} args_list;

int arg_handler(char * arg_string, int ac, char **av);
char **make_tab(char *str, char pars);
char **sm_strtoarr(char *str, char pars);

#endif /* !ARG_HANDLER_H_ */