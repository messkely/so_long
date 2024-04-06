NAME = so_long
FILES = mandatory/so_long.c
OBJ = $(FILES:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : $(NAME)

%.o : %.c includes/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
	clear
	./so_long

.PHONY : clean