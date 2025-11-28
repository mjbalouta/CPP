# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoao-fr <mjoao-fr@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/28 15:15:55 by mjoao-fr          #+#    #+#              #
#    Updated: 2025/11/28 15:28:52 by mjoao-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXXFLAGS	= -Wall -Wextra -Werror -g -std=c++98
NAME		= megaphone
SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Megaphone compiled."
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

