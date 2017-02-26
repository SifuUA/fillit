/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:40:18 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/25 21:40:19 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_H
# define INC_H
# include "libft.h"

typedef struct	s_point{
	int		x;
	int		y;
}				t_point;

typedef	struct	s_fig2
{
	t_point		points[4];
	int			type;
	t_point		point_on_field;
}				t_fig2;

typedef struct	s_figs2
{
	t_fig2		*figs;
	int			n_f;
	int			max_type;
}				t_figs2;

typedef t_point	t_figure[4];

char			**get_figure_from_string(char *s);
void			ft_arr_putstr(char **str);
void			norm_figure(t_figure a);
void			read_figure(char *s, t_figure a);
char			**array_of_figure(size_t field_size);
void			print_answer(char **answer, t_point *top_of_figure,
				t_figure *figures, size_t n_figs);
size_t			min_size(size_t n_figs);
int				check(t_figure arr, char *s, int i, int count);
t_figs2			get_figs2_from_figs1(t_figure *figs1, int n_f);
void			creating_typed_array(t_figs2 *figs2);
char			**gen_fld(size_t size);
int				test_size(size_t size, t_figs2 *figs2);
int				recur_func(char **fld, t_figs2 *figs2, size_t size, int i_f);

void			print_fig2(t_fig2 fig);
void			print_figs2(t_figs2 *figs);

#endif
