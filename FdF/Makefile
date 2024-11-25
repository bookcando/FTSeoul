# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 13:46:01 by minsulee          #+#    #+#              #
#    Updated: 2022/11/25 20:45:19 by minsulee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
CFLAGS_INC := -lmlx -lm -framework OpenGL -framework AppKit
RM		:= rm -fr

SRCS 	:= ml_main.c\
ml_tools.c\
ml_object_zmapping.c\
ml_drawing.c\
ml_drawing_tool.c\
ml_map_parsing.c\
ml_map_parsing_tool.c\
ml_map_reading.c\
ml_hook.c

SRCS_BONUS 	:= ml_main_bonus.c\
ml_tools_bonus.c\
ml_object_zmapping_bonus.c\
ml_object_mapping_bonus.c\
ml_drawing_bonus.c\
ml_drawing_tool_bonus.c\
ml_map_parsing_bonus.c\
ml_map_parsing_tool_bonus.c\
ml_map_reading_bonus.c\
ml_hook_bonus.c

OBJS	:= $(SRCS:.c=.o)
SRCS_H	:= ml_fdf.h
OBJS_BONUS := $(SRCS_BONUS:.c=.o)
SRCS_BONUS_H	:= ml_fdf_bonus.h
NAME := fdf

ifdef BONUS
OBJECTS := $(OBJS_BONUS)
HEADER := $(SRCS_BONUS_H)
else
OBJECTS := $(OBJS)
HEADER := $(SRCS_H)
endif

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(CFLAGS_INC) $(OBJECTS) -o $@

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

rebonus : 
	make fclean
	make bonus

.PHONY : clean re fclean all bonus rebonus
