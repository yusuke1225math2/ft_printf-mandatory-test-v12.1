#!/bin/bash

rm -f tmp/*.out tmp/*.log
set -euo pipefail

echo "===== norminette ====="
norminette *.c *.h
echo "===== make ====="
make fclean && make && make && make re && make clean && make
echo "===== test ====="
mkdir -p tmp
cc tests/out_printf.c -o tmp/a.out
cc -Wall -Werror -Wextra tests/out_ft_printf.c -L. -lftprintf -o tmp/b.out
echo "===== write failure / same process / undefined ====="
cc -Wall -Wextra -Werror -g -fsanitize=address,undefined \
  tests/test_write_fail.c libftprintf.a -o tmp/c.out
tmp/c.out
echo "===== valgrind ft_printf output ====="
valgrind --error-exitcode=1 --leak-check=full tmp/b.out
echo "===== diff between printf and ft_printf ====="
tmp/a.out > tmp/a.log
tmp/b.out > tmp/b.log
diff -a tmp/a.log tmp/b.log
