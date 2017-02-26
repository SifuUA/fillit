/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_s_from_stream_or_file.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:02:39 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/27 16:03:30 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		write_to_temp_file(int fd)
{
	char	s1[8192];
	int		nbytes;
	int		fd_temp;
	int		res;

	res = 0;
	fd_temp = open("temp.txt", O_WRONLY | O_TRUNC | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_temp == -1)
		return (0);
	else
	{
		nbytes = 1;
		while (nbytes != 0)
		{
			nbytes = read(fd, s1, 8192);
			write(fd_temp, s1, nbytes);
			res += nbytes;
		}
		close(fd_temp);
	}
	return (res);
}

char			*get_s_from_stream(int fd)
{
	int		s_len;
	int		nbytes;
	int		i;
	char	*s;
	int		fd_temp;

	s_len = write_to_temp_file(fd);
	fd_temp = open("temp.txt", O_RDONLY);
	if (fd != -1)
	{
		s = (char*)malloc((s_len + 1) * sizeof(char));
		nbytes = 1;
		i = 0;
		while (nbytes != 0 && nbytes != -1)
		{
			nbytes = read(fd_temp, s + i, s_len - i);
			i += nbytes;
		}
		close(fd_temp);
		s[i] = '\0';
	}
	else
		s = 0;
	return (s);
}

char			*get_s_from_file(char *filename)
{
	int		fd;
	char	*s;

	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		s = get_s_from_stream(fd);
		close(fd);
	}
	else
		s = 0;
	return (s);
}
