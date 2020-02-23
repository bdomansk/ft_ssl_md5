# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:55:51 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../ft_ssl
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror 
FT_SSL_SRC = main.c error.c init_info.c md5.c sha256.c check_input.c \
	leaks_exit.c check_arguments.c read_file.c output_hash.c swap_bits.c \
	free_file_info.c sha256_handler.c rotr.c md5_handler.c
FT_SSL_OBJ = $(FT_SSL_SRC:.c=.o)
HEADER = ../includes
DEL = /bin/rm -f

.PHONY : all clean n fclean re 

all : $(NAME)

$(NAME) : $(FT_SSL_OBJ) $(LIB) 
	@echo "Compiling ft_ssl"
	@gcc $(FLAGS) $(FT_SSL_OBJ) -o $(NAME) $(LIB) 

$(FT_SSL_OBJ): $(FT_SSL_SRC) $(HEADER)
	@echo "FT_SSL objects creating"
	@gcc $(FLAGS) -c $(FT_SSL_SRC) -I $(HEADER)


$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(FT_SSL_OBJ)

n :
	@norminette $(FT_SSL_SRC) 

fclean:
	@$(DEL) $(FT_SSL_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all