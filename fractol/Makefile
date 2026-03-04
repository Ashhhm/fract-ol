NAME = fractol

SRC = \
		utils/init.c \
		utils/render.c \
		utils/math.c \
		utils/event.c \
		src/main.c

HDRS = header/fractol.h

OBJS = $(SRC:.c=.o)

LIBFT_DIR = ../libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

MLX_DIR = ../mlx-linux
MLX = $(MLX_DIR)/libmlx.a

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror -g -I./header -I$(LIBFT_DIR) -I$(MLX_DIR)
MLX_FLAGS = -lXext -lX11 -lm

all : $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX) :
	@$(MAKE) -C $(MLX_DIR)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c -g $< -o $@

clean :
	/bin/rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean : clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re : fclean all

.PHONY : all clean fclean re
