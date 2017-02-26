/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:36:59 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/25 21:37:00 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

char		**gen_fld(size_t size)
{
	char	**fld;
	size_t	x;
	size_t	y;

	fld = (char**)malloc((size + 1) * sizeof(char*));
	y = 0;
	while (y < size)
	{
		fld[y] = (char*)malloc((size + 1) * sizeof(char));
		x = 0;
		while (x < size)
			fld[y][x++] = '.';
		fld[y++][x] = '\0';
	}
	fld[y] = NULL;
	return (fld);
}

size_t		min_size(size_t n_figs)
{
	size_t	res;

	res = 2;
	while (res * res < n_figs * 4)
		res++;
	return (res);
}
