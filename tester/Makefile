CPP = cc
CPP_FLAGS = #-Wall -Wextra -Werror
INCLUDES = -I ./includes

# Path: PrintfのMakefileおよび実行ファイルが存在するディレクトリ
PRINTF_DIR = ../

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRC_NAME = main.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

PRINTF_NAME = libftprintf.a
NAME = ./tester

all: $(NAME)
	@ $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR)
	mv $(PRINTF_DIR)/$(PRINTF_NAME) .
	$(CPP) $(CPP_FLAGS) $(INCLUDES) $(PRINTF_NAME) $(SRCS) -o $(NAME)

clean:
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(PRINTF_NAME)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CPP) $(CPP_FLAGS) $(INCLUDES) -o $@ -c $<

.PHONY: test all clean fclean re