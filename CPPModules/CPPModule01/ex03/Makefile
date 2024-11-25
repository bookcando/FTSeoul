# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:52:46 by minsulee          #+#    #+#              #
#    Updated: 2023/06/14 14:41:49 by minsulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = attack_test

CXX = c++
SRCS = HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

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
