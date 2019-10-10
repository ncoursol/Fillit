/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:22:01 by dberger           #+#    #+#             */
/*   Updated: 2019/05/08 18:29:01 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*ft_increase(t_map *table)
{
	int k;

	k = 0;
	while (table->res[k])
	{
		free(table->res[k]);
		k++;
	}
	free(table->res);
	table->sqr = table->sqr + 1;
	return (table);
}

char	**ft_map(t_map *table, int mode)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (mode == 1)
		ft_increase(table);
	if (!(table->res = (char**)malloc(sizeof(char*) * (table->sqr + 1))))
		return (NULL);
	while (i < table->sqr)
	{
		if (!(table->res[i] = (char*)malloc(sizeof(char) * (table->sqr + 1))))
			return (NULL);
		table->res[i][table->sqr] = '\0';
		while (j < table->sqr)
			table->res[i][j++] = '.';
		j = 0;
		i++;
	}
	table->res[i] = 0;
	return (table->res);
}
