#include "../includes/push_swap.h"

void free_stacks(t_stacks stacks)
{
    if (stacks->stack_a)
        free(stacks->stack_a);
    if (stacks->stack_b)
        free(stacks->stack_b);
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
}