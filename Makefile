NAME = so_long
BONUS = so_long_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

LIBFT = ./libft/libft.a
MINILIBX = ./minilibx-linux/libmlx.a

SRCS = 	mandatory/main.c \
		mandatory/operations/check.c\
		mandatory/operations/check_path.c\
		mandatory/operations/free.c\
		mandatory/operations/get.c\
		mandatory/operations/map_utils.c\
		mandatory/operations/move.c\
		mandatory/operations/utils.c\

BONUS_SRCS = bonus/main_bonus.c \
		bonus/operations/check_bonus.c\
		bonus/operations/check_path_bonus.c\
		bonus/operations/free_bonus.c\
		bonus/operations/get_bonus.c\
		bonus/operations/map_utils_bonus.c\
		bonus/operations/move_bonus.c\
		bonus/operations/utils_bonus.c\
		bonus/operations/animation_bonus.c\
		bonus/operations/enemy_bonus.c\

OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(MINILIBX):
	@$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT) $(MINILIBX)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MINILIBX) $(MFLAGS) -o $(BONUS)

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM) $(NAME) $(BONUS)

re: fclean all