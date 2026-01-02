CXX=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98 -Wshadow-all
RM=rm -rf
SRC=main.cpp Bureaucrat.cpp
OBJS=$(SRC:%.cpp=%.o)
NAME=Bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

