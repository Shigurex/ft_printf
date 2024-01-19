CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

SRC_DIR = ./srcs
OBJ_DIR = ./objs
LIBFT_DIR = ./libft

LIBFT = libft.a

SRC_NAME = ft_printf.c \
	conversions.c \
	conversion_c.c \
	conversion_s.c \
	conversion_p.c \
	conversion_u.c \
	conversion_x.c \
	conversion_large_x.c \
	conversion_percent.c \
	unsigned.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = libftprintf.a

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar r $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re
