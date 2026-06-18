# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/03 11:39:29 by afournie          #+#    #+#              #
#    Updated: 2026/06/18 15:14:05 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.cpp Fixed.cpp
INC			= Fixed.hpp
OBJ			= $(SRC:.cpp=.o)

CXX			= c++
CXXFLAGS	= -std=c++98 -Wall -Wextra -Werror
RM			= rm -rf

NAME		= fixed

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
