# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 12:31:17 by chruhin           #+#    #+#              #
#    Updated: 2024/03/02 11:10:17 by chruhin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the archive file
NAME				=		libftprintf.a

# color codes
GRN					=		\e[1;32m
RST					=		\e[0m

# Directories
SRC_DIR				=		src
OBJ_DIR				=		obj
INC_DIR				=		inc

# Source files
DIRS				=		specifiers main
SRCS				=		$(foreach dir,$(DIRS),$(filter %.c,$(shell find $(SRC_DIR)/$(dir) -type f)))

# Object files
OBJS				=		$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Header files
INCS				=		$(addprefix -I, $(INC_DIR))

# Compiler flags
CFLAGS				=		-Wall -Wextra -Werror

# Cleanup
RM					=		rm -rf

# No exceptions
.PHONY:						all clean fclean re

# Targets
all:						$(NAME)

# Create a directory for obj
$(OBJ_DIR):
							@mkdir -p $(OBJ_DIR)
# Compiling obj
$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c | $(OBJ_DIR)
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Compiling exec
$(NAME): 					$(OBJ_DIR) $(OBJS)
							@ar -rcs $@ $(OBJS)
							@printf "${GRN}"'Compiled successfuly'"${RST}\n"

# Remove object files
clean:
							@$(RM) $(OBJ_DIR)

# Remove obj & exec files
fclean:						clean
							@$(RM) $(NAME)

# remove all & recompile
re:							fclean all


# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# https://cs.colby.edu/maxwell/courses/tutorials/maketutor/
#
