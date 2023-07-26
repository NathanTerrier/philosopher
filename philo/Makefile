# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 00:18:41 by naterrie          #+#    #+#              #
#    Updated: 2023/07/01 00:18:41 by naterrie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLEU := \033[36m
PURPLE := \033[35m
GREEN := \033[32m
RED := \033[31m
RESET := \033[0m
ERASE := \033[2K\033[1A\r

DIR_SRCS := src
DIR_OBJS := .objs

OBJS =	$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))

NAME =	philosopher

CFLAGS = -Wall -Werror -Wextra -I $(INC_DIR) -g3 -pthread

HEADERS = $(NAME).h
INC_DIR = includes
INC		= $(addprefix $(INC_DIR)/, $(HEADERS))

SRCS =	main.c \
		parsing.c \
		init.c \
		routine.c \
		actions.c \
		utils.c \
		time.c \
		mutex.c

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIB)
	cc $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	echo "$(GREEN)✅ $(NAME) compilated !"
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INC) Makefile
	echo "$(GREEN)⏳ Making $(NAME)"
	printf "$(BLEU) ⮡ Making $(RESET)$@$(RED)"
	cc $(CFLAGS) -c $< -o $@ -I.
	sleep 0.05
	printf "$(ERASE)"

$(DIR_OBJS):
	mkdir -p $@

clean:
	echo "$(PURPLE)🧹Removing $(NAME).o files !"
	rm -rf $(DIR_OBJS)

fclean: clean
	echo "$(PURPLE)🧹Removing $(NAME:.a=) !"
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re all

.SILENT:
