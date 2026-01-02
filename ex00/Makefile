CXX=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98 -Wshadow-all
RM=rm -rf
SRC=Cat.cpp Dog.cpp Animal.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
OBJS=$(SRC:%.cpp=%.o)
NAME=Polymorphism

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

