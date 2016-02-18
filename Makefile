##
## Makefile for Allum1
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Mon Feb  8 16:54:00 2016 marc brout
## Last update Thu Feb 18 14:07:49 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)allum.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)my_put_nbr.c \
	$(SRCP)get_next_line.c \
	$(SRCP)check.c \
	$(SRCP)ia.c \
	$(SRCP)player.c \
	$(SRCP)tabs.c

OBJS    = $(SRC:.c=.o)

NAME    = allum1

CC      = gcc

CFLAGS  =  -W -Wall -Werror

HDFLAGS = -I./include/

LDFLAGS = 

RM      = rm -f

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
