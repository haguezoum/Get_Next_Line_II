#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//#include "get_next_line.h"
//#define BUFFER_SIZE 50

void    ft_bzero(void *string, size_t n)
{
    while (n != 0)
    {
        *(char *)string = '\0';
        n--;
        string++;
    }
}

void    *ft_calloc(size_t count, size_t size)
{
    void    *ptr;

    ptr = malloc(count * size);
    if (ptr)
        ft_bzero(ptr, count * size);
    return (ptr);
}

size_t    ft_strlen(const char *string)
{
    int    i;

    i = 0;
    if(!string)
        return 0;
    while (string[i])
    {
        i++;
    }
    return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	stlen;
	size_t	size;
	char	*ptr;
	size_t	i;

	stlen = ft_strlen((char *)str) + 1;
	size = sizeof (*((char *) str));
	i = 0;
	ptr = (char *) ft_calloc(stlen, size);
	if (ptr == NULL)
		return (NULL);
	while (stlen > i)
	{
		ptr[i] = (char)str[i];
		i++;
	}
	return (ptr);
}
int    ft_strchr(const char *s, char c)
{
    while (*s || *s == c)
    {
        if (*s == c)
        {
            return (1);
        }
        s++;
    }
    return (0);
}
char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t    s1_len;
    size_t    s2_len;
    char    *ptr;
    size_t    i;
    size_t    j;

    i = 0;
    j = 0;
    s1_len = strlen((char *)s1);
    s2_len = strlen((char *)s2);
    ptr = (char *)malloc(s1_len + s2_len + 1 * sizeof(char));
    if (!ptr)
        return (0);
    while (s1[i])
        ptr[j++] = s1[i++];
    i = 0;
    while (s2[i])
        ptr[j++] = s2[i++];
    ptr[j] = '\0';
    return (ptr);
}
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = n;
	if (!dest && !src)
	{
		return (0);
	}
	while (n != 0)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest - i);
}
void	*ft_memmove(void *dest, void *src, size_t n)
{
	int	i;

	i = n - 1;
	if (dest > src)
	{
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
		return (dest);
	}
	else
	{
		return (ft_memcpy(dest, src, n));
	}
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ptr;
	unsigned int		i;

	i = start;
	if (!s)
		return (0);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen((char *)s) - i;
	if (i >= ft_strlen((char *)s))
		return (ft_strdup(""));
	ptr = (char *)ft_calloc(len + 1, sizeof(*s));
	if (!ptr)
	{
		return (0);
	}
	if (ptr != NULL)
	{
		return ((char *)ft_memmove(ptr, (char *)s + i, len));
	}
	return (NULL);
}

char *check_new_line(char *string, char *target )
{
    int i;
    char *newstr;
    int len_string;
    i = 0;
    len_string = ft_strlen((char*)string);
    while(string[i])
    {
        
        if(string[i] == '\n')
            break;
        else
        {
            newstr[i] = string[i];
            i++;
        }
        
    }
    target = ft_substr(string, i+1,len_string - (i+1) );
    string = newstr;
    
    return string;
}
char *get_next_line(int fd)
{
    /*bufer size =  5*/
    char *buff;
    static char *line = NULL;
    int bytes_readed = 1;
    char *tmp ;
   
    buff = malloc(BUFFER_SIZE + 1 *1);  //protect buff first (NULL) !!!!!!!!!!!
  
    while(bytes_readed != 0)
    {
        bytes_readed = read(fd, buff, BUFFER_SIZE);
        if(bytes_readed == 0)
            break;
        tmp = line;
        if(line == NULL)
            line =  ft_strdup("");
        tmp = ft_strjoin(line, buff);
        if(ft_strchr(tmp, '\n'))
            break;
    }
   
    //printf("last = %d\n",bytes_readed);
    //int i = 0;
    // while(i < BUFFER_SIZE)
    // {
    //     printf(" [%d = %c] ",i, line[i]);
    //     i++;
    // }
    
    check_new_line(tmp,line);
     printf("line => %s\n", tmp);
    // while(1)
    // {
    //     bytes_readed = read(fd, buff, 30);
    //     printf("[%d] ",i++);
    //     if(bytes_readed == -1)
    //          break;
    // }
    // buff[30] = '\0';
    // while(buff)
    // {
    //     printf("%c", buff[0]);
    //     buff++;
    // }
    printf("\n");
    // while(1)
    // {
    //     bytes_readed = read(fd, buff, 20);
    //   buff[bytes_readed] = '\0';
    //     if(bytes_readed == -1)
    //         break;
    //     tmp = line;
    //     line = ft_strjoin(tmp, buff);
    //     if (strchr(line, '\n'))
    //         break;
    //     //free(tmp);
    // }
    return tmp;
}

int main()
{
    int fd;
    char *str;
    fd = open("_file.txt", O_CREAT | O_RDWR, 0777);
    //printf("fd = %d\n",fd);
    str = get_next_line(fd);
    printf("str = [%s]\n", str);
    //printf("end\n");

    /*
    while(1)
    {
        str = get_next_line(fd);
        if(str == NULL)
            break;
        printf("%s",str);
        free(str);
    }
    */
    //close(fd);
}