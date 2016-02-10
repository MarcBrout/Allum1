/*
** alum.c for Alum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 16:58:45 2016 marc brout
** Last update Wed Feb 10 18:29:37 2016 marc brout
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

int		*copy_tab(int *allum, int h)
{
  int		i;
  int		*copy;

  if (!(copy = malloc(sizeof(int) * (h + 3))))
    return (NULL);
  copy[0] = 0;
  copy[h + 1] = 0;
  copy[h + 2] = -1;
  i = 0;
  while (++i < h + 1)
    copy[i] = allum[i];
  return (copy);
}

char		allum(int h)
{
  char		**tab;
  int		*allum;
  int		error;

  if (!(tab = init_tab(h)) || !(allum = tab_allum(h)))
    return (1);
  set_tab(tab, allum, h);
  show_tab(tab);
  while (check_tab(allum, h))
    if ((error = launch_game(tab, allum, h)) ||
	(error = ia_turn(tab, allum, h)))
      return ((error == 1) ? 1 : 0);
  free_tabs(tab, allum);
  return (0);
}

int		main(int ac, char **av)
{
  int		nb;

  srand(time(0));
  if (ac < 2)
    {
      if (allum(4))
	return (1);
    }
  else
    {
      if ((nb = my_getnbr(av[1])) < 1 || allum(nb))
	return (1);
    }
  return (0);
}
