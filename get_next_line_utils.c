/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:29:23 by krwongwa          #+#    #+#             */
/*   Updated: 2024/02/18 19:13:37 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	j = 0;
	i = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destt;
	unsigned char	*srcc;

	srcc = (unsigned char *)src;
	destt = (unsigned char *)dest;
	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}
