/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:38 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/19 14:38:23 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

char    *concat_args(int argc, char **argv)
{
    char    *dest;
    int     nbr_arg;
    char    *temp;

    nbr_arg = argc - 2;
    dest = ft_strdup("");
    while (argc > 0)
    {
        temp = dest;
        dest = ft_strjoin(dest, *argv);
        free(temp);
        if (argc > 1)
        {
            temp = dest;
            dest = ft_strjoin(dest, " ");
            free(temp);
        }
        argv++;
        nbr_arg--;
    }
    return (dest);
}
