NAME	:= so_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code
MLX_DIR	= ./MLX42
MLX	:= $(MLX_DIR)/libmlx42.a
HEADERS	:= -I$(MLX_DIR)
MLX_FLAGS	:= -ldl -pthread -lm
SRCS	:= so_long.c keybinding.c check.c map.c utils_map.c utils.c utils_image.c Get/get_next_line.c Get/get_next_line_utils.c printf/ft_printf.c printf/utils_printf.c
OBJS	:= ${SRCS:.c=.o}
CC	:= clang
all: $(NAME)
libmlx:
	@make -C $(MLX_DIR)
%.o: %.c
	@$(CC) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) libmlx
	@$(CC) $(OBJS) $(MLX) $(HEADERS) -ldl -lglfw -pthread -lm -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@make -C $(MLX_DIR) fclean
fclean: clean
	@rm -rf $(NAME)
re: clean all
.PHONY: all, clean, fclean, re, libmlx