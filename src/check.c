/*
** check.c for alum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Mon Feb  8 22:01:59 2016 marc brout
** Last update Mon Feb 15 18:37:43 2016 marc brout
*/

#include <unistd.h>
#include "allum.h"

int		is_it_over(int player, int *tab, int h)
{
  int		nbtab;

  nbtab = check_tab(tab, h);
  if (!player)
    {
      if (nbtab == 1)
	return (1);
      if (nbtab == 0)
	return (0);
    }
  else
    {
      if (nbtab == 1)
	return (0);
      if (nbtab == 0)
	return (1);
    }
  return (-1);
}

void		print_end_turn(int player, int line, int nb)
{
  if (player)
    write(1, "Player removed ", 15);
  else
    write(1, "AI removed ", 11);
  my_put_nbr(nb);
  write(1, " match(es) from line ", 21);
  my_put_nbr(line);
  write(1, "\n", 1);
}

int		verif_line(char *str, int *allum, int h)
{
  int		test;

  if (!str || (test = my_getnbr(str)) <= 0)
    {
      if (!str)
	write(1, "\n", 1);
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (0);
    }
  if (test > h)
    {
      write(1, "Error: this line is out of range\n", 33);
      return (0);
    }
  if (allum[test] <= 0)
    {
      write(1, "Error: this line is empty\n", 26);
      return (0);
    }
  return (test);
}

int		verif_nballum(char *str, int *allum, int line)
{
  int		test;

  if (!str || (test = my_getnbr(str)) <= 0)
    {
      if (!str)
	write(1, "\n", 1);
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (0);
    }
  if (test > allum[line])
    {
      write(1, "Error: not enough match(es) on this line\n", 41);
      return (0);
    }
  if (test <= 0)
    {
      write(1, "Error: you have to remove at least one match\n", 45);
      return (0);
    }
  return (test);
}

int		check_tab(int *allum, int h)
{
  int		i;
  int		total;

  total = 0;
  i = -1;
  while (++i < h + 2)
    total += allum[i];
  return (total);
}
