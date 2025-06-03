##
## EPITECH PROJECT, 2025
## Jofrenstein3D
## File description:
## Makefile
##

NAME = ../liblogger.a
DEBUG_NAME = ../liblogger.a

CC = gcc

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DBG_DIR     = $(BUILD_DIR)/debug

CFLAGS = -Wall -Wextra -Werror -iquote include
DEBUG_CFLAGS = -g -fsanitize=address -DDEBUG

SRC = \
	logger.c \
	logger_create.c \
	logger_destroy.c \
	logger_create_file.c \
	logger_vlog.c \
	level.c

REAL_SRC = $(addprefix src/, $(SRC))
OBJ = $(REAL_SRC:src/%.c=$(OBJ_DIR)/%.o)
DEBUG_OBJ = $(REAL_SRC:src/%.c=$(DBG_DIR)/%.debug.o)

all: dirs $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: dirs $(DEBUG_OBJ)
	ar rcs $(DEBUG_NAME) $(DEBUG_OBJ)

%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$(notdir $@)

%.debug.o: %.c
	@mkdir -p $(DBG_DIR)
	$(CC) $(CFLAGS) -c $< -o $(DBG_DIR)/$(notdir $@)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(DBG_DIR)/%.debug.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

dirs:
	@mkdir -p $(OBJ_DIR) $(DBG_DIR)

clean:
	rm -rf $(OBJ_DIR) $(DBG_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug debugre dirs
