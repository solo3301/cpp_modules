# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 16:49:31 by yadereve          #+#    #+#              #
#    Updated: 2024/12/03 16:41:26 by yadereve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavTrap
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = sources
OBJ_DIR = objects

SRC_FILE = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

NC = \033[0m
RED = \033[31m
ORANGE = \033[33m
GREEN = \033[92m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) -c $(CXXFLAGS) -o $@ $<
	@echo "[OK]\t$(ORANGE)"$@"$(NC)"

$(NAME): $(OBJ)
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "[OK]\t$(GREEN)$(NAME)$(NC) ready to use"
	@echo "------------------------------"

all: $(NAME)

# generate dependency files
# CXXFLAGS += -MMD

# leacks
# CXXFLAGS += -fsanitize=address

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[OK]\t$(RED)temporary object files deleted$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "[OK]\t$(NAME) $(RED)deleted$(NC)"

newLine:
	@echo ""

re: fclean newLine all

.SILENT: $(OBJ)

.PHONY: all re clean fclean newLine
