##
## EPITECH PROJECT, 2025
## myworld
## File description:
## Makefile
##

# The executable file name
EXEC = wolf3d
# The path of all sources file
SRC_PATH = src

TEST_PATH = tests

# The path of all headers file
INC_PATH = \
	./include/ \
	./lib/my/include/ \
	./lib/vector/include/ \
	./lib/hashmap/include/ \
	./lib/logger/include/ \
	./lib/ui/include/

# All the sources of the project
SRC = \
	$(addprefix settings/, $(SETTINGS_SRC)) \
	$(addprefix process/, $(PROCESS_SRC)) \
	$(addprefix utils/, $(UTILS_SRC)) \
	$(addprefix asset_manager/, $(ASSET_MANAGER_SRC)) \
	$(addprefix game_map/, $(GAME_MAP_SRC)) \
	$(addprefix entity_manager/, $(ENTITY_MANAGER_SRC)) \
	$(addprefix level/, $(LEVEL_SRC)) \
	$(addprefix render/, $(RENDER_SRC)) \
	$(addprefix callback/, $(CALLBACK_SRC)) \
	$(addprefix entity_logic/, $(ENTITY_LOGIC_SRC)) \
	$(addprefix listeners/, $(LISTENER_SRC)) \
	handle_movement.c \
	main.c \
	jofreinstein.c\

CALLBACK_SRC = \
	exit_callback.c \
	singleplayer_callback.c \
	go_back_callback.c \
	load_game_callback.c \
	multiplayer_callback.c \
	create_game_callback.c \
	settings_callback.c \
	graphical_enum_selector_callback.c \
	musics_slider_callback.c \
	sounds_slider_callback.c \
	sensibility_slider_callback.c \
	world_name_callback.c

SETTINGS_SRC = \
	settings_load.c \
	settings_default.c \
	settings_save.c

ENTITY_LOGIC_SRC = \
	$(addprefix logic/, $(ENTITY_LOGIC_LOGIC_SRC)) \
	$(addprefix player/, $(ENTITY_LOGIC_PLAYER_SRC)) \
	entity_logic_create.c \
	entity_logic_destroy.c \
	entity_logic_register.c \
	entity_logic_register_tag.c \
	entity_logic_construct_data.c \
	entity_logic_destroy_data.c \
	entity_logic_apply.c

ENTITY_LOGIC_PLAYER_SRC = \
	player_constructor.c \
	player_set_weapon.c \
	player_start_attack.c \
	player_update_interaction.c \
	player_handle_attack.c

ENTITY_LOGIC_LOGIC_SRC = \
	entity_hoppy_logic.c \
	entity_player_logic.c \
	entity_heal_logic.c \
	entity_jojo_logic.c \
	entity_projectile_logic.c

RENDER_SRC = \
	setup_only_button_page.c \
	setup_game_page.c \

ASSET_MANAGER_SRC = \
	$(addprefix parser/, $(ASSET_MANAGER_PARSER_SRC)) \
	asset_manager_create.c \
	asset_manager_destroy.c \
	asset_manager_load_textures_from_file.c \
	asset_manager_get_texture.c \
    asset_manager_get_entity.c \
    asset_manager_get_sound.c \
    asset_manager_get_music.c \
    asset_manager_get_font.c \
    asset_manager_get_shader.c

ASSET_MANAGER_PARSER_SRC = \
	parse_texture_line.c \
	parse_sound_line.c \
	parse_shader_line.c \
    parse_music_line.c \
	parse_font_line.c \
	parse_entity_line.c

GAME_MAP_SRC = \
	load_map_from_file.c \
	game_map_destroy.c

LEVEL_SRC = \
	load_level_from_file.c \
	destroy_level.c \
	level_save_in_file.c

ENTITY_MANAGER_SRC = \
	create_entity_from_line.c \
	entity_manager_get_by_tag.c \
	entity_manager_add.c \
	entity_manager_create.c \
	entity_manager_mark_for_removal.c \
	entity_manager_destroy.c \
	entity_manager_for_each.c \
	entity_manager_print.c \
	entity_manager_cleanup.c \
	entity_manager_sort.c

UTILS_SRC = \
	log.c \
	get_original_win_size.c \
	cast_ray.c \
	compute_angle.c \
	compute_orientation.c \
	vector2f_to_angle.c \
	compute_distance.c \
	format_rotation.c \
	update_sound_listener.c \
	music_switch.c \
	update_music_volume.c

PROCESS_SRC = \
	process_setup.c \
	process_setup_computer.c \
	process_cleanup.c \
	process_update_clock.c \
	process_set_window_fullscreen.c \
	process_update_window.c \
	process_load_assets.c \
	process_render.c \
	process_render_computer.c \
	process_render_player_interface.c \
	process_render_entities.c \
	process_render_roof_and_top.c \
	process_render_walls.c \
	process_draw_scene_to_window.c \
	process_render_weapon.c

CALLBACK_SRC = \
	exit_callback.c \
	singleplayer_callback.c \
	go_back_callback.c \
	load_game_callback.c \
	multiplayer_callback.c \
	create_game_callback.c \
	settings_callback.c \
	graphical_enum_selector_callback.c \
	musics_slider_callback.c \
	sounds_slider_callback.c \
	sensibility_slider_callback.c \
	world_name_callback.c

RENDER_PAGES_SRC = \
	pages_register.c \
	register_main_page.c \
	setup_widget_data.c \
	setup_widgets_data.c \
	register_create_game_page.c \
	register_singleplayer_page.c \
	register_settings_page.c \
	add_default_menu.c \
	register_load_game_page.c \
	register_in_game_page.c

RENDER_WIDGETS_PREVIEW_SRC = \
	preview_widget_create.c \
	preview_widget_draw.c \
	preview_widget_handle_event.c \
	preview_widget_destroy.c

RENDER_WIDGETS_SRC = \
	$(addprefix preview/, $(RENDER_WIDGETS_PREVIEW_SRC)) \

RENDER_SRC = \
	$(addprefix pages/, $(RENDER_PAGES_SRC)) \
	$(addprefix widgets/, $(RENDER_WIDGETS_SRC))

LISTENER_SRC = \
	handle_movements.c \
	ingame_interaction_listener.c

# Path to the lib folder
LIB_PATH = lib

LIBS_NAMES = ui my hashmap vector logger

# Compilation flags
CFLAGS = -Wall -Wextra

# Pre processing compilation flags
CPPFLAGS = -L./$(LIB_PATH) $(addprefix -l, $(LIBS_NAMES)) \
	-lcsfml-graphics \
	-lcsfml-window \
	-lcsfml-system \
	-lcsfml-audio \
	-lm \
	$(HEADER_PATHS)

# Compliation flags added when using debug rule
DEBUG_CFLAGS = -static-libasan -g3 -fsanitize=address

# Pre processing compilation flags added when using debug rule
DEBUG_CPPFLAGS =

CURRENT_RULE = all

HEADER_PATHS = $(addprefix -iquote , $(INC_PATH))

SOURCES = $(addprefix $(SRC_PATH)/, $(SRC))

OBJ = $(SOURCES:.c=.o)

LIBS_FULL_PATH = $(addprefix $(LIB_PATH)/, $(LIBS_NAMES))

LIBS_RULES = $(addprefix make_, $(LIBS_FULL_PATH))

all : forgelibs_all $(EXEC)

.FORCE:
	@true

make_$(LIB_PATH)/% :
	$(MAKE) $<

.FORCE:
forgelibs_% :
	@$(foreach lib, $(LIBS_FULL_PATH), \
	$(MAKE) -C $(lib) $(subst forgelibs_,,$@) &&) true

debug : CFLAGS += $(DEBUG_CFLAGS)
debug : CPPFLAGS += $(DEBUG_CPPFLAGS)
debug : forgelibs_debug $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean :
	$(RM) $(OBJ)

mrclean : clean
	$(RM) $(EXEC)

fclean : mrclean
	$(MAKE) forgelibs_fclean

ll: fclean all

re : fclean
	$(MAKE) forgelibs_re
	$(MAKE) $(EXEC)

my : re
	make clean

debugre : mrclean
	$(MAKE) debug

.PHONY: all clean fclean mrclean forgelibs debug debugre re ll .FORCE
