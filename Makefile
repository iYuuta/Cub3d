NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_UTILS = utils/ft_putendl_fd.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_substr.c utils/get_next_line.c

SRC = $(SRC_UTILS) main.c

OBJ = $(SRC:.c=.o)

%.o: %.c include/Cupid.h
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -Imlx

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Lmlx -lmlx -lXext -lX11

bonus : all

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean