/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:05:42 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/07 14:33:45 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_getmem(char ***ptrtab, char const *s, char c)
{
	size_t		i;
	int			i_word;
	int			i_inword;

	i_word = -1;
	i_inword = -1;
	i = 0;
	while (s[i] != '\0')
		if (s[i++] != c)
		{
			if (i_inword == -1)
				i_word++;
			i_inword++;
		}
		else
			i_inword = -1;
	(*ptrtab) = (char**)malloc((i_word + 2) * sizeof(char*));
	if ((*ptrtab) != NULL)
		(*ptrtab)[i_word + 1] = NULL;
	return (i_word + 1);
}

static char		*copy_word(char const *s, size_t *i, char c)
{
	size_t	word_len;
	size_t	i_inword;
	char	*res;

	i_inword = *i;
	while (s[i_inword] != c && s[i_inword] != '\0')
		i_inword++;
	word_len = i_inword - *i;
	res = ft_strnew(word_len);
	if (res != NULL)
		ft_memcpy(res, (s + *i), word_len);
	(*i) = i_inword + 1;
	while (s[*i] == c)
		(*i)++;
	return (res);
}

static void		ft_strsplit_freemem(char **tab)
{
	int		i_word;

	if (tab != NULL)
	{
		i_word = 0;
		while (tab[i_word] != NULL)
			free(tab[i_word]);
		free(tab);
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		n_words;
	int		i_word;
	size_t	i;
	char	**tab;

	if (s == NULL)
		return (NULL);
	n_words = ft_strsplit_getmem(&tab, s, c);
	if (tab == NULL)
		return (NULL);
	i_word = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (i_word < n_words)
	{
		tab[i_word] = copy_word(s, &i, c);
		if (tab[i_word] == NULL)
		{
			ft_strsplit_freemem(tab);
			return (NULL);
		}
		i_word++;
	}
	return (tab);
}
