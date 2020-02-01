# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:48:14 by bdomansk          #+#    #+#              #
#    Updated: 2017/12/17 18:51:01 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_SSL = ft_ssl
LIB = libft/libft.a
LIBDIR = libft
SRCRDIR = src
INCLUDES = includes/
FLAGS = -Wall -Wextra -Werror
DEL = /bin/rm -f

.PHONY : all clean n fclean re ft_ssl

all : $(FT_SSL)

ft_ssl : 
	@make -C $(SRCRDIR)

clean:
	@make -C $(SRCRDIR)/ clean
	@make -C $(LIBDIR)/ clean

n :
	@norminette $(INCLUDES)
	@make -C $(LIBDIR)/ n
	@make -C $(SRCRDIR)/ n

fclean:
	@make -C $(LIBDIR)/ fclean
	@make -C $(SRCRDIR)/ fclean

re: fclean all

