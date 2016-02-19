/*
** allum.h for Allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:55:02 2016 marc brout
** Last update Fri Feb 19 01:51:02 2016 marc brout
*/

#ifndef ALLUM_H_
# define ALLUM_H_
# define USAGE "Usage: ./allum1 ...[OPTIONAL][0 < LINES <= 10000]\n"
# define MALLOC "Program interrupted: Error during allocating process.\n"
# define CTRL_D "\nProgram interrupted: NULL string input.\n"

/*
** TOOLS
*/

int my_strlen(char *);
void my_put_nbr(int);
int my_getnbr(char *);
int my_getnbr_line(char *);

/*
** *****
** ****
** *** MAIN FUNCTIONS : allum.c
** **
** *|  allum :      Main function which contains the main loop of the game.
** ||  show_loser : If the game has ended, it prints to the screen 
** ||               which player is the loser.
** ||  copy_tab :   Copys the content of the second int* array to the
** ||               first one. Each array must be alloced and initialized.
** |*
** *
*/

char allum(int);
char show_loser(int, int *, int);
void copy_tab(int *, int *, int);

/*
** *****
** ****
** *** ARRAY FUNCTIONS : tabs.c
** **
** *|  tab_allum : Returns an int array of n°int cells. 
** ||  free_tabs : Frees the allocated arrays passed to the function.
** ||  show_tab :  Prints the content of the tab on the screen.
** ||  init_tab :  Returns an array of char arrays.
** ||  set_tab :   Sets the char **array from the int *array.
** |*
** *
*/

int *tab_allum(int);
int free_tabs(int *, char **, int *);
void show_tab(char **);
char **init_tab(int);
void set_tab(char **, int *, int);

/*
** *****
** ****
** *** AI'S FUNCTIONS : ia.c
** **
** *|  attrib_victory :       Copies the winning move conbinaison 
** ||                         calculated by calc_path_to_victory into the
** ||                         structure t_ia.
** ||  calc_path_to_victory : Contains the main loop to calculate 
** ||                         the best move with one thousand tests.
** ||  last_line :            Returns the last line of the array containing 
** ||                         matches.
** ||  ia_turn :              Main function launching the whole IA turn.
** ||  one_thousand_match :   Monte Carlo recursive function.
** |*
** *
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

int my_put(char *);
int launch_game(char **, int *, int);
int ask_player(t_ia *, int *, int);
int freestr(char *);

/*
** CHECKING FUNCTIONS : check.c
*/

int is_it_over(int, int *, int);
void print_end_turn(int, int , int);
int verif_line(char *, int *, int);
int verif_nballum(char *, int *, int);
int check_tab(int *, int);

#endif /* !ALLUM_H_ */
