# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 18:19:35 by mel-hadj          #+#    #+#              #
#    Updated: 2021/09/07 11:19:37 by mel-hadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BN = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c   ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c


all: $(NAME)
	
$(NAME):
	@gcc -Wall -Wextra -Werror -c ft_atoi.c \
		ft_itoa.c ft_strdup.c ft_strjoin.c ft_strchr.c\
		ft_strlen.c ft_split.c ft_calloc.c ft_bzero.c\

	@ar -rc $(NAME) *.o 
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@gcc -Wall -Wextra -Werror -c $(BN)
	@ar -rc $(NAME) *.o
