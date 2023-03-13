CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY_SRCS = ft_printf.c \
	flags.c \
	list.c \
	list_utils.c \
	substr_size_t.c \
	uitoa_base.c \
	conversions.c \
	conversion_c.c \
	conversion_s.c \
	conversion_u.c \
	conversion_percent.c \
	string.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar r $(NAME) $(MANDATORY_OBJS)

clean:
	$(RM) $(MANDATORY_OBJS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: make clean fclean re
