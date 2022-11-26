/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:09:54 by haguezou          #+#    #+#             */
/*   Updated: 2022/11/17 20:09:57 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

//strat chunck
char *chunck(char *s)
{
    int i;

    i = 0;
    if(s[0] == 0)
        return(NULL);
    while(s[i] != '\n' && s[i])
        i++;
    return (ft_substr(s, 0, i + 1));
}
 char *restof(char *s)
 {
    int i;
    int s_len;

    s_len = (int)strlen(s);
    i = 0;
    if(s[i] == 0)
    {
        free(s);
        return(NULL);
    }
    while(s[i] != '\n' && s[i])
        i++;
    return (ft_substr((char*)s, i + 1, s_len - (i)));
 }
// end rest of
// end strjoin

char *string(int fd, char *line) {
    char *buff;
    int bytes;
    int loop = 0;
    bytes = 1;
    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(buff == NULL)
        return (NULL);
    while(bytes > 0)
    {
        bytes = read(fd, buff, BUFFER_SIZE);
        if(bytes == -1)
            break;
        buff[bytes] = '\0';
        line = ft_strjoin(line, buff);
        if (ft_strchr(buff, '\n'))
            break;
    }
    free(buff);
    return line;
}
char *get_next_line(int fd)
{
    static char *line;
    char *tmp;  

    if(fd < 0 || BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    line = string(fd, line);
    if (!line)
        return NULL;
    tmp = chunck(line);
    line = restof(line);
    return tmp;
}
//main function
int main()
{
    int fd;
    char *r_str;
    fd = open("_file.txt" , O_RDONLY);

    while(1)
    {
        r_str = get_next_line(fd);
        printf("%s", r_str);
        if(r_str == NULL)
            break;
    }
}