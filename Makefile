# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvisenti <tvisenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/20 11:33:31 by tvisenti          #+#    #+#              #
#    Updated: 2016/05/13 19:36:24 by tvisenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = libftprintf.a

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	ft_apply_flags.c\
			ft_check.c\
			ft_dispatcher.c\
			ft_display_char.c\
			ft_display_numb.c\
			ft_flag_s.c\
			ft_flag_c.c\
			ft_flag_d.c\
			ft_flag_p_undefined.c\
			ft_flag_wu_wo.c\
			ft_flag_u_o.c\
			ft_flag_x.c\
			ft_handler.c\
			ft_printf.c\
			ft_buf.c\
			ft_transform_wchar.c

LIB_NAME = 	ft_atoi.c\
			ft_isdigit.c\
			ft_itoa_base.c\
			ft_strlen.c\
			ft_strsub.c\
			ft_wcharlen.c\
			ft_strlwr.c\
			ft_wstrlen.c\
			ft_wstrsub.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
	@ranlib $(NAME)
	@echo "\033[33;32m=== Compilation DONE ==="

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@echo "\033[33;32m==== clean obj DONE ===="

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "\033[33;32m===== fclean DONE ======"

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[33;32m===== Norme  DONE ======"
