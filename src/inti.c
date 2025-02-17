
#include "../includes/push_swap.h"

char *merge_str(int argc, char **argv)
{
	char *str;

	if (argc > 2)
		str = concat_args(argc, argv);
	else
		str = argv[1];
	return (str);
}

int init_stacks(int argc, char **argv, t_stacks stacks)
{
	char *str;
	char **tab_number;
	int num_count;
	int i;

	str = merge_str(argc, argv);
	tab_number = ft_split(str, ' ');
	num_count = count_numbers(str); // Faire la fonction count_numbers (compte chaque argument)
	if (argc > 2)
		free(str);
	stacks->stack_a = (sizeof(int) * num_count);
	stacks->stack_b = (sizeof(int) * num_count);
	if (!stacks->stack_a || !stacks->stack_b)
	{
		free_stacks(stacks);
		return (0)
	}
	i = -1;
	while (++i < num_count)
		stacks->stack_a[i] = ft_atol(tab_number[i])
	free_stacks(tab_number);
	stacks->size_a = num_count;
	stacks->size_b = 0;
	stacks->int_max = num_count;
	return(1);
}
