# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 19:15:47 by yadereve          #+#    #+#              #
#    Updated: 2024/11/05 19:48:41 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
PFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(addprefix objects/, $(SRC:.cpp=.o))

NC = \033[0m
RED = \033[31m
ORANGE = \033[33m
GREEN = \033[92m

objects/%.o: %.cpp
	@mkdir -p $(@D)
	$(CC) -c $(PFLAGS) -o $@ $<
	@echo "[OK]\t$(ORANGE)"$@"$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(PFLAGS) $(OBJ) -o $(NAME)
	@echo "[OK]\t$(GREEN)$(NAME)$(NC) ready to use"
	@echo "------------------------------"

all: $(NAME)

# generate dependency files
# PFLAGS += -MMD

clean:
	@rm -rf objects/
	@echo "[OK]\t$(RED)temporary object files delete$(NC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "[OK]\t$(RED)$(NAME) delete$(NC)"

newLine:
	@echo ""

re: fclean newLine all

.SILENT: $(OBJ)

.PHONY: all re clean fclean
