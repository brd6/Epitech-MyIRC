##
## Makefile for Makefile in PSU_2016_nmobjdump
##
## Made by jonathan bruel
## Login   <bruel_a@epitech.net>
##
## Started on  Thu Dec 10 10:45:14 2015 jonathan bruel
## Last update Tue Jun  6 07:24:09 2017 bruel_a
##

##
## !*********!
## ! Sources !
## !*********!
##

SRC =		src/main.c \
		src/error_handler.c \
		src/freetab.c \
		src/tabdup.c \
		src/tablen.c \
		src/hosts.c \
		src/loop.c \
		src/str_to_wordtab.c \
		src/get_next_line.c \
		src/get_next.c \
		src/read_server.c \
		src/read_user.c \
		src/write_server.c \
		src/cmd/server.c \
		src/cmd/nick.c \
		src/cmd/exit.c \
		src/cmd/users.c \
		src/cmd/part.c \
		src/cmd/list.c \
		src/cmd/join.c \
		src/cmd/names.c \
		src/cmd/msg.c \
		src/cmd/accept_file.c \
		src/cmd/default_cmd.c \
		src/cmd/quit.c

##
## !*********!
## !  Utils  !
## !*********:
##

NAME =		../client

CC =		gcc

RM =		rm -f

OBJS =		$(SRC:.c=.o)

##
## !*********!
## !  Flags  !
## !*********!
##

CFLAGS =	-I./include -D_GNU_SOURCE
CFLAGS +=	-W -Wall -Wextra

##
## !***************!
## ! Instructions  !
## !***************!
##

all: 		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
