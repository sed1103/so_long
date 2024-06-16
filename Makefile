NAME = so_long

SRCS = src/main.c \
	   src/flood_fill.c \
	   src/get_next_line.c \
	   src/get_next_line_utils.c \
	   src/ft_strdup.c \
	   src/ft_strtrim.c \
	   src/start_graphic.c \
	   src/split.c \
	   src/start_game.c \
	   src/ft_itoa.c \
	   src/check.c \
	   src/move.c \
	   src/map.c \
	   src/destroy.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LDFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.c Includes/so_long.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re