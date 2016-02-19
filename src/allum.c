/*
** alum.c for Alum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:58:45 2016 marc brout
** Last update Fri Feb 19 01:51:49 2016 marc brout
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

char		show_loser(int player, int *allum, int h)
{
  if (!check_tab(allum, h))
    {
      if (player)
	write(1, "You lost, too bad..\n", 20);
      else
	write(1, "I lost.. snif.. but I'll get you next time!!\n", 45);
      return (1);
    }
  return (0);
}

void		copy_tab(int *copy, int *allum, int h)
{
  int		i;

  copy[0] = 0;
  copy[h + 1] = 0;
  copy[h + 2] = -1;
  i = 0;
  while (++i < h + 1)
    copy[i] = allum[i];
}

char		allum(int h)
{
  char		**tab;
  int		*copy;
  int		*allum;
  int		errorpl;
  int		erroria;

  if (!(tab = init_tab(h)) || !(allum = tab_allum(h)) ||
      !(copy = malloc(sizeof(int) * (h + 3))))
    return (1);
  set_tab(tab, allum, h);
  show_tab(tab);
  while (check_tab(allum, h))
    if ((errorpl = launch_game(tab, allum, h)) ||
	(erroria = ia_turn(copy, tab, allum, h)))
      {
	if (errorpl && free_tabs(copy, tab, allum))
	  return (errorpl);
	if (erroria && free_tabs(copy, tab, allum))
	  return (erroria);
      }
  return (0);
}

int		my_printerror(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}

int		main(int ac, char **av)
{
  int		nb;

  srand(time(0));
  if (ac < 2)
    {
      if ((nb = allum(4)) == 2)
	return (my_printerror(MALLOC));
    }
  else
    {
      if ((nb = my_getnbr_line(av[1])) < 1)
	return (my_printerror(USAGE));
      if ((nb = allum(nb)) == 2)
	return (my_printerror(MALLOC));
    }
  if (nb == 3)
    return (my_printerror(CTRL_D));
  return (0);
}
