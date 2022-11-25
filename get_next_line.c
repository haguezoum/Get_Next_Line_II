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

char *st_(int fd, char *line) {
    char *buff;
    int bytes;

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
    line = st_(fd, line);
    if (!line)
        return NULL;
    tmp = chunck(line);
    line = restof(line);
    return tmp;
}

// int main()
// {
//     int fd;
//     char *str;
//     str = "hello world \n ggfgf";
//     char *res = chunck(str);
//     printf("%s",res);
//         fd = open("_file.txt",O_RDONLY);
//    int i = 0;
//     while(1)
//     { 
//         if(str == NULL)
//             break;
        
//          str = get_next_line(fd);
//          printf("%s", str);
         
//         i++;
//     }
// }

// int main()
// {
//     int fd;
//     char *str;
//     fd = open("_file.txt",O_RDONLY);

    
//     while(1){
//         str = get_next_line(fd);
//         printf("%s",str);
//         break;
//     }
// }


    //this fucking function dosnt returning NUUUUUUUUL aaas   fgqgriu;gqrt
  
    // str = get_next_line(fd);
    // printf("%s",str);
    // str = get_next_line(fd);
    // printf("%s",str);
    
    // char *test = "hassan\nand this is a test";
    // char *mystr;
    //  mystr = restof(test);
    //  printf("%s",mystr);

// } main

// int main()
// {
//     char *str = "mehdi\0\nhassan\naguezoum";
//     char *ret = chunck(str);
//     puts(ret);
// }