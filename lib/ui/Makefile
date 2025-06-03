##
## EPITECH PROJECT, 2025
## Jofrenstein3D
## File description:
## Makefile (lib)
##

NAME = ../libui.a
DEBUG_NAME = ../libui.a

CC = gcc

BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj
DBG_DIR     = $(BUILD_DIR)/debug

CFLAGS = -Wall -Wextra -Werror -iquote include -iquote ../hashmap/include
DEBUG_CFLAGS = -g -fsanitize=address -DDEBUG

APP_SRC = \
	ui_app_create.c \
	ui_app_add_page.c \
	ui_app_set_active_page.c \
	ui_app_draw.c \
	ui_app_handle_event.c \
	ui_app_push_page.c \
	ui_app_pop_page.c \
	ui_app_current_page.c \
	ui_app_destroy.c \
	ui_app_draw_debug_outline.c \
	ui_app_get_current_page_name.c

BUTTON_SRC = \
	ui_button_create.c \
	ui_button_draw.c \
	ui_button_handle_event.c \
	ui_button_destroy.c

ENUM_SELECTOR_SRC = \
	ui_enum_selector_create.c \
	ui_enum_selector_draw.c \
	ui_enum_selector_handle_event.c \
	ui_enum_selector_destroy.c

GEOMETRY_SRC = \
	ui_rect_to_pixels.c \
	ui_point_to_proportions.c \
	interpolate.c \
	compute_sprite_size.c

IMAGE_BUTTON_SRC = \
	ui_image_button_create.c \
	ui_image_button_destroy.c \
	ui_image_button_handle_event.c \
	ui_image_button_draw.c

IMAGE_FILL_SRC = \
	ui_image_fill_create.c \
	ui_image_fill_destroy.c \
	ui_image_fill_handle_event.c \
	ui_image_fill_draw.c

LAYOUT_SRC = \
	ui_layout_col.c \
	ui_layout_row.c

PAGE_SRC = \
	ui_page_create.c \
	ui_page_destroy.c \
	ui_page_add_widget.c \
	ui_page_draw.c \
	ui_page_handle_event.c

SLIDER_SRC = \
	ui_slider_create.c \
	ui_slider_draw.c \
	ui_slider_handle_event.c \
	ui_slider_destroy.c

TEXTBOX_SRC = \
	ui_textbox_create.c \
	ui_textbox_handle_event.c \
	ui_textbox_draw.c \
	ui_textbox_destroy.c

WIDGET_SRC = \
	ui_widget_draw.c \
	ui_widget_handle_event.c \
	ui_widget_debug_outline.c \
	ui_widget_destroy.c

SRC = \
	$(addprefix app/, $(APP_SRC)) \
	$(addprefix button/, $(BUTTON_SRC)) \
	$(addprefix enum_selector/, $(ENUM_SELECTOR_SRC)) \
	$(addprefix geometry/, $(GEOMETRY_SRC)) \
	$(addprefix image_button/, $(IMAGE_BUTTON_SRC)) \
	$(addprefix image_fill/, $(IMAGE_FILL_SRC)) \
	$(addprefix layout/, $(LAYOUT_SRC)) \
	$(addprefix page/, $(PAGE_SRC)) \
	$(addprefix textbox/, $(TEXTBOX_SRC)) \
	$(addprefix slider/, $(SLIDER_SRC)) \
	$(addprefix widget/, $(WIDGET_SRC))

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
