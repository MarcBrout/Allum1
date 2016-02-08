/*
** alum.c for Alum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:58:45 2016 marc brout
** Last update Mon Feb  8 19:38:31 2016 marc brout
*/

#include <stdio.h>
#include "allum.h"
#include "get_next_line.h"

int		verif_line(char *str, int *allum, int h)
{
  int		test;

  if ((test = my_getnbr(str)) <= 0 || test > h)
    {
      write(1, "Error: this line is out of range\n", 34);
      return (0);
    }
  if (allum[test] <= 0)
    {
      write(1, "Error: this line is empty\n", 27);
      return (0);
    }
  return (test);
}

int		verif_nballum(char *str, int *allum, int line)
{
  int		test;

  if ((test = my_getnbr(str)) > allum[line])
    {
      write(1, "Error: not enough match(es) on this line\n", 43);
      return (0);
    }
  if (test <= 0)
    {
      write(1, "Error: you have to remove at least one match\n", 46);
      return (0);
    }
  return (test);
}

void		launch_game(char **tab, int *allum, int h)
{
  char		*answer;
  int		line;
  int		nb;

  write(1, "\nYour turn:\n", 13);
  write(1, "Line: ", 6);
  while ((answer = get_next_line(0)))
    {
      if ((line = verif_line(answer, allum, h)))
	break;
      write(1, "Line: ", 6);
    }
  write(1, "Matches: ", 9);
  while ((answer = get_next_line(0)))
    {
      if ((nb = verif_nballum(answer, allum, line)))
	  break;
      write(1, "Matches: ", 9);
    }
  allum[line] -= nb;
  set_tab(tab, allum, h);
  show_tab(tab);
}

char		allum(int h)
{
  char		**tab;
  int		*allum;

  if (!(tab = init_tab(h)) ||
      !(allum = tab_allum(h)))
    return (1);
  set_tab(tab, allum, h);
  show_tab(tab);
  while (42)
    launch_game(tab, allum, h);
  free_tabs(tab, allum);
  return (0);
}

int		main(int ac, char **av)
{
  int		nb;

  if (ac < 2)
    {
      if (allum(3))
	return (1);
    }
  else
    {
      if ((nb = my_getnbr(av[1])) < 1 ||
	  allum(nb))
	return (1);
    }
  return (0);
}
