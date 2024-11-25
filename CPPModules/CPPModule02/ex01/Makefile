# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 10:35:08 by minsulee          #+#    #+#              #
#    Updated: 2023/06/26 10:35:09 by minsulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed_test

CXX = c++
SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

ifdef WITH_BONUS
CXXFLAGS = -Wall -Wextra -Werror -MP -MMD -pedantic -pedantic-errors -std=c++98
else
CXXFLAGS = -Wall -Wextra -Werror -MP -MMD
endif

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

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
