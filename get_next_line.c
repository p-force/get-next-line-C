/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bember <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:56:01 by bember            #+#    #+#             */
/*   Updated: 2020/07/29 19:35:37 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_rem(char **line, char **rem)
{
	char	*p_n;
	char	*tmp;

	p_n = NULL;
	if (*rem)
	{
		if ((p_n = ft_strchr(*rem, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup(*rem);
			tmp = *rem;
			*rem = ft_strdup(++p_n);
			free(tmp);
		}
		else
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (p_n);
}

char		*back(char **line, char *buf, char **rem)
{
	char	*p;
	char	*tmp;

	p = NULL;
	if ((p = ft_strchr(buf, '\n')))
	{
		*p = '\0';
		*rem = ft_strdup(++p);
	}
	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
	return (p);
}

int			get_next_line(int fd, char **line)
{
	static char *rem;
	char		buf[BUFFER_SIZE + 1];
	char		*p_n;
	int			bwr;

	bwr = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) != 0)
		return (-1);
	p_n = check_rem(line, &rem);
	if (!*line || (p_n && !rem))
		return (-1);
	while (!p_n && (bwr = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bwr] = '\0';
		p_n = back(line, buf, &rem);
		if (!line || (p_n && !rem))
			return (-1);
	}
	if (bwr < 0)
		return (-1);
	else if (bwr > 0 || p_n)
		return (1);
	free(rem);
	rem = NULL;
	return (bwr);
}
