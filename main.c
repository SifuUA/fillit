/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:36:13 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/27 16:39:50 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int			error(void)
{
	write(1, "error\n", 6);
	return (0);
}

int			get_f_arr(char *s, t_figure **f_arr, int *n_f)
{
	char		**arr;
	int			i;

	arr = get_figure_from_string(s);
	i = 0;
	while (arr[i] != NULL)
		i++;
	(*n_f) = i;
	if ((ft_strlen(s) % 21) != 20 || (*n_f) > 26)
		return (error());
	(*f_arr) = (t_figure*)malloc((*n_f) * sizeof(t_figure));
	i = 0;
	while (arr[i] != NULL)
	{
		read_figure(arr[i], (*f_arr)[i]);
		if (check((*f_arr)[i], arr[i], 0, 0) == 0)
			return (error());
		norm_figure((*f_arr)[i++]);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_figure	*f_arr;
	int			n_f;
	size_t		size;
	char		*s;
	t_figs2		figs2;

	if (argc != 2)
		ft_putstr("usage: fillit input_file");
	else
	{
		s = get_s_from_file(argv[1]);
		if (s == NULL || *s == '\0')
			return (error());
		if (get_f_arr(s, &f_arr, &n_f) == 0)
			return (0);
		figs2 = get_figs2_from_figs1(f_arr, n_f);
		size = min_size(n_f);
		while (test_size(size, &figs2) == 0)
			size++;
	}
}
