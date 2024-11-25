# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:46:01 by minsulee          #+#    #+#              #
#    Updated: 2022/10/30 21:29:02 by minsulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
RM		:= rm -fr

SRCS 	:= sort_initial_bs0.c \
sort_initial_bs1.c \
sort_initial_sb0.c \
sort_initial_sb1.c \
sort_instruction.c \
sort_main.c \
sort_mid.c \
sort_mid_b.c \
sort_mid_s.c \
sort_small.c \
sort_stack0.c \
sort_stack1.c \
sort_stage.c \
sort_util0.c \
sort_util1.c \
sort_util2.c \
checker_util.c \
checker_parser_int.c

SRCS_BONUS := checker_main_bonus.c \
checker_parser_inst_bonus.c \
checker_parser_int_bonus.c \
checker_util_bonus.c \
sort_stack0_bonus.c \
sort_stack1_bonus.c

OBJS	:= $(SRCS:.c=.o)
SRCS_H	:= stack.h
OBJS_BONUS := $(SRCS_BONUS:.c=.o)
SRCS_BONUS_H	:= checker_bonus.h
EXEC	:= push_swap
EXEC_BONUS := checker

ifdef BONUS
OBJECTS := $(OBJS_BONUS)
HEADER := $(SRCS_BONUS_H)
NAME := $(EXEC_BONUS)
else
OBJECTS := $(OBJS)
HEADER := $(SRCS_H)
NAME := $(EXEC)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(EXEC) $(EXEC_BONUS)

re :
	make fclean
	make all

bonus :
	make BONUS=1 all

.PHONY : clean re fclean all bonus
