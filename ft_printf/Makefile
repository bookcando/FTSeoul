# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:46:01 by minsulee          #+#    #+#              #
#    Updated: 2022/10/04 15:08:39 by minsulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
AR		:= ar
ARFLAGS := -rcs
RM		:= rm -fr

SRCS 	:= ft_printf.c\
case_dixu.c\
case_dixuhelp1.c\
case_dixuhelp2.c\
case_flag.c\
case_cs.c\
case_ppct.c\
case_uni.c

SRCS_BONUS := ft_printf_bonus.c\
case_dixu_bonus.c\
case_dixuhelp1_bonus.c\
case_dixuhelp2_bonus.c\
case_flag_bonus.c\
case_cs_bonus.c\
case_ppct_bonus.c\
case_uni_bonus.c

OBJS	:= $(SRCS:.c=.o)
OBJS_H	:= ft_printf.h
OBJS_BONUS := $(SRCS_BONUS:.c=.o)
OBJS_BONUS_H	:= ft_printf_bonus.h
NAME	:= libftprintf.a

ifdef BONUS
OBJECTS := $(OBJS_BONUS)
HEADER := $(OBJS_BONUS_H)
else
OBJECTS := $(OBJS)
HEADER := $(OBJS_H)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

bonus :
	make BONUS=1 all

.PHONY : clean re fclean all bonus
