/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:36:45 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/25 21:36:47 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int			test_size(size_t size, t_figs2 *figs2)
{
	char	**fld;
	int		res;

	fld = gen_fld(size);
	res = recur_func(fld, figs2, size, 0);
	if (res == 1)
		ft_arr_putstr(fld);
	return (res);
}

void		insert_fig_to_pt(t_figs2 *figs2, int i_f, char **fld, t_point pt)
{
	int		x_p;
	int		y_p;
	int		i_p;
	char	letter;

	figs2->figs[i_f].point_on_field = pt;
	letter = 'A' + (char)i_f;
	i_p = 0;
	while (i_p < 4)
	{
		x_p = figs2->figs[i_f].points[i_p].x + pt.x;
		y_p = figs2->figs[i_f].points[i_p].y + pt.y;
		fld[y_p][x_p] = letter;
		i_p++;
	}
}

void		remove_fig_from_field(t_figs2 *figs2, int i_f, char **fld)
{
	int		x_p;
	int		y_p;
	int		i_p;

	i_p = 0;
	while (i_p < 4)
	{
		x_p = figs2->figs[i_f].points[i_p].x;
		x_p += figs2->figs[i_f].point_on_field.x;
		y_p = figs2->figs[i_f].points[i_p].y;
		y_p += figs2->figs[i_f].point_on_field.y;
		fld[y_p][x_p] = '.';
		i_p++;
	}
	figs2->figs[i_f].point_on_field.x = -1;
}

int			can_certain_fig_to_be_inserted_to_point(char **fld, t_fig2 *fig2,
		size_t size, t_point pt)
{
	int		x_p;
	int		y_p;
	int		i_p;

	i_p = 0;
	while (i_p < 4)
	{
		x_p = fig2->points[i_p].x + pt.x;
		y_p = fig2->points[i_p].y + pt.y;
		if (y_p >= (int)size || x_p >= (int)size)
			return (0);
		if (fld[y_p][x_p] != '.')
			return (0);
		i_p++;
	}
	return (1);
}

int			recur_func(char **fld, t_figs2 *figs2, size_t size, int i_f)
{
	t_point	pt;

	if (i_f == figs2->n_f)
		return (1);
	pt.y = 0;
	while (pt.y < (int)size)
	{
		pt.x = 0;
		while (pt.x < (int)size)
		{
			if (can_certain_fig_to_be_inserted_to_point(fld,
						&(figs2->figs[i_f]), size, pt) == 1)
			{
				insert_fig_to_pt(figs2, i_f, fld, pt);
				if (recur_func(fld, figs2, size, i_f + 1) == 1)
					return (1);
				else
					remove_fig_from_field(figs2, i_f, fld);
			}
			pt.x++;
		}
		pt.y++;
	}
	return (0);
}
