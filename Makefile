# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 03:29:05 by zombunga          #+#    #+#              #
#    Updated: 2024/10/31 12:04:57 by zombunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	./src/main.c			\
		./src/init.c			\
		./src/render.c			\
		./src/events.c			\
		./src/math_utils.c		\
		./src/verify_args.c		\
		./src/string_utils.c	\
		./src/error_handling.c

OBJS_DIR = objs
OBJS = $(SRCS:./src/%.c=$(OBJS_DIR)/%.o)

LIBSTATICS_DIR = ./includes/minilibx-linux
LIBSTATICS = -L.$(LIBSTATICS_DIR) $(LIBSTATICS_DIR)/libmlx_Linux.a -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBSTATICS_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBSTATICS) -O1 -o $(NAME)
	@echo "Complete Build: $(NAME) successfuly created!"

$(OBJS_DIR)/%.o: ./src/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I./includes -I$(LIBSTATICS_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBSTATICS_DIR) clean
	@echo "Objects removed!"

fclean: clean
	@rm -rf $(NAME) $(OBJS_DIR)
	@echo "$(NAME) was removed."

re: fclean all