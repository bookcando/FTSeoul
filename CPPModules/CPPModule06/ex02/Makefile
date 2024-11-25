SRCS := main.cpp Base.cpp A.cpp B.cpp C.cpp util.cpp
OBJS := $(SRCS:.cpp=.o)
HEAD := Base.hpp A.hpp B.hpp C.hpp util.hpp
NAME := ex02
CXX  := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

ifdef DEBUG
	CXXFLAGS += -g3 -fsanitize=address -DDEBUG
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

fclean: 
	make clean
	rm -f $(NAME)

re: 
	make fclean 
	make -j8 all

.phony: all clean fclean re debug