# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:13:06 by sarajime          #+#    #+#              #
#    Updated: 2024/09/16 16:57:20 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -g -Wall -Wextra -Werror 
IFLAG = -I./include

SRC_DIR = src
OBJ_DIR = obj


FILES = main.c print.c init.c utils.c getset.c routine.c time.c monitor.c

all: $(NAME)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

$(NAME): $(OBJ_FILES)
	gcc $(CFLAGS) $(IFLAG) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re