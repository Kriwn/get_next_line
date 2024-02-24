/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:23 by krwongwa          #+#    #+#             */
/*   Updated: 2024/02/24 14:05:12 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		str[n + i] = s2[n];
		n++;
	}
	free(s1);
	str[n + i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ans;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	ans = NULL;
	c = (unsigned char)c;
	if (c == 0)
		return (ptr + ft_strlen(s));
	while (ptr[i])
	{
		if (ptr[i] == c)
			ans = (ptr + i);
		ptr++;
	}
	return (ans);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		start = len_s;
	if (len >= len_s - start)
		len = len_s - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len_s = 0;
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
