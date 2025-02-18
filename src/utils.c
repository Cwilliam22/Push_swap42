/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcapt < wcapt@student.42lausanne.ch >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:17:38 by wcapt             #+#    #+#             */
/*   Updated: 2025/02/18 14:43:47 by wcapt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

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
