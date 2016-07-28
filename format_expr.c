/*
** format_expr.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:06:27 2008 christophe sundas
** Last update Mon Nov  3 22:08:12 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

char		**str_to_tab_string(char *base, char *expr, char *operators)
{
  char		**tabexpr;
  int		cpt;
  int		nb;

  if ((tabexpr = malloc(sizeof(*tabexpr) * (nb_case(base, expr, operators) + 1) )) == 0)
    exit(-1);
  cpt = 0;
  while (*expr != '\0')
    {
      nb = nb_char_to_add(base, expr, operators, cpt);
      if ((tabexpr[cpt] = malloc (sizeof(**tabexpr) * (nb + 1))) == 0)
	exit(-1);
      my_strlcat(tabexpr[cpt], expr, nb + 1);
      if (need_to_clean(base,operators, tabexpr[cpt]) == 1)
	my_strcpy(tabexpr[cpt], clean_it(base, operators, tabexpr[cpt]));
      cpt = cpt + 1;
      expr = expr + nb ;
    }
  tabexpr[cpt] = NULL;
  return (tabexpr);
}

/*
** Renvoi un si ca match qqchose dans la base
*/
int	search_number(char *base, char *expr_in_tab)
{
  while (*expr_in_tab != '\0')
    {
      if (is_in_base(base, *expr_in_tab) == 1)
	{
	  return (1);
	}
      expr_in_tab = expr_in_tab + 1;
    }
  return (0);
}

int	nb_char_to_add(char *base, char *expr, char *operators, int cpt)
{
  int	char_val;

  char_val = is_char_op(base, operators, *expr);
  if (char_val == 7)
    {
      return (num_len(base, expr));
    }
  if ((char_val == 2) || (char_val == 3))
    {
      if (is_an_operator(base, expr, operators, cpt) == 0)
	return (num_with_op_len(base, expr, operators));
    }
  return (1);
}

/* 
**retourne le nombre de case a allouer en vue dun malloc
*/
int		nb_case(char *base, char *expr, char *operators)
{
  int		cpt;
  int		char_val;
    
  cpt = 0;
  while (*expr != '\0')
    {
      char_val = is_char_op(base, operators, *expr);
      if (char_val == 7)
	expr = expr + num_len(base, expr) - 1;
      if ((char_val == 2) || (char_val == 3))
	{
	  if (is_an_operator(base, expr, operators, cpt) == 0)
	    expr = expr + (num_with_op_len(base, expr, operators) - 1);
	}
      cpt = cpt + 1;
      expr = expr + 1;
    }
  return (cpt);
}
