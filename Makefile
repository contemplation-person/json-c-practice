# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <jy.h4456@arielnetworks.co.kr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#                                                      #+#    #+#              #
#                                                     ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS_DIR 		:=	src
OBJ_DIR			:=	obj

CC				:=	gcc
NAME			:=	p_json
SRC				:=  json_c_practice.c
SRCS			:=	$(addprefix $(SRCS_DIR)/, $(SRC))
OBJS			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

RM				:=	rm -rf
CFLAGS			:=	-Wall -Wextra -Werror
INCLUDE			:=  -Ilibari

#-Ltest
LIB_PATH		:=	-Lari
LIB_DIR_NAME	:= 	-l

$(OBJ_DIR)/%.o:		$(SRCS_DIR)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME):			$(OBJS)
					@$(MAKE) -C $(LIB_PATH) libari.a
					$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIB_DIR) -o $(NAME)

all:				$(NAME)

clean:
					$(RM) $(OBJS)
					@$(MAKE) -C $(LIB_PATH) clean

fclean:				clean
					@$(MAKE) -C $(LIB_PATH) fclean
					$(RM) $(NAME)

re:					fclean
					@$(MAKE) all

bonus:				all

.PHONY:				all clean fclean re test

test: 
	gcc main.c libari.a srcs/json_c_practice.c -ljson-c -o testoutput && ./testoutput < test/reqSet/mcp_req.json
