# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echuong <echuong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 11:52:12 by echuong           #+#    #+#              #
#    Updated: 2022/03/17 11:52:54 by echuong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRCS = srcs/main.c \
       srcs/ft_check_char.c \
       srcs/ft_check_hv.c \
       srcs/ft_check_map.c \
       srcs/ft_check_params.c \
       srcs/ft_display.c \
       srcs/ft_draw.c \
       srcs/ft_errors.c \
       srcs/ft_free.c \
       srcs/ft_get_fc.c \
       srcs/ft_get_intersec.c \
       srcs/ft_get_map.c \
       srcs/ft_get_textures.c \
       srcs/ft_gnl.c \
       srcs/ft_handle_events.c \
       srcs/ft_handle_moves.c \
       srcs/ft_init.c \
       srcs/ft_init_data.c \
       srcs/ft_len.c \
       srcs/ft_map2d.c \
       srcs/ft_parse_file.c \
       srcs/ft_render_walls.c \
       srcs/ft_textures.c \
       srcs/ft_utils.c
 
OBJS = $(SRCS:.c=.o)

MLX = minilibx/libmlx.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./minilibx -I ./include

LIB = -L minilibx -lmlx -lXext -lX11 -lm

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS) $(MLX)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIB)

$(NAME_BONUS):	$(OBJS) $(MLX)
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME_BONUS) $(LIB)

$(MLX):
	make -C minilibx

clean:
	make -C minilibx clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
