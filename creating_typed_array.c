/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_typed_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:28:02 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/25 21:28:03 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

t_figs2	get_figs2_from_figs1(t_figure *figs1, int n_f)
{
	int		i_f;
	int		i_p;
	t_figs2	figs2;

	figs2.figs = (t_fig2*)malloc(sizeof(t_fig2) * n_f);
	i_f = 0;
	while (i_f < n_f)
	{
		i_p = 0;
		while (i_p < 4)
		{
			figs2.figs[i_f].points[i_p].x = figs1[i_f][i_p].x;
			figs2.figs[i_f].points[i_p].y = figs1[i_f][i_p].y;
			i_p++;
		}
		figs2.figs[i_f].type = -1;
		figs2.figs[i_f].point_on_field.x = -1;
		i_f++;
	}
	figs2.n_f = n_f;
	return (figs2);
}
