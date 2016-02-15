/*
** player.c for allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Feb 10 18:19:15 2016 marc brout
** Last update Mon Feb 15 18:37:02 2016 marc brout
*/

#include <unistd.h>
#include "get_next_line.h"
#include "allum.h"

void		ask_player(t_ia *ia, int *allum, int h)
{
  char		*answer;
  char		bool;

  write(1, "\nYour turn:\nLine: ", 18);
  bool = 1;
  while (bool)
    {
      while (((answer = get_next_line(0)) || answer == NULL) &&
	     !(ia->line = verif_line(answer, allum, h)))
	write(1, "Line: ", 6);
      write(1, "Matches: ", 9);
      if (((answer = get_next_line(0)) || answer == NULL) &&
	  !(ia->nb = verif_nballum(answer, allum, ia->line)))
	write(1, "Line: ", 6);
      else
	bool = 0;
    }
}

char		launch_game(char **tab, int *allum, int h)
{
  t_ia		ia;

  ask_player(&ia, allum, h);
  allum[ia.line] -= ia.nb;
  print_end_turn(1, ia.line, ia.nb);
  set_tab(tab, allum, h);
  show_tab(tab);
  if (show_loser(1, allum, h))
    return (2);
  return (0);
}
