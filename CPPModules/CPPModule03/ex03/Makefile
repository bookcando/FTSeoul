NAME = diamondtrap

CXX = c++
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

ifdef WITH_BONUS
CXXFLAGS = -Wall -Wextra -Werror -MP -MMD -pedantic-errors -std=c++98
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
	rm -rf $(OBJS)

dclean :
	make clean
	rm -rf $(DEPS)

fclean :
	make dclean
	rm -rf $(NAME)

re : 
	make fclean
	make all

bonus :
	make WITH_BONUS=1 all

.PHONY : all clean dclean fclean re bonus
