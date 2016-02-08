/*
** tabs.c for alum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 18:10:03 2016 marc brout
** Last update Mon Feb  8 19:14:42 2016 marc brout
*/

#include <unistd.h>
#include <stdlib.h>
#include "allum.h"

int		*tab_allum(int h)
{
  int		*tab;
  int		i;

  if (!(tab = malloc(sizeof(int) * (h + 3))))
    return (NULL);
  tab[0] = 0;
  tab[h + 2] = -1;
  i = 1;
  tab[1] = 1;
  while (++i < h + 1)
    tab[i] = i * 2 - 1;
  return (tab);
}

void		free_tabs(char **tab, int *tabint)
{
  int		i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  free(tabint);
}

void		show_tab(char **tab)
{
  int		i;
  int		j;

  j = -1;
  while (tab[++j])
    {
      i = -1;
      while (tab[j][++i])
	write(1, &tab[j][i], 1);
      write(1, "\n", 1);
    }
}

char		**init_tab(int h)
{
  char		**tab;
  int		l;
  int		j;

  l = (h == 1) ? 1 : (h * 2) - 1;
  if (!(tab = malloc(sizeof(char *) * (h + 3))))
    return (NULL);
  tab[h + 2] = NULL;
  j = -1;
  while (++j < (h + 2))
    {
      if (!(tab[j] = malloc(l + 3)))
	return (NULL);
      tab[j][l + 2] = 0;
    }
  return (tab);
}

void		set_tab(char **tab, int *allum, int h)
{
  int		l;
  int		i;
  int		j;
  int		rest;

  j = -1;
  l = (h == 1) ? 1 : (h * 2) - 1;
  while (++j < (h + 2))
    {
      rest = allum[j];
      i = -1;
      while (++i < (l + 2))
	{
	  if (!j || !i || j == (h + 1) || i == (l + 1))
	    tab[j][i] = '*';
	  else if (i >= (l / 2 + 1 - (j - 1)) &&
		   i <= (l / 2 + 1 + (j - 1)) && rest-- > 0)
	    tab[j][i] = '|';
	  else
	    tab[j][i] = ' ';
	}
    }
}
