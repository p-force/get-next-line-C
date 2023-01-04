/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 03:14:51 by student           #+#    #+#             */
/*   Updated: 2020/07/29 17:07:45 by bember           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len1;
	size_t			len2;
	size_t			i;
	char			*mem;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!mem)
		return (NULL);
	while (*s1 != '\0')
		mem[i++] = *s1++;
	while (*s2 != '\0')
		mem[i++] = *s2++;
	mem[i] = '\0';
	return (mem);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t			i;
	char			*s;

	i = 0;
	s = (char*)src;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char*)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char			*mem;
	int				len;
	int				i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	mem = (char*)malloc(sizeof(char) * (len + 1));
	if (mem)
	{
		while (*s != '\0')
			mem[i++] = *s++;
	}
	else
		return (NULL);
	mem[i] = '\0';
	return (mem);
}
