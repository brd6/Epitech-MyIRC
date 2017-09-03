##
## Makefile for Makefile in /home/bruel_a/rendu/Ini_IA/dante/mazes
##
## Made by jonathan bruel
## Login   <bruel_a@epitech.net>
##
## Started on  Sun Apr 24 16:53:30 2016 jonathan bruel
## Last update Tue May 23 14:04:43 2017 bruel_a
##

##
## !***************!
## ! Instructions  !
## !***************!
##

all:
			$(MAKE) -C Server
			$(MAKE) -C Client

client:
			$(MAKE) -C Client

server:
			$(MAKE) -C Server

clean:
			$(MAKE) clean -C Server
			$(MAKE) clean -C Client

fclean:
			$(MAKE) fclean -C Server
			$(MAKE) fclean -C Client

re:
			$(MAKE) re -C Server
			$(MAKE) re -C Client
