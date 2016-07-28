/*
** main.c for bistro in /u/all/sundas_c/cu/rendu/piscine/bistro/version0911
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Nov  3 22:10:36 2008 christophe sundas
** Last update Mon Nov  3 22:10:38 2008 christophe sundas
*/

#include "my.h"
#include "bistromathique.h"
#include <stdlib.h>
#include <string.h>

int		main(int ac,char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
    {
      my_putstr("Usage : ");
      my_putstr(av[0]);
      my_putstr(" base ops\"()+-*/%\" exp_len\n");
      exit(1);
    }
  check_base(av[1]);
  check_ops(av[2]);
  expr = get_expr(size = atoi(av[3]));
  my_putstr(eval_expr(av[1], av[2], expr, size));
}

static void	check_base(char *b)
{
  if (strlen(b) < 2)
    {
      my_putstr("Bad base\n");
      exit(1);
    }
}

static char	*get_expr(unsigned int size)
{
  char		*expr;
  
  if (size <= 0)
    {
      my_putstr("Bad expr len\n");
      exit(1);
    }
  if ((expr = malloc(size+1))==0)
    {
      my_putstr("could not alloc\n");
      exit(1);
    }
  if (read(0,expr,size)!=size)
    {
      my_putstr("could not read\n");
      exit(1);
    }
  expr[size] = 0;
  return (expr);
}

static void	check_ops(char *ops)
{
  if (strlen(ops) != 7)
    {
      my_putstr("Bad ops\n");
      exit(1);
    }
}
