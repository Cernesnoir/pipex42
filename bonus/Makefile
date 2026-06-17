NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = source/main.c source/close_fd.c source/check_access.c source/path.c source/erreur.c source/do_fork.c source/split_pipex.c
OBJ = $(SRC:.c=.o)
RM = rm -f
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: clean fclean re
