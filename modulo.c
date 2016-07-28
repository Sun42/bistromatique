/*
** modulo.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:12:03 2008 christophe sundas
** Last update Mon Nov  3 22:12:15 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"

char	*modulo(char *base, char *operators, char *expr1, char *expr2)
{
  char	tmp[2];

  tmp[0] = base[1];
  tmp[1] = '\0';
  while (is_sup(base, expr1, expr2))
    {
      my_strcpy(expr1, soustraction(base, operators, expr1, expr2));
    }
  return (expr1);
}

