NAME = minishell
SOURCES = \
	main.c env.c env_utils.c quotes.c piper.c spacer.c expander.c lexer.c \
	checker.c parser.c str_utils.c execute_binary.c execute.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) libft
	$(CC) -o $@ $(OBJECTS) -Llibft -lft -Llibreadline -lreadline

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft bonus

clean:
	$(RM) $(OBJECTS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
