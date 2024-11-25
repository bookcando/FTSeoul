# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:42:14 by minsulee          #+#    #+#              #
#    Updated: 2023/06/14 14:49:33 by minsulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sad

CXX = c++
SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

ifdef WITH_BONUS
CXXFLAGS = -Wall -Wextra -Werror -pedantic -pedantic-errors -std=c++98
else
CXXFLAGS = -Wall -Wextra -Werror
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(DEPS)

fclean :
	make clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

bonus :
	make WITH_BONUS=1 all

.PHONY : all clean fclean re bonus
