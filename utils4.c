/*
** utils4.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:23:20 2008 christophe sundas
** Last update Mon Nov  3 22:23:21 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"

int	is_mod_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_MOD_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}
int	is_plus_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_PLUS_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}

int	is_sub_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_SUB_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}

int	is_high_op(char *operators, char *expr_in_tab)
{
  if (is_mod_op(operators, expr_in_tab) == 1)
    {
      return (1);
    }
  if (is_mult_op(operators, expr_in_tab) == 1)
    {
      return (1);
    }
  if (is_div_op(operators, expr_in_tab) == 1)
    return (1);
  return (0);
}
