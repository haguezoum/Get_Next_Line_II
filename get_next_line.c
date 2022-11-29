/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:54 by haguezou          #+#    #+#             */
/*   Updated: 2022/11/29 01:07:04 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		s1_len;
	size_t		s2_len;
	char		*ptr;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!ptr)
		return (free(ptr), NULL);
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	return (free(s1), ptr);
}

char	*chunck(char *s)
{
	int	i;

	i = 0;
	if (s[0] == 0)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*restof(char *s)
{
	int		i;
	int		s_len;
	char	*line;

	s_len = (int)ft_strlen(s);
	i = 0;
	if (s[i] == 0)
	{
		free(s);
		return (NULL);
	}
	while (s[i] != '\n' && s[i])
		i++;
	line = ft_substr((char *)s, i + 1, s_len - (i));
	free(s);
	return (line);
}

char	*string(int fd, char *line)
{
	char	*buff;
	int		bytes;

	bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff == NULL)
		return (free(line), NULL);
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			break ;
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = string(fd, line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	tmp = chunck(line);
	line = restof(line);
	return (tmp);
}
