/*
** ia.c for alum1 in /home/brout_m/rendu/projet/Prog_elem/CPE_2015_Allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Wed Feb 10 16:15:38 2016 marc brout
** Last update Fri Feb 19 01:20:48 2016 marc brout
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "allum.h"

int		one_thousand_match(int *tab, int h)
{
  int		line;
  int		nb;
  int		test;

  if (check_tab(tab, h) >= 500)
    return (-1);
  if ((test = is_it_over(0, tab, h)) >= 100)
    return (test);
  while ((line = (rand() % h + 1)) && !(tab[line]));
  nb = rand() % tab[line] + 1;
  tab[line] -= nb;
  if ((test = is_it_over(1, tab, h)) >= 0)
    return (test);
  while ((line = (rand() % h + 1)) && !(tab[line]));
  nb = rand() % tab[line] + 1;
  tab[line] -= nb;
  if ((test = is_it_over(0, tab, h)) >= 0)
    return (test);
  return (one_thousand_match(tab, h));
}

void		attrib_victory(t_ia *ia, int ret, int line, int nb)
{
  if (ret > ia->victories)
    {
      ia->victories = ret;
      ia->line = line;
      ia->nb = nb;
    }
}

char		calc_path_to_victory(int *copy, t_ia *ia, int *allum, int h)
{
  int		ret;
  int		total;
  int		line;
  int		nb;
  int		matches;

  line = h + 2;
  ia->victories = 0;
  while (--line > 0)
    {
      nb = allum[line];
      while (--nb > 0 && (matches = 1000) && !(total = 0))
	{
	  while (--matches >= 0)
	    {
	      copy_tab(copy, allum, h);
	      copy[line] -= nb;
	      if ((ret = one_thousand_match(copy, h)) < 0)
		break;
	      total += ret;
	    }
	  attrib_victory(ia, total, line, nb);
	}
    }
  return (0);
}

int		last_line(int *tab, int h)
{
  int		i;

  i = h + 2;
  while (--i > 0)
    if (tab[i] > 0)
      break;
  return (i);
}

char		ia_turn(int * copy, char **tab, int *allum, int h)
{
  t_ia		ia;

  ia.line = last_line(allum, h);
  ia.nb = allum[ia.line];
  ia.victories = 0;
  write(1, "\nAI's turn...\n", 14);
  if (calc_path_to_victory(copy, &ia, allum, h))
    return (1);
  allum[ia.line] -= ia.nb;
  print_end_turn(0, ia.line, ia.nb);
  set_tab(tab, allum, h);
  show_tab(tab);
  if (show_loser(0, allum, h))
    return (4);
  return (0);
}
