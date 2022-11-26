/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:02:50 by haguezou          #+#    #+#             */
/*   Updated: 2022/11/16 13:02:52 by haguezou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
// #include<crtdbg.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42 // if we whan to compile our code  witout defining BUFEER_SIZE at compile time (e.g -D BUFFER_SIZE=42)
#endif

char    *get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
int     ft_strchr(const char *s, char c);
char    *ft_strjoin(char *s1, char *s2);
#endif
