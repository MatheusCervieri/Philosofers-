# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 11:10:22 by mvieira-          #+#    #+#              #
#    Updated: 2022/08/16 20:38:02 by mvieira-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE_PATH = ./
SRCS_PATH = ./
OBJS_PATH = ./
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE_PATH) -pthread
RM = rm -f
NAME = philo
SRC_FILES = main.c \
			time.c \
			error.c \
			initialization.c \
			utils.c \
			exit_handle.c \
			create_thread.c \
			print_stage.c

SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

all: $(NAME)
	
$(NAME): $(OBJECTS) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re