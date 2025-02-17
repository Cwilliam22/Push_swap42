#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct s_stacks
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    int max_size;
}   t_stacks;

