/*
** main.c for mult in /u/all/sundas_c/cu/rendu/piscine/bistro/operations/multiplication
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Sat Nov  1 04:38:23 2008 christophe sundas
** Last update Mon Nov  3 22:14:11 2008 christophe sundas
*/

#include <stdlib.h>
#include "my.h"
#include "bistromathique.h"

int	digit_to_val(char *base, char d)
{
  int	r;
  
  r = 0;
  while (base[r] != d)
    {
      r = r + 1;
    }
  return (r);
}

int	*mk_r(int size)
{
  int	*r;
  int	i;
  
  i = 0;
 r = malloc(size * sizeof(*r));
  while (i < size)
    {
      r[i] = 0;
      i = i + 1;
    }
  return (r);
}

char	*mk_res(int size)
{
  char	*res;

  res = malloc(size + 1);
  res[size] = 0;
  return (res);
}

char	*do_inf_mult(char *base, char *expr1, char *expr2)
{
  int	len1;
  int	len2;
  int	*r;
  int	i;
  int	j;
  
  len1 = my_strlen(expr1);
  len2 = my_strlen(expr2);
  r = mk_r(len1 + len2);
  i = len1 - 1;
  while (i >= 0)
    {
      j = len2 - 1;
      while (j >= 0)
        {
          r[i + j + 1] = r[i + j + 1] + (DIGIT_TO_VAL(expr1[i]) * DIGIT_TO_VAL(expr2[j]));
          r[i + j] = r[i + j] + (r[ i + j + 1] / BASE_LEN(base));
          r[i + j + 1] = r[i + j + 1] % BASE_LEN(base);
	  j = j - 1;
        }
      i = i - 1;
    }
  return (do_inf_mult2(base, expr1, expr2, r));
}

char	*do_inf_mult2(char *base, char *expr1, char *expr2, int *r)
{
  int	i;
  int	j;
  char	*res;
  int	len1;
  int	len2;
 
  i = 0;
  j = 0;
  len1 = my_strlen(expr1);
  len2 = my_strlen(expr2);
  res = mk_res(len1 + len2);
  while (i < len1 + len2)
    {
      if (j || r[i] || i == len1 + len2 - 1)
	{
	  res[j++] = VAL_TO_DIGIT(r[i]);
	}
      i = i + 1;
    }
  return (res);
}
