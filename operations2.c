/*
** operations2.c for  in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:16:08 2008 christophe sundas
** Last update Mon Nov  3 22:16:10 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*parse_modulo(char *base, char *operators, char *expr1, char *expr2)
{
  int	*flags;

  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  flags = parse_operation(base, operators, &expr1, &expr2);
  if (flags[0] == 1)
    {
      return (ajoute_moins(base, operators, modulo(base, operators, expr1, expr2)));
    }
  return (modulo(base, operators, expr1, expr2));
}

char	*parse_division(char *base, char *operators, char *expr1, char *expr2)
{
  int	*flags;
  
  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  flags = parse_operation(base, operators, &expr1, &expr2);
  if ((flags[0] == 0) && (flags[1] == 0))
    return (division(base, operators, expr1, expr2));
  if ((flags[0] == 1) && (flags[1] == 1))
    return (division(base, operators, expr1, expr2));
  if ((flags[0] == 0) && (flags[1] == 1))
    return (ajoute_moins(base, operators, division(base, operators, expr1, expr2)));
  if ((flags[0] == 1) && (flags[1] == 0))
    return (ajoute_moins(base, operators, division(base, operators, expr1, expr2)));
}


char	*parse_multiplication(char *base, char *operators, char *expr1, char *expr2)
{
  int	*flags;
  
  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  flags = parse_operation(base, operators, &expr1, &expr2);
  if ((flags[0] == 0) && (flags[1] == 0))
    return (do_inf_mult(base, expr1, expr2));
  if ((flags[0] == 1) && (flags[1] == 1))
    return (do_inf_mult(base, expr1, expr2));
  return (ajoute_moins(base, operators, do_inf_mult(base, expr1, expr2)));
}

char	*parse_soustraction(char *base, char *operators, char *expr1, char *expr2)
{
  int	*flags;

  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  flags = parse_operation(base, operators, &expr1, &expr2);
  if ((flags[0] == 0) && (flags[1] == 0))
    return (soustraction(base, operators, expr1, expr2));
  if ((flags[0] == 1) && (flags[1] == 1))
    return (soustraction(base, operators, expr2, expr1));
  if ((flags[0] == 1) && (flags[1] == 0))
    return (ajoute_moins(base, operators, addition(base, expr1, expr2)));
  if ((flags[0] == 0) && (flags[1] == 1))
    return (addition(base, expr1, expr2));
}

char	*parse_addition(char *base, char *operators, char *expr1, char *expr2)
{
  int	*flags;
  
  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  flags = parse_operation(base, operators, &expr1, &expr2);
  if ((flags[0] == 0) && (flags[1] == 0))
    return (addition(base, expr1, expr2));
  if ((flags[0] == 1) && (flags[1] == 1))
    return (ajoute_moins(base, operators, addition(base, expr1, expr2)));
  if (flags[2] == 0)
    {
      if (flags[0] == 1)
	return (soustraction(base, operators, expr2, expr1));
      return (soustraction(base, operators, expr1, expr2));
    }
  if (flags[2] == 1)
    {
      if (flags[0] == 1)
	return (soustraction(base, operators, expr2, expr1));
      return (soustraction(base, operators, expr1, expr2));
    }
}
