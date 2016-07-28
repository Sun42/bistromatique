/*
** parenthesis_mode.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:17:24 2008 christophe sundas
** Last update Mon Nov  3 22:17:25 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char	*parenthesis_mode(char *base, char *operators, int *i, char **tabexpr)
{
  t_list	*op;
  t_list	*nb;
  
  op = 0;
  nb = 0;
  *i = (*i) + 1;
  while (is_close_parent(operators, tabexpr[*i]) == 0)
    {
      if (is_open_parent(operators, tabexpr[*i]) == 1)
	my_put_in_list(&nb, parenthesis_mode(base, operators, i, tabexpr));
      if (is_num(base, operators, tabexpr[*i]) == 1)
	my_put_in_list(&nb, tabexpr[*i]);
      if ((is_high_op(operators, tabexpr[*i]) == 1))
	resolv(base, operators, i, tabexpr, &op, &nb);
      if (is_low_op(operators, tabexpr[*i]) == 1)
	my_put_in_list(&op, tabexpr[*i]);
      *i = *i + 1;
    }
  return (depile_all_parenthesis(base, operators, op, nb));
}



char	*depile_all_parenthesis(char *base, char *operators, t_list *op, t_list *nb)
{
  char	*operator;
  char	*expr1;
  char	*expr2;
  
  if (my_list_size(op) > 0)
    my_rev_list(&op);
  if (my_list_size(op) > 0)
    my_rev_list(&nb);
  while (my_list_size(op) > 0)
    {
      if ((expr1 = malloc(sizeof(*expr1) * (my_strlen(nb->data) + 1))) == NULL)
	exit(-1);
      my_strcpy(expr1, nb->data);
      depile(&nb);
      operator = malloc(sizeof(*operator) * (my_strlen(op->data) + 1));
      my_strcpy(operator,op->data);
      depile(&op);
      if (my_list_size(nb) == 0)
	return (special_case_one_expr_only(base, operators, expr1, operator));
      expr2 = malloc(sizeof(*expr2) * (my_strlen(nb->data) + 1));
      my_strcpy(expr2, nb->data);
      depile(&nb);
      my_put_in_list(&nb, operations(base, operators, expr1, operator, expr2));
    }
  return (nb->data);
}
