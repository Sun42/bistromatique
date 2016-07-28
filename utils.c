/*
** utils.c for groupement dutilitaires pour bistro in /u/all/sundas_c/cu/rendu/piscine/bistro
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Thu Oct 30 16:20:12 2008 christophe sundas
** Last update Mon Nov  3 20:10:29 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

int	is_char_op(char *base, char *operators, char c)
{
  if (c == operators[OP_OPEN_PARENT_IDX])
    return (OP_OPEN_PARENT_IDX);
  if (c == operators[OP_CLOSE_PARENT_IDX])
    return (OP_CLOSE_PARENT_IDX);
  if (c == operators[OP_PLUS_IDX])
    return (OP_PLUS_IDX);
  if (c == operators[OP_SUB_IDX])
    return (OP_SUB_IDX);
  if (c == operators[OP_MULT_IDX])
    return (OP_MULT_IDX);
  if (c == operators[OP_DIV_IDX])
    return (OP_DIV_IDX);
  if (c == operators[OP_MOD_IDX])
    return (OP_MOD_IDX);
  if (is_in_base(base, c))
    return (OP_NUM);
 return (OP_ELSE);
}

int	is_in_base(char *base, char c)
{
  while (*base != '\0')
    {
      if (c == *base)
	return (1);
      base = base + 1;
    }
  return (0);
}

int	indice_in_base(char *base, char c)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
	return (i);
      i = i + 1;
    }
}

int	num_len(char *base, char *expr)
{
  int	i;

  i = 0;
  while (is_in_base(base, *expr) == 1)
    {
      i = i + 1;
      expr = expr + 1;
    }
  return (i);
}

/*
** Retourne la longueur dun nombre avec ses plus et moins compris dans une chaine
*/
int	num_with_op_len(char *base, char *expr, char *operators)
{
  int	i;

  i = 0;
  while ((is_char_op(base, operators, *expr) == 2) || (is_char_op(base, operators, *expr) == 3))
    {
      i = i + 1;
      expr = expr + 1;
    }
  i = i + num_len(base, expr);
  return (i);
}
