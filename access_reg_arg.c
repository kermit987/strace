/*
** access_reg_arg.c for strace in /home/le_l/Workspace/PSU_2015_strace
**
** Made by Victor Le
** Login   <le_l@epitech.net>
**
** Started on  Fri Apr  8 22:07:57 2016 Victor Le
** Last update Sun Apr 10 16:17:06 2016 Victor Le
*/

#include "main.h"

t_reg_size	access_reg_arg(const t_regs *regs, const int arg_nb)
{
  t_reg_size	*regs_ptr;
  static int	offsets[] = {REG_IDX(rax), REG_IDX(rdi), REG_IDX(rsi),
			     REG_IDX(rdx), REG_IDX(rcx), REG_IDX(r8),
			     REG_IDX(r9)};

  if (arg_nb < 0 || arg_nb > 6)
    return (0);
  regs_ptr = (t_reg_size *)regs;
  return (regs_ptr[offsets[arg_nb]]);
}

t_reg_size	get_rip(const t_regs *regs)
{
  t_reg_size	*regs_ptr;

  regs_ptr = (t_reg_size *)regs;
  return (regs_ptr[REG_IDX(rip)]);
}
