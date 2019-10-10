/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:48:35 by ncoursol          #+#    #+#             */
/*   Updated: 2019/05/08 17:26:33 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_new(t_lst **nxt, int index, t_lst **storage)
{
	t_lst	*tab;

	if (!(tab = (t_lst*)malloc(sizeof(t_lst))))
		return (0);
	tab->index = index;
	tab->next = NULL;
	if (!*storage)
	{
		*storage = tab;
		*nxt = *storage;
	}
	else
		(*nxt)->next = tab;
	return (1);
}

void	form_pos(t_lst **nxt)
{
	int		i;
	int		x_min;
	int		y_min;

	x_min = 4;
	y_min = 4;
	i = 0;
	while (i != 4)
	{
		if ((*nxt)->tetri[i][0] < x_min)
			x_min = (*nxt)->tetri[i][0];
		if ((*nxt)->tetri[i][1] < y_min)
			y_min = (*nxt)->tetri[i][1];
		i++;
	}
	i = 0;
	x_min--;
	y_min--;
	while (i != 4)
	{
		(*nxt)->tetri[i][0] = ((*nxt)->tetri[i][0] - x_min) - 1;
		(*nxt)->tetri[i][1] = ((*nxt)->tetri[i][1] - y_min) - 1;
		i++;
	}
}

void	coord(char *str, t_lst **nxt)
{
	int		i;
	int		hash;
	int		x;
	int		y;

	hash = 0;
	i = 0;
	x = 1;
	y = 1;
	while (str[i] && (str[i] != '\n' || str[i + 1] != '\n'))
	{
		if (str[i] == '\n' && (x = 0) == 0)
			y++;
		if (str[i] == '#')
		{
			(*nxt)->tetri[hash][0] = x;
			(*nxt)->tetri[hash][1] = y;
			hash++;
		}
		x++;
		i++;
	}
	form_pos(nxt);
}

void	size(t_lst **nxt)
{
	int i;

	i = 0;
	(*nxt)->x_max = 0;
	(*nxt)->y_max = 0;
	while (i++ != 4)
		if ((*nxt)->tetri[i][0] > (*nxt)->x_max)
			(*nxt)->x_max = (*nxt)->tetri[i][0];
	i = 0;
	while (i++ != 4)
		if ((*nxt)->tetri[i][1] > (*nxt)->y_max)
			(*nxt)->y_max = (*nxt)->tetri[i][1];
}

t_lst	ft_storage(char *str, t_lst **storage)
{
	t_lst	*nxt;
	int		i;
	int		nb_bloc;

	i = 0;
	nb_bloc = 0;
	if (!ft_new(&nxt, nb_bloc, storage))
		return (**storage);
	while (nb_bloc < -((-1 - (int)ft_strlen(str)) / 21))
	{
		if (nb_bloc != 0)
		{
			if (!ft_new(&nxt, nb_bloc, storage))
				return (**storage);
			nxt = nxt->next;
		}
		coord(&str[i], &nxt);
		size(&nxt);
		i = i + 21;
		nb_bloc++;
	}
	return (**storage);
}
