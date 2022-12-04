/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:55:47 by haguezou          #+#    #+#             */
/*   Updated: 2022/11/28 23:33:43 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	int	size;

	size = n;
	if (!dest && !src)
	{
		free(src);
		free(dest);
		return (NULL);
	}
	while (n != 0)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest - size);
}

char	*ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(count * size);
	i = 0;
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	while (i < count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		i;

	i = start;
	ptr = ft_calloc(len + 1, sizeof(*s));
	if (!ptr)
	{
		free(ptr);
		return (0);
	}
	if (ptr != NULL)
	{
		return (ft_memcpy(ptr, s + i, len));
	}
	free(ptr);
	return (NULL);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == c)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
