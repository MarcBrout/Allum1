/*
** allum.h for Allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:55:02 2016 marc brout
** Last update Mon Feb  8 18:47:19 2016 marc brout
*/

#ifndef ALLUM_H_
# define ALLUM_H_

void free_tabs(char **, int *);
void show_tab(char **);
void set_tab(char **, int *, int);
char **init_tab(int);
char allum(int);
int *tab_allum(int);
int my_getnbr(char *);

#endif /* !ALLUM_H_ */
