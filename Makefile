.PHONY: all clean fclean re

NAME =	ft_gkrillm
CC =	clang++
FLAGS =	
LIB =	-lncurses
SDIR =	src/
ODIR =	obj/
IDIR =	includes/
SRC =	main.cpp Time.cpp Monitor.cpp
INC =	IMonitorDisplay.hpp IMonitorModule.hpp Monitor.hpp Time.hpp header.hpp
OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: fclean $(NAME)

$(NAME): $(O)
	@$(CC) $(FLAGS) -o $@ $^ -I $(IDIR) $(LIB)

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR)

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
