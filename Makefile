NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = source/main.c source/close_fd.c source/check_access.c source/path.c source/erreur.c source/do_fork.c
BONUS_SRC = bonus/main_bonus.c bonus/check_access_bonus.c bonus/close_fd_bonus.c bonus/fd_arr_bonus.c bonus/make_pipe_bonus.c bonus/num_cmd_bonus.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
RM = rm -f
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ)
	$(RM) $(NAME)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: all clean fclean re
