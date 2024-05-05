NAME		= so_long
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -Ofast
HEADERS		= -Iinclude
MLX_FLAGS	= lib/libmlx42.a lib/libglfw3.a -framework \
			Cocoa -framework OpenGL -framework IOKit
SRCS		= mandatory/so_long.c mandatory/read_map.c mandatory/ft_split.c
# SRCS		= mandatory/so_long.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) $(HEADERS) -o $@

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test : re
	make clean
	clear && ./so_long "../assets/map.ber"
parse :
	cc mandatory/so_long.c mandatory/read_map.c mandatory/ft_split.c && ./a.out "assets/map.ber"

.PHONY: clean