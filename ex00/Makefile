# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 11:13:31 by afournie          #+#    #+#              #
#    Updated: 2026/06/03 11:13:44 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.cpp Fixed.cpp
OBJ			= $(SRC:.cpp=.o)

CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

NAME		= fixed

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
