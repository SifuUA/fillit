/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/25 21:40:30 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/27 16:05:30 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t			ft_strlen(const char *s);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memalloc(size_t size);
char			*ft_strnew(size_t size);
char			**ft_strsplit(char const *s, char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);

char			*get_s_from_stream(int fd);
char			*get_s_from_file(char *filename);
#endif
