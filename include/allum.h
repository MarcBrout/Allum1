/*
** allum.h for Allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:55:02 2016 marc brout
** Last update Thu Feb 18 12:27:07 2016 marc brout
*/

#ifndef ALLUM_H_
# define ALLUM_H_

/*
** TOOLS
*/

void my_put_nbr(int);
int my_getnbr(char *);

/*
** MAIN FUNCTIONS : allum.c
*/

char allum(int);
char show_loser(int, int *, int);
void copy_tab(int *, int *, int);

/*
** ARRAY FUNCTIONS : tabs.c
*/

int *tab_allum(int);
void free_tabs(int *, char **, int *);
void show_tab(char **);
char **init_tab(int);
void set_tab(char **, int *, int);

/*
** AI'S FUNCTIONS : ia.c
*/

typedef struct		s_ia
{
  int			line;
  int			nb;
  int			victories;
}			t_ia;

void attrib_victory(t_ia *, int, int, int);
char calc_path_to_victory(int *, t_ia *, int *, int);
char ia_turn(int *, char **, int *, int);
int last_line(int *, int);
int one_thousand_match(int *, int);

/*
** PLAYER FUNCTIONS : player.c
*/

char launch_game(char **, int *, int);
void ask_player(t_ia *, int *, int);
void freestr(char *);

/*
** CHECKING FUNCTIONS : check.c
*/

int is_it_over(int, int *, int);
void print_end_turn(int, int , int);
int verif_line(char *, int *, int);
int verif_nballum(char *, int *, int);
int check_tab(int *, int);

#endif /* !ALLUM_H_ */
