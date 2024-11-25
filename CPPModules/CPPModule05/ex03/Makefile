SRCS := Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS := $(SRCS:.cpp=.o)
HEAD := Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
NAME := ex03
CXX  := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

ifdef DEBUG
	CXXFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.cpp $(HEAD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

debug:
	make fclean
	make DEBUG=1 -j8 all

clean:
	rm -f $(OBJS)
	rm -f *_shrubbery

fclean: 
	make clean
	rm -f $(NAME)

re: 
	make fclean 
	make -j8 all

.phony: all clean fclean re debug