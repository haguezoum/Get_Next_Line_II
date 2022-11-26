# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 00:24:12 by haguezou          #+#    #+#              #
#    Updated: 2022/11/26 00:28:17 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= get_next_line.c get_next_line_utils.c
CFLAGS= -Wall -Wextra -Werror
all:clean
	gcc $(CFLAGS) $(SRC)
	clear
	./a.out
clean:
		rm -rf a.out
	