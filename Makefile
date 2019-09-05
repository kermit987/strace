##
## Makefile for  in /home/le_l/Workspace/strace/step3
##
## Made by Victor Le
## Login   <le_l@epitech.net>
##
## Started on  Mon Apr  4 14:35:02 2016 Victor Le
## Last update Sun Apr 10 17:31:07 2016 Victor Le
##

RM		= rm -rf

CC		= gcc

CFLAGS		+= -W -Wall -Wextra -Werror
CFLAGS		+= -I./includes

NAME		= strace

SRCS		= main.c		\
		access_reg_arg.c	\
		parse_cmd_line.c	\
		strace_cmd.c		\
		strace_cmd_child.c	\
		strace_dump_x.c		\
		strace_sopt_display.c	\
		p_init.c		\
		syscall_info.c		\
		my_wait.c

OBJS		= $(SRCS:.c=.o)

LDFLAGS		=


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
