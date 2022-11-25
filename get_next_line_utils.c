//header missing 
#include"get_next_line.h"
// start strdup
char	*ft_strdup(const char *str)
{
	size_t	stlen;
	size_t	size;
	char	*ptr;
	size_t	i;

	stlen = strlen((char *)str) + 1; // strlen 
	size = sizeof (*((char *) str));
	i = 0;
	ptr = (char *) calloc(stlen, size); // calloc
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
	if (strlen(s) < len) //strlen
		len = strlen(s) - i; //strlen
	if (i >= strlen(s)) //strlen
		return (ft_strdup(""));
	ptr = calloc(len + 1, sizeof(*s)); //calloc
	if (!ptr)
	{
		return (0);
	}
	if (ptr != NULL)
	{
		return (memmove(ptr, s + i, len)); //memnmove
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
		s1 = malloc(2);// allocat to s1;
		s1[0] = '\0';
	}
    s1_len = strlen(s1);//forbiden function strlen
    s2_len = strlen(s2);//forbiden function strlen
    ptr = calloc(s1_len + s2_len + 1 , sizeof(char));// ft_calloc is missing
    if (!ptr)
	{
		//free((void*)s1);
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