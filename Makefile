NAME			=	miniRT

CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall -g

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

RUN_SRCS		=	main.c

RUN_OBJS		=	$(addprefix ${BIN_DIR}, ${RUN_SRCS:.c=.o})

OBJS			=	$(RUN_OBJS)

${BIN_DIR}%.o: ${RUN_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: brew $(LIB_DIR) $(BIN_DIR) libft libmlx $(BIN_DIR) $(NAME)
	@echo "miniRT compiled!"

$(NAME): $(OBJS)
	@echo "compiling miniRT!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

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

.PHONY: all clean fclean re libmlx brew
