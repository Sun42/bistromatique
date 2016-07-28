/*
** utils3.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:22:11 2008 christophe sundas
** Last update Mon Nov  3 22:22:12 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

int	only_pm_until_par(char *base, char *expr, char *operators)
{
  int	value;

  value = is_char_op(base, operators, *expr);
  while (value != OP_OPEN_PARENT_IDX)
    {
      if ((value != OP_PLUS_IDX) && (value != OP_SUB_IDX))
        {
          return (0);
	}
      expr = expr + 1;
      value = is_char_op(base, operators, *expr);
    }
  return (1);
}

/*
**CHeck si un '-' ou un '+' est un operateur
*/
int	is_an_operator(char *base, char *expr, char *operators, int cpt_mot)
{
  int	prev_val;

  prev_val = is_char_op(base, operators, *(expr - 1));
  if (cpt_mot == 0)
    return (0);
  if ((prev_val == 0) || ((prev_val >= 2) && (prev_val <= 6)))
    return (0);
  if (only_pm_until_par(base, expr, operators) == 1)
    {
      return (0);
    }
  else
    return (1);
}

void		depile(t_list **begin)
{
  t_list	*tmp;

  tmp = *begin;
  *begin = (*begin)->next;
  free(tmp);
}

int	is_div_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_DIV_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}

int	is_mult_op(char *operators, char *expr_in_tab)
{
  if ((expr_in_tab[0] == operators[OP_MULT_IDX]) && (my_strlen(expr_in_tab) == 1))
    return (1);
  return (0);
}
