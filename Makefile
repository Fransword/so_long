GLFWLIB = lib/glfw/3.4/include

NAME	:= fdf
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
PARAMS	:= -D Z_MIN_MODE=1 -D BACKGROUND_COLOR=0x000000 -D DEFAULT_COLOR=-1 -D WIN_WIDTH=1920 -D WIN_HEIGHT=1080
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I $(GLFWLIB) -I ./include -I $(LIBMLX)/include
LIBS	:= -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm $(LIBMLX)/libmlx42.a
SRCS	:= src/bresenham.c src/color_gradient.c src/fdf.c src/figure.c \
			src/free.c src/hooks.c src/map_nodes.c src/map_reading.c \
			src/observer.c src/painting_basic.c src/painting_ordered.c \
			src/painting_utils.c src/prints.c src/transform_map.c \
			src/transform_node.c src/value_action.c src/value_reading.c
OBJS	:= ${SRCS:.c=.o}

BONUS_NAME := map_maker
BONUS_SRC := src_bonus/map_maker_bonus.c src_bonus/map_maker_utils_bonus.c \
			src_bonus/user_function_bonus.c
BONUS_OBJS	:= ${BONUS_SRC:.c=.o}
BONUS_PARAMS := -D MAP_HEIGHT=200 -D MAP_WIDTH=200

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) $(PARAMS) $(BONUS_PARAMS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(OBJS) $(HEADERS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all clean fclean re libmlx bonus