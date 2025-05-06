# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME        = cub3d
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I./src/includes -g -O3
LDFLAGS     = -lreadline

# Directorios
LIBFT_DIR   = src/includes/libft
PARSEO_DIR  = src/parseo
FREE_DIR    = src/free
UTILS_DIR   = src/utils
RENDER_DIR	= src/render

# MLX42 Directory and options
MLX42_DIR   = src/includes/MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_LIB   = $(MLX42_BUILD)/libmlx42.a
# MLX42 dependencies (adjust as needed based on your system)
MLX_FLAGS   = -ldl -lglfw -pthread -lm

PARSEO_SRCS = \
		$(PARSEO_DIR)/get_file.c \
		$(PARSEO_DIR)/get_data.c \
		$(PARSEO_DIR)/get_color_code.c \
		$(PARSEO_DIR)/get_textures.c \
		$(PARSEO_DIR)/get_map.c \
		$(PARSEO_DIR)/check_map.c \
		$(PARSEO_DIR)/check_map_utils.c \
		$(PARSEO_DIR)/ft_get_player_pos.c \


FREE_SRCS = \

UTILS_SRCS = \
		$(UTILS_DIR)/prints.c \
		$(UTILS_DIR)/ft_join_clean.c \
		$(UTILS_DIR)/ft_clean_jump.c \
		$(UTILS_DIR)/ft_extension_cheker.c \

RENDER_SRC = \
		$(RENDER_DIR)/cub3d.c \
		$(RENDER_DIR)/render.c \
		$(RENDER_DIR)/key_management.c \
		$(RENDER_DIR)/make_map.c \
		$(RENDER_DIR)/direction.c \
		$(RENDER_DIR)/move.c \
		$(RENDER_DIR)/textures_wall.c \


MAIN_SRCS = main.c

# Unir todas las fuentes
SRCS = \
	$(MAIN_SRCS) \
	$(PARSEO_SRCS) \
	$(FREE_SRCS) \
	$(UTILS_SRCS) \
	$(RENDER_SRC)

# Create object directories
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Create necessary directories
DIRS = $(OBJ_DIR) \
       $(OBJ_DIR)/$(PARSEO_DIR) \
       $(OBJ_DIR)/$(FREE_DIR) \
       $(OBJ_DIR)/$(UTILS_DIR) \
	   $(OBJ_DIR)/$(RENDER_DIR)

# Regla principal para compilar
all: $(DIRS) $(LIBFT_DIR)/libft.a $(MLX42_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX42_BUILD) -lmlx42 $(MLX_FLAGS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

$(LIBFT_DIR)/libft.a:
	@if [ ! -f "$@" ]; then \
		make -C $(LIBFT_DIR); \
	fi

$(MLX42_LIB):
	@if [ ! -f "$@" ]; then \
		cmake -B $(MLX42_BUILD) -S $(MLX42_DIR); \
		cmake --build $(MLX42_BUILD) -j4; \
	fi

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX42_BUILD)" ]; then \
		rm -rf $(MLX42_BUILD); \
	fi

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
