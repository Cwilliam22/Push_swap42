#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stacks    stacks;

    stacks.size_a = 0;
    stacks.size_b = 0;
    stacks.stack_a = NULL;
    stacks.stack_b = NULL;
    
    if (!checks(argc, argv))
        return (1);
    if (!init_stacks(argc, argv, stacks))
        return (1);
    return (0);
}