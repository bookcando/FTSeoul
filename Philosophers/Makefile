# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:46:01 by minsulee          #+#    #+#              #
#    Updated: 2023/03/17 16:25:14 by minsulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra

RM		:= rm -fr

SRCS 	:= philo_action.c \
philo_atoi.c \
philo_eat.c \
philo_main_init.c \
philo_main.c \
philo_monitoring.c \
philo_thread.c \
philo_util.c

HEADER := philo.h

OBJECTS	:= $(SRCS:.c=.o)

NAME := philo

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : clean re fclean all
