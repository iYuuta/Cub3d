NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC_UTILS = utils/ft_putendl_fd.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_substr.c utils/get_next_line.c

SRC = $(SRC_UTILS) main.c

OBJ = $(SRC:.c=.o)

%.o: %.c include/Cupid.h
	$(CC) $(CFLAGS) -I./include -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)

bonus : all

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean