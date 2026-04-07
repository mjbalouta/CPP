# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 17:41:19 by mjoao-fr          #+#    #+#              #
#    Updated: 2026/04/07 11:12:37 by mjoao-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS	= -Wall -Wextra -Werror -g -std=c++98
NAME		= RPN
SRCS		= main.cpp RPN.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "RPN compiled."
	@c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@c++ $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Object files deleted."
	@rm -f $(OBJS)

fclean: clean
	@echo "Executable removed."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

