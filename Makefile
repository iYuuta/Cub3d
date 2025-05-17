NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

SRC_UTILS = utils/ft_exit.c utils/ft_error.c utils/ft_lstnew.c utils/ft_lstadd_back.c utils/ft_lstfree.c \
			utils/ft_lstsize.c utils/ft_lstlast.c utils/ft_putendl_fd.c utils/ft_strchr.c \
			utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_substr.c \
			utils/get_next_line.c

SRC_PARSING = parsing/check_map.c

SRC_RENDERING = rendering/events.c

SRC = $(SRC_UTILS) $(SRC_PARSING) $(SRC_RENDERING) main.c

OBJ = $(SRC:.c=.o)

%.o: %.c include/Cupid.h
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -Imlx -fsanitize=address -g

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Lmlx -lmlx -lXext -lX11 -fsanitize=address -g

bonus : all

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean