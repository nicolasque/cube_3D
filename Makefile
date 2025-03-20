# **************************************************************************** #
#                                   Makefile                                   #
# **************************************************************************** #

NAME        = cube_3d
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I./src/includes
LDFLAGS     = -lreadline

# Directorios
LIBFT_DIR   = src/includes/libft
PARSEO_DIR  = src/parseo
FREE_DIR    = src/free
UTILS_DIR   = src/utils

PARSEO_SRCS = \
		$(PARSEO_DIR)/get_file.c \

FREE_SRCS = \

UTILS_SRCS = \
		$(UTILS_DIR)/prints.c \
		$(UTILS_DIR)/ft_join_clean.c \


MAIN_SRCS = main.c

# Unir todas las fuentes
SRCS = \
	$(MAIN_SRCS) \
	$(PARSEO_SRCS) \
	$(FREE_SRCS) \
	$(UTILS_SRCS) \

# Create object directories
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Create necessary directories
DIRS = $(OBJ_DIR) \
       $(OBJ_DIR)/$(PARSEO_DIR) \
       $(OBJ_DIR)/$(FREE_DIR) \
       $(OBJ_DIR)/$(UTILS_DIR) \

# Regla principal para compilar
all: $(DIRS) $(LIBFT_DIR)/libft.a $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	mkdir -p $@

$(LIBFT_DIR)/libft.a:
	@if [ ! -f "$@" ]; then \
		make -C $(LIBFT_DIR); \
	fi

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
