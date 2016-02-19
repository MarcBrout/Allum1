/*
** player.c for allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Feb 10 18:19:15 2016 marc brout
** Last update Fri Feb 19 01:47:42 2016 marc brout
*/

#include <unistd.h>
#include "get_next_line.h"
#include "allum.h"

int		my_put(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
  return (1);
}

int		freestr(char *str)
{
  if (str != NULL)
    free(str);
  return (1);
}

int		ask_player(t_ia *ia, int *allum, int h)
{
  char		*answer;
  char		bool;

  my_put("\nYour turn:\nLine: ");
  bool = 1;
  while (bool)
    {
      while (((answer = get_next_line(0)) || answer == NULL) &&
	     !(ia->line = verif_line(answer, allum, h)) && my_put("Line: ")
	     && freestr(answer));
      if (ia->line < 0)
	return (1);
      freestr(answer);
      my_put("Matches: ");
      if (((answer = get_next_line(0)) || answer == NULL) &&
	  !(ia->nb = verif_nballum(answer, allum, ia->line)))
	my_put("Line: ");
      else if (ia->nb < 0)
	return (1);
      else
	bool = 0;
      freestr(answer);
    }
  return (0);
}

int		launch_game(char **tab, int *allum, int h)
{
  t_ia		ia;

  if (ask_player(&ia, allum, h))
    return (3);
  allum[ia.line] -= ia.nb;
  print_end_turn(1, ia.line, ia.nb);
  set_tab(tab, allum, h);
  show_tab(tab);
  if (show_loser(1, allum, h))
    return (2);
  return (0);
}
