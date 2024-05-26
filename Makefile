NAME		= so_long
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -Ofast
HEADERS		= include/so_long.h
MLX_FLAGS	= lib/libmlx42.a lib/libglfw3.a -framework \
			Cocoa -framework OpenGL -framework IOKit
SRCS		= src/so_long.c src/read_map.c src/ft_split.c src/mlx_workspace.c \
			src/initial_imgs.c src/so_long_utils.c src/parrsing.c src/setup_map.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean