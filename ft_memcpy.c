/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:01:07 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/27 16:02:16 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s_src;
	char		*s_dst;
	size_t		i;

	s_src = src;
	s_dst = dst;
	if (src < dst)
	{
		i = n;
		while (--i < n)
			s_dst[i] = s_src[i];
	}
	else
	{
		i = 0;
		--i;
		while (++i < n)
			s_dst[i] = s_src[i];
	}
	return (dst);
}
