NAME			=	miniRT

ifeq ($(shell uname -s),Linux)
    OS := Linux
    LDFLAGS := -ldl -lglfw -pthread -lm
else ifeq ($(shell uname -s),Darwin)
    OS := macOS
    LDFLAGS := -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit
endif

CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall -g #-fsanitize=address

COLOUR_GREEN	=	\033[0;32m
COLOUR_YELLOW	=	\033[0;33m
COLOUR_RED		=	\033[0;31m
COLOUR_END		=	\033[0m

LIB_DIR			=	lib/
LIBFT_DIR		=	$(LIB_DIR)libft/
LIBFT			=	$(LIB_DIR)libft/libft.a
LIBFT_GIT_URL	=	https://github.com/ztrottie/libft.git
LIBFT_VERSION	=	v1.0.0

LIBMLX_DIR		=	$(LIB_DIR)MLX42/
LIBMLX			=	$(LIBMLX_DIR)build/libmlx42.a
LIBMLX_GIT_URL	=	https://github.com/codam-coding-college/MLX42.git
LIBMLX_VERSION	=	v2.3.2

BIN_DIR			=	bin/

RUN_DIR			=	src/run/
MATH_DIR		=	src/maths/
RENDERER_DIR	=	src/renderer/
PARSING_DIR		=	src/parsing/
KEY_DIR			=	src/key_hook/

RUN_SRCS		=	main.c

PARSING_SRCS	=	get_map.c\
					sphere.c\
					cylinder.c\
					plane.c\
					error.c\
					run_scene.c\
					utils.c\
					ambient.c\
					light.c\
					camera.c\

MATH_SRCS		=	basic_operation.c \
					basic_vector_operation.c \
					dot_product.c \
					basic_ray_operation.c \
					cross_product.c \
					matrices.c

RENDERER_SRCS	=	renderer.c \
					init_vectors.c \
					color.c \
					hit_sphere.c \
					ray_collision.c \
					light_collision.c \
					hit_plane.c \
					hit_cylinder.c

KEY_SRCS		=	key_hook.c

RUN_OBJS			=	$(addprefix ${BIN_DIR}, ${RUN_SRCS:.c=.o})
PARSING_OBJS		=	$(addprefix ${BIN_DIR}, ${PARSING_SRCS:.c=.o})
MATH_OBJS			=	$(addprefix ${BIN_DIR}, ${MATH_SRCS:.c=.o})
RENDERER_OBJS		=	$(addprefix $(BIN_DIR), ${RENDERER_SRCS:.c=.o})
KEY_OBJS			=	$(addprefix $(BIN_DIR), ${KEY_SRCS:.c=.o})

OBJS			=	$(RUN_OBJS) $(MATH_OBJS) $(RENDERER_OBJS) $(PARSING_OBJS) $(KEY_OBJS)

${BIN_DIR}%.o: ${RUN_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${PARSING_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${MATH_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

$(BIN_DIR)%.o: $(RENDERER_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)%.o: $(KEY_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: brew $(LIB_DIR) $(BIN_DIR) libft libmlx $(BIN_DIR) $(NAME)
	@echo "miniRT compiled!"

$(NAME): $(OBJS)
	@echo "compiling miniRT!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(LDFLAGS) -o $(NAME)

clean:
	@rm -fr $(BIN_DIR)
	@rm -rf $(LIBMLX_DIR)build
	@$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) clean

re: fclean all

$(LIB_DIR):
	@mkdir -p $(LIB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

libmlx:
	@if [ ! -d "$(LIBMLX_DIR)" ]; then \
        echo "libmlx directory does not exist, cloning..."; \
        git clone -b $(LIBMLX_VERSION) -q $(LIBMLX_GIT_URL) $(LIBMLX_DIR); \
	fi
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)build && make -C $(LIBMLX_DIR)build -j4

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
        echo "libft directory does not exist, cloning..."; \
        git clone -q $(LIBFT_GIT_URL) $(LIBFT_DIR); \
    else \
        echo "libft directory already exists, pulling latest version..."; \
        cd $(LIBFT_DIR) && git pull; \
	fi
	@$(MAKE) -sC $(LIBFT_DIR)

brew:
	@if command -v brew >/dev/null 2>&1; then \
        echo "$(COLOUR_GREEN)Homebrew is already installed.$(COLOUR_END)"; \
		if command -v cmake >/dev/null 2>&1; then \
			echo "$(COLOUR_GREEN)cmake is already installed.$(COLOUR_END)"; \
		else \
			echo "$(COLOUR_RED)cmake is not installed. Please follow the instructions to install it: $(COLOUR_GREEN)brew install cmake$(COLOUR_END)"; \
		fi; \
		if command -v brew --version glfw >/dev/null 2>&1; then \
			echo "$(COLOUR_GREEN)glfw is already installed.$(COLOUR_END)"; \
		else \
			echo "$(COLOUR_RED)glfw is not installed. Please follow the instructions to install it: $(COLOUR_GREEN)brew install glfw$(COLOUR_END)"; \
		fi \
    else \
        echo "$(COLOUR_YELLOW)Homebrew is not installed. Please follow the instructions of this website to install it: $(COLOUR_GREEN)https://brew.sh/index_fr$(COLOUR_END)"; \
    fi

run: re
	./miniRT

val:
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re libmlx brew run
