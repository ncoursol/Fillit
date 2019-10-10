/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:36:58 by dberger           #+#    #+#             */
/*   Updated: 2019/05/07 15:52:50 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_col(char *str, int i)
{
	int col;

	col = 0;
	while (str[i] != '\n' && str[i] && (str[i] == '.' || str[i] == '#'))
	{
		col++;
		i++;
	}
	if (col == 4)
		return (str[i] == '\n' ? i : 0);
	return (0);
}

int		ft_check_line(char *str, int i, int col, int line)
{
	int		k;
	int		z;

	z = 0;
	k = ft_strlen(str);
	if (str[i] == '\n' && (str[i + 1] == '.' || str[i + 1] == '#')
			&& col == 4 && line < 4)
	{
		line++;
		z++;
	}
	if (str[i] == '\n' && line == 4 && str[i + 1] != '\n'
			&& col == 4 && i < k - 1 && !z)
		return (0);
	return (line <= 4 ? line : 0);
}

int		ft_check_block(char *str, int i)
{
	int k;
	int	count;
	int	tetri;

	count = 0;
	tetri = 0;
	k = i - 19;
	while (k <= i)
	{
		if (str[k] == '#')
		{
			if (k >= 5 && str[k - 5] == '#')
				count++;
			if (k < i - 5 && str[k + 5] == '#')
				count++;
			if (k < i - 1 && str[k + 1] == '#')
				count++;
			if (k >= 1 && str[k - 1] == '#')
				count++;
			tetri++;
		}
		k++;
	}
	return (tetri == 4 && count >= 6 ? i + 1 : 0);
}

int		ft_check(char *str)
{
	int		i;
	int		k;
	int		col;
	int		line;

	i = 0;
	col = 0;
	line = 1;
	k = ft_strlen(str);
	while (str[i] && (str[i] == '.' || str[i] == '#' || str[i] == '\n'))
	{
		if (!(i = ft_check_col(str, i)))
			return (0);
		col = 4;
		if ((line = ft_check_line(str, i, col, line)))
			if (str[i] == '\n' && line == 4 && str[i + 1] == '\n' && col == 4)
				if ((col = 0) == 0)
					if ((line = 1) == 1)
						if (!(i = ft_check_block(str, i)))
							return (0);
		if (str[i] == '\n' && line == 4 && i + 1 == k && col == 4)
			return (!(ft_check_block(str, i)) ? 0 : 1);
		i++;
	}
	return (0);
}
