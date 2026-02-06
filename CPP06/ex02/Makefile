# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/30 15:53:58 by mjoao-fr          #+#    #+#              #
#    Updated: 2026/02/06 11:31:04 by mjoao-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS	= -Wall -Wextra -Werror -g -std=c++98
NAME		= cast
SRCS		= main.cpp Base.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Cast compiled."
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

