# Exam 3 Take-Home Portion, COSC 208, Spring 2023

For the take-home portion of Exam 3, you must complete the following tasks:

* [Sleeping children](#sleeping_children) (in `sleeping.c`)
* [string_divide](#string_divide) (in `strdivide.c`)
* [ring_remove](#ring_remove) (in `ring.c`)

As you work on the take-home portion, you may consult your notes, class notes (linked on Moodle), the textbook, or the man pages. You may also write/compile/execute code on your Raspberry Pi. However, you may not communicate with other people (classmates, other Colgate students, people on StackOverflow, etc.) about the take-home portion. 

Note that there is a `Makefile` in the repo so you can use the command `make` to compile your code.

You must commit and push your final code to GitHub **by the start of the final exam period on Tuesday, May 9**.

## Sleeping children
You should add code to `sleeping.c` to satisfy the following requirements:
* Parent process:
    * Creates two child processes
    * Prints `Parent: my 1st child is PID1` replacing `PID1` with the process ID of the first child
    * Prints `Parent: my 2nd child is PID2` replacing `PID2` with the process ID of the second child
    * Prints `Parent: my NTH child woke up first` replacing `NTH` with `1st` or `2nd`, depending on which child process finished first
    * Prints `Parent: both children woke up` after both child processes have finished
* Each child process:
    * Prints `NTH child: sleep TIME` replacing `NTH` with `1st` or `2nd`, depending on whether it is the 1st or 2nd child, and replacing `TIME` with the last digit of the child's PID
    * Executes the `/bin/sleep` program with the last digit of the child's PID as the duration in seconds

Sample output:
```
Parent: my 1st child is 20341
Parent: my 2nd child is 20342
1st child: sleep 1
2nd child: sleep 2
Parent: my 1st child woke up first
Parent: both children woke up
```

Another sample output:
```
Parent: my 1st child is 20539
1st child: sleep 9
Parent: my 2nd child is 20538
2nd child: sleep 8
Parent: my 2nd child woke up first
Parent: both children woke up
```

Yet another sample output:
```
Parent: my 1st child is 20626
1st child: sleep 6
Parent: my 2nd child is 20627
2nd child: sleep 7
Parent: my 1st child woke up first
Parent: both children woke up
```

## string_divide

Write a function `string_divide` that accepts a C string `s` and an integer 
`k`.  The function should divide the string in two parts such that the first
part is of length `k` and the second part is of length(`strlen(s) - k`).

The function should return an array of `char *` of length 2 where the 
first element points to the first part of the divided string and the second
element points to the second part.  Both parts of the divided string
must be allocated on the heap.

For example, `string_divide("apple", 3)` should return a structure
like the following:

```
     +---+---+
-->  | x | x |
     +-|-+-|-+
       |   |   +---+---+---+
       |   +-->| l | e | \0|
       |       +---+---+---+
       |    +---+---+---+---+
       +--->| a | p | p | \0|
            +---+---+---+---+
```

Note:
* If `k` is less than 0 or greater than the length of the string, the function should return `NULL`
* If the given `k` results in one part of the divided string being empty (length 0) you must still return the array of length 2 as described above.  The empty string should still be constructed as a valid C string, allocated on the heap.
* You **cannot** modify the string `s` given as a parameter to `string_divide`.


## ring_remove

Unlike a list of nodes which has a definitive head and tail, a ring of nodes has no distinct head or tail. Instead, the "last" node in the ring points to the "first" node in the ring. (Although without a head and a tail, there isn't really a first or last node.)

For example, the following memory diagram depicts a ring with three nodes.
```
     struct node              struct node              struct node
    ┌--------------------┐   ┌--------------------┐   ┌---------------------┐
 ╭~>│ struct node *next~~~~~>│ struct node *next~~~~~>│ struct node *next~╮ │
 │  └ value=1            |   | value=2            |   | value=3           | |
 │  └--------------------┘   └--------------------┘   └-------------------│-┘
 ╰~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~╯
```

Your task is to write a `ring_remove` function (in `ring.c`) that takes a pointer to a `struct node` that is part of a ring (with at least one node) and removes the first node encountered with a given value, starting with the given node (start of the ring).  If no node exists with the given value the ring should be unchanged.

The function should return a pointer to the original starting node in the ring (the one given to `ring_remove`) if that node still exists.  If the start node was removed, the function should return a pointer to the next node in the ring.  If there was only one node in the ring and it is removed, the function should return `NULL`.

The `main` function of `ring.c` contains some simple testing code which you are welcome to modify.

