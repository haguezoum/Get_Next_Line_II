/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:55:47 by haguezou          #+#    #+#             */
/*   Updated: 2022/11/25 23:55:51 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header missing 
#include"get_next_line.h"
// start strdup
char	*ft_strdup(const char *str)
{
	size_t	stlen;
	size_t	size;
	char	*ptr;
	size_t	i;

	stlen = strlen((char *)str) + 1; //  (you can use ft_strlen from libtf project)
	size = sizeof (*((char *) str));
	i = 0;
	ptr = (char *) calloc(stlen, size); // (you can use ft_calloc from libtf project)
	if (ptr == NULL)
		return (NULL);
	while (stlen > i)
	{
		ptr[i] = (char)str[i];
		i++;
	}
	return (ptr);
}
// end strdup
// strat strsubstr
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		i;

	i = start;
	if (strlen(s) < len) //(you can use ft_strlen from libtf project)
		len = strlen(s) - i; //(you can use ft_strlen from libtf project)
	if (i >= strlen(s)) //strlen
		return (ft_strdup(""));
	ptr = calloc(len + 1, sizeof(*s)); //(you can use ft_calloc from libtf project)
	if (!ptr)
	{
		return (0);
	}
	if (ptr != NULL)
	{
		return (memmove(ptr, s + i, len)); //(you can use ft_memmove from libtf project)
	}
	return (NULL);
}
// end strsubstr
// strat strchr
int    ft_strchr(const char *s, char c)
{
    int i;
    i = 0;
    while (s[i] || s[i] == c)
    {
        if (s[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}
// end strchr
// strat strjoin
char    *ft_strjoin(char *s1, char *s2)
{
    size_t		s1_len;
    size_t		s2_len;
    char		*ptr;
    size_t		i;
    size_t		j;

    i = 0;
    j = 0;
    if(s1 == NULL)
    {
		s1 = malloc(1);// allocat to s1; (you can use ft_strdup function e.g [s1 = ft_strdup("");])
		s1[0] = '\0'; // if u use ft_strdup() dont use this line of code cuse strdup func add \0 at the last auto :)
	}
    s1_len = strlen(s1); //(you can use ft_strlen from libtf project)
    s2_len = strlen(s2); //(you can use ft_strlen from libtf project)
    ptr = calloc(s1_len + s2_len + 1 , sizeof(char));/// (you can use ft_calloc from libtf project)
    if (!ptr)
	{
		return (NULL);
	}
    while (s1[i])
        ptr[j++] = s1[i++];
    i = 0;
    while (s2[i])
        ptr[j++] = s2[i++];
    ptr[j] = '\0';
	free(s1);
    return (ptr);
}
