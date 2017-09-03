##
## Makefile for Makefile in PSU_2016_nmobjdump
##
## Made by jonathan bruel
## Login   <bruel_a@epitech.net>
##
## Started on  Thu Dec 10 10:45:14 2015 jonathan bruel
## Last update Wed Jun 14 15:50:59 2017 bongol_b
##

DEBUG_CFLAGS	=	-g3 -DDEBUG
RELEASE_CFLAGS	=	-W -Wall -Wextra -Werror

##
## !*********!
## ! Sources !
## !*********!
##

LIB_SRCS =	src/lib/get_next_line.c \
		src/lib/my_add_elem_in_list_begin.c \
		src/lib/my_find_elm_eq_in_list.c \
		src/lib/my_get_char_pos.c \
		src/lib/my_str_split.c \
		src/lib/my_free_wordtab.c \
		src/lib/my_rm_el_from_list.c \
		src/lib/my_wordtab_count.c \
		src/lib/queue.c \
		src/lib/queue_init.c \

CMD_SRCS =	src/commands/cmd_pass.c \
		src/commands/cmd_nick.c \
		src/commands/cmd_user.c \
		src/commands/cmd_quit.c \
		src/commands/cmd_join.c \
		src/commands/cmd_names.c \
		src/commands/cmd_part.c \
		src/commands/cmd_list.c \
		src/commands/cmd_topic.c \
		src/commands/cmd_ping.c \
		src/commands/cmd_users.c \
		src/commands/cmd_privmsg.c \

SRC =		src/main.c \
		src/init_irc_server.c \
		src/error_handler.c \
		src/tools.c \
		$(LIB_SRCS) \
		$(CMD_SRCS) \
		src/packet_manager.c \
		src/packet_parser.c \
		src/command_manager.c \
		src/client_manager.c \
		src/client_manager_get.c \
		src/try_authentificate_client.c \
		src/skip_space.c \
		src/channel_manager.c \
		src/channel_manager_get.c \
		src/client_cmp.c \
		src/client_cmp2.c \
		src/channel_cmp.c \
		src/client_manager2.c \
		src/client_manager_get2.c \
		src/packet_parser2.c \
		src/handle_clients.c \
		src/handle_client_commands.c \
		src/select_utils.c \
		src/listen_clients.c \
		src/generate_client_name.c \

##
## !*********!
## !  Utils  !
## !*********:
##

NAME =		../server

CC =		gcc

RM =		rm -f

OBJS =		$(SRC:.c=.o)

##
## !*********!
## !  Flags  !
## !*********!
##

CFLAGS =	-I./include -I./include/lib -D_GNU_SOURCE

##
## !***************!
## ! Instructions  !
## !***************!
##

all: 		CFLAGS += $(RELEASE_CFLAGS)
all: 		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: $(NAME)

test:
	./tests/runtests.sh

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: 	all clean fclean re
