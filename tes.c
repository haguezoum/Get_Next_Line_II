#include "get_next_line.h"

char    *ft_read(int fd)
{
    int     bytes;
    char    *buff;
    char    *tmp;
    static char *str;

    bytes = 1;
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));

    if(fd < 0 || BUFFER_SIZE <= 0)
    {
        free(buff);
        return (NULL);
    }
    if(buff == NULL)
        return (NULL);
    while(bytes > 0)
    {
        if(bytes == -1)
        {
            free(buff);
            free(str);
            return(NULL);
        }
        bytes = read(fd, buff, BUFFER_SIZE);
        buff[bytes] = '\0';
        str = ft_strjoin(str, buff);
        if (ft_strchr(str, '\n'))
            break;
    }
    free(buff);
    return (str);
}

int main()
{
    int     fd;
    char    *str;

    fd = open("_file.txt", O_RDONLY);
    printf("%s", ft_read(fd));
    return (0);
}