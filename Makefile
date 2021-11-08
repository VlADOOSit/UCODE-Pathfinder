NAME = pathfinder

FLAGS = -std=c11 $(addprefix -W, all extra error pedantic) -g

SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR	= obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

LIB_DIR	= libmx
LIB_A:=	$(LIB_DIR)/libmx.a
LIB_INC:= $(LIB_DIR)/inc


all: $(LIB_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(FLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@clang $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_INC)

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(LIB_A):
	@make -sC $(LIB_DIR)
	
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)

uninstall:
	@make -sC $(LIB_DIR) $@
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

reinstall: uninstall all
