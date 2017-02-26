/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:27:51 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/25 21:27:54 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc.h"

int		mod(int x, int y, int x1, int y1)
{
	int	res;
	int	res1;

	res = (x - x1);
	res1 = (y - y1);
	if (res < 0)
		res = -res;
	if (res1 < 0)
		res1 = -res1;
	return (res + res1);
}

int		point_count(char *s)
{
	int i;
	int point;

	i = 0;
	point = 0;
	while (s[i])
	{
		if (s[i] == '.')
			point++;
		i++;
	}
	return (point);
}

int		sharps_count(char *s)
{
	int	i;
	int	sharps;

	i = 0;
	sharps = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		if (s[i] == '#')
			sharps++;
		i++;
	}
	if (i == 20 && (int)s[i] == 10)
		return (sharps);
	if (i > 20)
		return (0);
	return (sharps);
}

int		check(t_figure arr, char *s, int i, int count)
{
	int j;
	int x;
	int y;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		x = arr[i].x;
		y = arr[i].y;
		while (j < 4)
		{
			if (mod(x, y, arr[j].x, arr[j].y) == 1)
				count++;
			j++;
		}
		i++;
	}
	if (sharps_count(s) != 4 || (point_count(s) != 12))
		return (0);
	if (count >= 6)
		return (1);
	return (0);
}
