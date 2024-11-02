# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 03:29:05 by zombunga          #+#    #+#              #
#    Updated: 2024/11/02 12:43:18 by zombunga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS =	./src/main.c			\
		./src/init.c		\
		./src/render.c		\
		./src/events.c		\
		./src/math_utils.c	\
		./src/verify_args.c	\
		./src/string_utils.c	\
		./src/error_handling.c

OBJS_DIR = objs
OBJS = $(SRCS:./src/%.c=$(OBJS_DIR)/%.o)

MATH_FLAG = -lm
LIBSTATICS_DIR = ./includes/minilibx-linux
LIBSTATICS = -L.$(LIBSTATICS_DIR) $(LIBSTATICS_DIR)/libmlx_Linux.a -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBSTATICS_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBSTATICS) $(MATH_FLAG) -o $(NAME)
	@printf "\033c"
	@echo "\033[1;14mComplete Build: \033[0;32m./$(NAME) \033[1;32msuccessfuly created!\033[0m"

$(OBJS_DIR)/%.o: ./src/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I./includes -I$(LIBSTATICS_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)
	@make -C $(LIBSTATICS_DIR) clean
	@printf "\033c"
	@echo "\033[93mobjects \033[1;31mremoved\033[93m!\033[0m"

fclean: clean
	@rm -rf $(NAME) $(OBJS_DIR)
	@printf "\033c"
	@echo "\033[1;93mAll generated files \033[1;31mremoved\033[1;93m.\033[0m"

re: fclean all
	@printf "\033c"
	@echo "\033[0;93mobjects \033[1;93mand \033[0;93m./$(NAME)\033[1m were successfuly \033[31mremoved\033[93m!\033[0m"
	@echo "\033[1;14mComplete Build: \033[0;32m./$(NAME) \033[1;32msuccessfuly created!\033[0m"