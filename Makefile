NAME = pathfinder

CFLG = -std=c11 -Wall -Wextra -Werror -Wpedantic -g

INC_FILES = $(wildcard inc/*.h)
SRC_FILES = $(wildcard src/*.c)
OBJ_FILES = $(addprefix obj/, $(notdir $(SRC_FILES:%.c=%.o)))

LMX_DIR	= libmx
LMX_A:=	$(LMX_DIR)/libmx.a
LMX_INC:= $(LMX_DIR)/inc

all: install

install: $(LMX_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(CFLG) $(OBJ_FILES) -L$(LMX_DIR) -lmx -o $@

obj/%.o: src/%.c $(INC_FILES)
	@clang $(CFLG) -c $< -o $@ -I inc -I $(LMX_INC)

$(OBJ_FILES): | obj

obj:
	@mkdir -p $@

$(LMX_A):
	@make -sC $(LMX_DIR)
	
clean:
	@rm -rf obj

uninstall:
	@make -sC $(LMX_DIR) $@
	@rm -rf obj
	@rm -rf $(NAME)

reinstall: uninstall all