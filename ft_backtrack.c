/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_track.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:46:23 by ncoursol          #+#    #+#             */
/*   Updated: 2019/05/08 18:22:23 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_place(t_lst *link, char **res, int x, int y)
{
	int		i;
	int		index;

	i = 0;
	index = link->index;
	while (i < 4 && res[link->tetri[i][1] + x][link->tetri[i][0] + y] == '.')
		i++;
	if (i == 4)
	{
		i = 0;
		while (i < 4)
		{
			res[link->tetri[i][1] + x][link->tetri[i][0] + y] = index + 65;
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_del_tetri(t_lst **storage, t_map *table, t_lst *begin)
{
	int		i;
	int		j;
	t_lst	*test;

	j = 0;
	i = 0;
	test = begin;
	while (test->next != *storage)
		test = test->next;
	*storage = test;
	while (table->res[i])
	{
		while (table->res[i][j])
		{
			if (table->res[i][j] == (char)(*storage)->index + 65)
				table->res[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_recursiv(t_lst *storage, t_map *table, t_lst *begin)
{
	int		x;
	int		y;

	x = 0;
	if (storage == NULL)
		return (1);
	while (x < table->sqr - storage->y_max && (y = 0) == 0)
	{
		while (y < table->sqr - storage->x_max)
		{
			if (ft_place(storage, table->res, x, y))
			{
				storage = storage->next;
				if (ft_recursiv(storage, table, begin))
					return (1);
				ft_del_tetri(&storage, table, begin);
			}
			y++;
		}
		x++;
	}
	if (storage->index == 0 && (table->res = ft_map(table, 1)) != NULL)
		if (ft_recursiv(storage, table, begin))
			return (1);
	return (0);
}

t_map	*ft_back_track(t_lst *storage)
{
	t_lst	*begin;
	t_map	*table;

	begin = storage;
	while (storage->next && storage)
		storage = storage->next;
	if (!(table = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	table->sqr = 1;
	if (!(table->res = ft_map(table, 0)))
		return (NULL);
	storage = begin;
	ft_recursiv(storage, table, begin);
	return (table);
}
