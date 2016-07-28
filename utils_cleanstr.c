/*
** utils_cleanstr.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:24:44 2008 christophe sundas
** Last update Mon Nov  3 22:24:45 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>

int	is_op_neg(char *operators, char *expr_in_tab)
{
  int	cpt;

  cpt = 0;
  while (*expr_in_tab != 0)
    {
      if (*expr_in_tab == operators[OP_NEG_IDX])
        cpt = cpt + 1;
      expr_in_tab = expr_in_tab + 1;
    }
  if ((cpt % 2) == 0)
    return (0);
  return (1);
}

int	need_to_clean(char *base, char *operators, char *expr_in_tab)
{
  if (my_strlen(expr_in_tab) <= 1)
    return (0);
  if (is_nb_pure(base, operators, expr_in_tab) == 1)
    return (0);
  return (1);
}

int	is_nb_pure(char *base, char *operators, char *expr_in_tab)
{
  while (*expr_in_tab != '\0')
    {
      if (is_char_op(base, operators, *expr_in_tab ) != OP_NUM)
        return (0);
      expr_in_tab = expr_in_tab + 1;
    }
  return (1);
}

/*
** retourne une chaine clean
*/
char	*clean_it(char *base, char *operators, char *expr_in_tab)
{
  char	*newstr;
  int	i;

  i = 0;
  if ((newstr = malloc(sizeof(*newstr) * (my_strlen(expr_in_tab) + 1))) == 0)
    exit(-1);
  if (search_number(base, expr_in_tab) == 1)
    return (clean_it_with_numbers(base, operators, expr_in_tab));
  else
    {
      if (is_op_neg(operators, expr_in_tab) == 1)
        newstr[i] = operators[OP_NEG_IDX];
      else
        newstr[i] = operators[OP_PLUS_IDX];
      i = i + 1;
      newstr[i] = '\0';
      return (newstr);
    }
}

char	*clean_it_with_numbers(char *base, char *operators, char *expr_in_tab)
{
  char	*newstr;
  int	i;
  
  if ((newstr = malloc(sizeof(*newstr) * (my_strlen(expr_in_tab) + 1))) == 0)
    return (NULL);
  i = 0;
  if (is_op_neg(operators, expr_in_tab) == 1)
    {
      newstr[i] = operators[OP_NEG_IDX];
      i = i + 1;
    }
  while (*expr_in_tab != '\0')
    {
      if (is_in_base(base, *expr_in_tab))
	{
	  newstr[i] = *expr_in_tab;
	  i = i + 1;
	}
      expr_in_tab = expr_in_tab + 1;
    }
  newstr[i] = '\0';
  return (newstr);
}
