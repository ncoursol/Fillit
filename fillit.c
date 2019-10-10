/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:12:28 by ncoursol          #+#    #+#             */
/*   Updated: 2019/05/08 18:39:20 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free(t_lst *storage, t_map *result, t_lst *save)
{
	int i;

	i = 0;
	while (result->res[i])
	{
		free(result->res[i]);
		i++;
	}
	free(result->res);
	free(result);
	storage = save;
	while (save)
	{
		save = storage->next;
		free(storage);
		storage = save;
	}
	free(storage);
}

void	ft_showtab(t_lst *storage)
{
	t_lst	*save;
	t_map	*result;

	save = storage;
	result = ft_back_track(storage);
	ft_display(result->res);
	ft_free(storage, result, save);
}

int		main(int argc, char **argv)
{
	t_lst	*storage;
	int		fd;
	char	buf[2084];
	int		k;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	k = read(fd, buf, 2084);
	buf[k] = '\0';
	if (ft_strlen(buf) > 545 || ft_strlen(buf) < 20
			|| !ft_check(buf))
	{
		ft_putstr("error\n");
		return (0);
	}
	storage = NULL;
	ft_storage(buf, &storage);
	ft_showtab(storage);
	close(fd);
	return (0);
}
