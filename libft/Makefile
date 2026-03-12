NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isascii.c ft_memset.c ft_tolower.c ft_bzero.c ft_isdigit.c ft_strchr.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_strlcat.c ft_isalpha.c ft_memcpy.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_memcmp.c ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strmapi.c ft_striteri.c get_next_line.c get_next_line.c get_next_line_utils.c ft_printf.c ft_putchar_printf.c ft_putstr_printf.c ft_putptr_printf.c ft_putnbr_int.c ft_putnbr_int.c ft_putnbr_un.c ft_putnbr_base.c ft_putnbr_uint.c
OBJ = $(SRC:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c $(includes)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
