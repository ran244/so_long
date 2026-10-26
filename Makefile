NAME = so_long
SRCS = src/mlx.c src/cheching.c src/put_image.c src/validating.c src/movement.c src/flood_fill.c src/exit.c
OFILES =  $(SRCS:src/%.c=obj/%.o)
lib = libft/libft.a
lib_path=./libft
mlx_path= ./minilibx-linux
CFLAG = -Wall -Wextra -Werror -g -I.

MLX_GIT_REPO	= git@github.com:42paris/minilibx-linux.git
MLX_DIR			= MLX
MLX_LIB			= $(MLX_DIR)/libmlx.a

all: $(lib) $(MLX_LIB) $(NAME)

$(lib):
	make -C $(lib_path)
$(MLX_DIR):
	@echo "$(LAVENDER)Cloning MLX FROM GITHUB...$(RESET)"
	@echo "$(LAVENDER)clone into MLX$(RESET)"
	@git clone $(MLX_GIT_REPO) $(MLX_DIR) > /dev/null 2>&1
	@echo "$(LAVENDER)MLX cloned successfuly into my project $(ARROW)$(RESET)"

$(MLX_LIB): $(MLX_DIR)
	@echo "$(LAVENDER)building minilibx...$(RESET)"
	@make --no-print-directory -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(LAVENDER)MLX built $(ARROW)$(RESET)"
# 	> /dev/null 2>&1


$(NAME): $(OFILES) $(lib) $(MLX_LIB)
	cc $^ $(CFLAG) -g -lXext -lX11 -lm -o $@

obj/%.o: src/%.c
	mkdir -p obj
	cc $(CFLAG) -c $< -o $@

clean :
		make -C $(lib_path) clean
		rm -f $(OFILES)
		rm -rf obj

fclean : clean
		make -C $(lib_path) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re LIB
