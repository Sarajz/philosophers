# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/02 18:13:06 by sarajime          #+#    #+#              #
#    Updated: 2024/11/28 19:04:28 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=thread
IFLAG = -I./include

SRC_DIR = src
OBJ_DIR = obj


FILES = main.c init.c utils_libft.c utils_philo.c routine.c time.c monitor.c

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