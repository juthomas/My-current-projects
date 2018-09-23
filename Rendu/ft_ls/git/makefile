## Name of Project

NAME = ft_ls

## Color for compiling (pink)

COLOR = \0033[1;34m

## List of Directories

INC_DIR = includes
OBJ_DIR = objs
SRC_DIR = srcs
LIB_DIR = libft

TEST_DIR = test

## Compilating Utilities

FAST = -Ofast
# DEBUG = -fsanitize=address -g3
FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT
INC = $(INC_DIR:%=-I./$(LIB_DIR)/%) $(INC_DIR:%=-I./%) 
LIB = -L$(LIB_DIR) -lft

CC = clang $(FLAGS) $(INC)

## List of Functions

TEST_FT =	test \

SRC_FT = main \

## List of Utilities

SRC = $(SRC_FT:%=$(SRC_DIR)/%.c) \
		$(TEST_FT:%=$(SRC_DIR)/$(TEST_DIR)/%.c) \

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(TEST_DIR:%=$(OBJ_DIR)/%) \

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIR):
	@mkdir -p $@
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIRS): $(OBJ_DIR)
	@mkdir -p $@
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_ls.h
	@$(CC) $(INC_FRMWK) -c $< -o $@
	@echo "$(COLOR)Compiled :\t\0033[0;32m$(@:$(OBJ_DIR)/%=%)\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INC_DIR)/ft_ls.h
	@$(MAKE) -j8 $(OBJ)
	@echo "$(COLOR)Objects\t\t\0033[0;32m[Created]\0033[1;37m"
	@make -j8 -C $(LIB_DIR)
	@$(CC) $(LIB) $(FRMWK) $(OBJ) -o $@
	@echo "$(COLOR)$(NAME)\t\t\0033[0;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIB_DIR)
	@echo "$(COLOR)Objects\t\t\0033[0;31m[Deleted]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME)\t\t\0033[0;31m[Deleted]\0033[1;37m"

re: fclean all

norme:
	@norminette $(SRC) $(INC_DIR)/
	@make norme -C $(LIB_DIR)

.PHONY: all clean fclean re norme frameworks frameworks_clean