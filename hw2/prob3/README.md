# Usages and Test Results

-bash-4.2$ cat stack.csv_
def_
abc_
ghi_
-bash-4.2$ ./stack stack.csv pop_
def_
-bash-4.2$ cat stack.csv_
abc_
ghi_
-bash-4.2$ ./stack stack.csv print_top_
abc_
-bash-4.2$ ./stack stack.csv swap_top_
ghi_
abc_
-bash-4.2$ ./stack stack.csv pop_
ghi_
-bash-4.2$ ./stack stack.csv swap_top_
abc_
-bash-4.2$ cat stack.csv_
abc_

