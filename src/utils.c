/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:38 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/22 19:37:59 by wcapt            ###   ########.fr       */
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

char	*concat_args(int argc, char **argv)
{
	char	*dest;
	char	*temp;
	int		i;

	dest = ft_strdup(argv[1]); 
	i = 2;
	while (i < argc)
	{
		temp = dest;
		dest = ft_strjoin(dest, " ");
		if (!dest)
		{
			free(temp);
			return (NULL);
		}
		temp = dest;
		dest = ft_strjoin(dest, argv[i]);
		if (!dest)  
		{
			free(temp);
			return (NULL);
		}
		i++;
	}
	return (dest);
}
