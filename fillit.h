/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncoursol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:19:02 by ncoursol          #+#    #+#             */
/*   Updated: 2019/05/09 16:50:59 by dberger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_lst
{
	int				index;
	int				tetri[4][2];
	int				x_max;
	int				y_max;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	char		**res;
	int			sqr;
}				t_map;

int				ft_check(char *str);
t_lst			ft_storage(char *str, t_lst **storage);
char			**ft_map(t_map *table, int mode);
t_map			*ft_back_track(t_lst *storage);
void			ft_display(char **result);

#endif
