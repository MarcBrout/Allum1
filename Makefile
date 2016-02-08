##
## Makefile for Allum1
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Mon Feb  8 16:54:00 2016 marc brout
## Last update Mon Feb  8 19:15:11 2016 marc brout
##

SRCP	= ./src/

SRC     = $(SRCP)allum.c \
	$(SRCP)my_getnbr.c \
	$(SRCP)get_next_line.c \
	$(SRCP)tabs.c

OBJS    = $(SRC:.c=.o)

NAME    = allum1

CC      = gcc -g

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
