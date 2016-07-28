/*
** operations.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:14:36 2008 christophe sundas
** Last update Mon Nov  3 22:14:38 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*operations(char *base, char *operators, char *expr1, char *op, char *expr2)
{
  if (op[0] == operators[OP_PLUS_IDX])
    return (parse_addition(base, operators, expr1, expr2));
  if (op[0] == operators[OP_SUB_IDX])
    return (parse_soustraction(base, operators, expr1, expr2));
  if (op[0] == operators[OP_MULT_IDX])
    return (parse_multiplication(base, operators, expr1, expr2));
  if (op[0] == operators[OP_DIV_IDX])
    {
      if (expr2[0] == base[0] && my_strlen(expr2) == 1)
        exit(-1);
      return (parse_division(base, operators, expr1, expr2));
    }
  if (op[0] == operators[OP_MOD_IDX])
    {
      if (expr2[0] == base[0] && my_strlen(expr2) == 1)
        exit(-1);
      return (parse_modulo(base, operators, expr1, expr2));
    }
}

char	*ajoute_moins(char *base, char *operators, char *expr)
{
  char	*new_expr;
  int	len;

  len = my_strlen(expr);
  if ((len == 1) && (expr[0] == base[0]))
    return (expr);
  if ((new_expr = malloc(sizeof(*new_expr) * len + 2)) == NULL)
    exit(-1);
  my_revstr(expr);
  my_strcpy(new_expr, expr);
  new_expr[len] = operators[OP_NEG_IDX];
  new_expr[len + 1] = '\0';
  my_revstr(new_expr);
  return (new_expr);
}

int	parse_zeros(char *base, char *expr)
{
  int	i;

  i = 0;
  while ((expr[i] == base[0]) && (expr[i + 1] != '\0'))
    {
      i = i + 1;
    }
  return (i);
}

int	is_sup(char *base, char *expr1, char *expr2)
{
  int	nb1;
  int	nb2;
  int	i;

  i = 0;
  nb1 = my_strlen(expr1);
  nb2 = my_strlen(expr2);
  if (nb1 > nb2)
    return (1);
  if (nb1 < nb2)
    return (0);
  if (nb1 == nb2)
    {
      while (i < nb1)
        {
          if (indice_in_base(base, expr1[i]) > indice_in_base(base, expr2[i]))
            return (1);
          if (indice_in_base(base, expr1[i]) < indice_in_base(base, expr2[i]))
            return (0);
          i = i + 1;
        }
    }
  return (1);
}

int	*parse_operation(char *base, char *operators, char **expr1, char **expr2)
{
  int	*flags;

  if ((flags = malloc(sizeof(*flags) * 3)) == 0)
    exit(-1);
  if (*expr1[0] == operators[OP_NEG_IDX])
    {
      flags[0] = 1;
      *expr1 = *expr1 + 1 ;
    }
  else
    flags[0] = 0;
  if (*expr2[0] == operators[OP_NEG_IDX])
    {
      flags[1] = 1;
      *expr2 = *expr2 + 1;
    }
  else
    flags[1] = 0;
  *expr1 = *expr1 + parse_zeros(base, *expr1);
  *expr2 = *expr2 + parse_zeros(base, *expr2);
  if (is_sup(base, *expr1, *expr2) == 0)
    flags[2] = 1;
  else
    flags[2] = 0;
  return (flags);
}
