/*
** soustraction.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:18:36 2008 christophe sundas
** Last update Mon Nov  3 22:19:43 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*soustraction(char *base, char *operators, char *expr1, char *expr2)
{
  if (is_sup(base, expr1, expr2))
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr1, expr2, 0));
    }
  else
    {
      my_revstr(expr1);
      my_revstr(expr2);
      return (sub(base, operators, expr2, expr1, 1));
    }
} 

char	*sub(char *base, char *operators, char *exprmax, char *exprmin, int flagmin)
{
  int	i;
  char	*stringfinale;
  int	res;
  int	retenu;

  i = 0;
  retenu = 0;
  if ((stringfinale = malloc(sizeof(*stringfinale) * (my_strlen(exprmax) + 2))) == 0)
    exit(-1);
  while (exprmax[i] != '\0')
    {
      stringfinale[i] = calcul_res(base, indice_in_base(base, exprmax[i]), if_exist_exprmin(base, i, exprmin), &retenu);
      i = i + 1;
    }
  check_ending_zero(base, retenu, &i, stringfinale);
  check_flagmin(operators, stringfinale, &i, flagmin);
  stringfinale[i] = '\0';
  my_revstr(stringfinale);
  return (stringfinale);
}

void	check_flagmin(char *operators, char *stringfinale, int *i, int flagmin)
{
  if (flagmin == 1)
    {
      stringfinale[*i] = operators[OP_NEG_IDX];
      *i = *i + 1;
    }
}

int	if_exist_exprmin(char *base, int i, char *exprmin)
{
  if (i >= my_strlen(exprmin))
    return (0);
  else
    return (indice_in_base(base, exprmin[i]));
}

char	calcul_res(char *base, int nb1, int nb2, int *retenu)
{
  int	res;
  
  res = nb1 - (nb2 + *retenu);
  if (res < 0)
    {
      res = -res;
      res = my_strlen(base) - res;
      *retenu = 1;
    }
  else
    {
      *retenu = 0;
    }
  return (base[res]);
}
