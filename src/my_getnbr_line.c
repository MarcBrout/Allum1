/*
** my_getnbr_line.c for allum1
** 
** Made by marc brout
** Login   <brout_m@epitech.net>
** 
** Started on  Thu Feb 18 14:13:43 2016 marc brout
** Last update Thu Feb 18 14:29:23 2016 marc brout
*/

#include <stdio.h>

int		my_getnbr_line(char *str)
{
  int		total;
  int		isneg;
  int		i;

  i = 0;
  isneg = 1;
  if (!(str) || str == NULL)
    return (-1);
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	isneg = -isneg;
      i = i + 1;
    }
  total = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      if (((total * 10) + (str[i] - 48)) > 10000)
	return (-1);
      total = ((total * 10) + (str[i] - 48));
      i = i + 1;
    }
  if (str[i] != 0 || (total * isneg) < 0)
    return (-1);
  return (total * isneg);
}
