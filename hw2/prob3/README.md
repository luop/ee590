# Usages and Test Results

$ cat stack.csv
1
2
3
$ ./stack stack.csv print_top
1
$ ./stack stack.csv swap_top
2
1
3
$ cat stack.csv
2
1
3
$ ./stack stack.csv pop
2
$ cat stack.csv
1
3
$ ./stack stack.csv swap_top
3
1
$ cat stack.csv
3
1
$ ./stack stack.csv pop
3
$ cat stack.csv
1
$ ./stack stack.csv swap_top
1
$ cat stack.csv
1
$ ./stack stack.csv pop
1
$ cat stack.csv
$ ./stack stack.csv pop
Internal error: assertion 's->size > 0' failed at stack.c, line 18
