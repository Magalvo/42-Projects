# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 12:16:06 by dde-maga          #+#    #+#              #
#    Updated: 2023/10/23 17:04:25 by dde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c aux_print.c

NAME = libftprintf.a

COMPRESS = ar rcs

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

OBJS = $(SRCS:.c=.o)

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	@$(COMPRESS) $(NAME) $(OBJS) libft/*.o

$(LIBFT):
	@make -C $(LIBFTDIR) --no-print-directory

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFTDIR) clean --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR) fclean --no-print-directory

re: fclean all

.PHONY: all fclean clean re