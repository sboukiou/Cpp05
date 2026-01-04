CXX=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98 -Wshadow-all
RM=rm -rf
SRC=main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp\
	RobotomyRequestForm.cpp  ShrubberyCreationForm.cpp Intern.cpp
OBJS=$(SRC:%.cpp=%.o)
NAME=Forms

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

