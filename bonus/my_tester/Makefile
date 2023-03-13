CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
NAME = printf

all: $(NAME)

$(NAME):
	make -C ../
	$(CC) $(SRCS) ../libftprintf.a -o $(NAME)
	./printf

clean:
	

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: make clean fclean re
