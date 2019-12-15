.PHONY: all clean fclean re

NAME =	ft_gkrillm
CC =	clang++
FLAGS =	-Werror -Wextra -Wall
LIB =  -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -lncurses
SDIR =	src/
ODIR =	obj/
IDIR =	includes/
SRC =	main.cpp Monitor.cpp Ncurses.cpp line_to_image.cpp 
INC =	IMonitorDisplay.hpp IMonitorModule.hpp Monitor.hpp header.hpp Ncurses.hpp
OBJ =	$(SRC:.cpp=.o)
I =		$(addprefix $(IDIR), $(INC))
S =		$(addprefix $(SDIR), $(SRC))
O =		$(addprefix $(ODIR), $(OBJ))

all: fclean $(NAME)

$(NAME): $(O)
	@$(CC) $(FLAGS) -o $@ $^ -I $(IDIR) $(LIB)

$(ODIR)%.o: $(SDIR)%.cpp $(I)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(IDIR) -I /usr/local/include 

$(O): | ./objects
./objects:
	@mkdir $(ODIR)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
