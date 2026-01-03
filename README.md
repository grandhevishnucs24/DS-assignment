# DS-assignment

This repository contains C programs for data structures lab exercises organized by week.

Files by week

Week 1
- Week1/infix_to_postfix.c — Stack-based infix-to-postfix converter (handles + - * / ^ and parentheses; ^ is right-associative)

Week 2
- Week2/queue_implementation.c — Linear queue (enqueue/dequeue)
- Week2/circular_queue.c — Circular queue (modular wraparound)

Week 3
- Week3/linked_list.c — Singly linked list (insert at position, delete at position, search)

Week 4
- Week4/linked_list_advanced.c — Value-based delete, bubble sort, reverse, concatenation

Week 6
- Week6/doubly_linked_list.c — Doubly linked list with forward and backward traversal

Week 7
- Week7/binary_tree.c — Binary search tree (insert, delete, traversals)
- Week7/bfs.c — Breadth-first search using adjacency matrix
- Week7/dfs.c — Depth-first search using adjacency matrix + recursion
- Week7/hash_map.c — Separate chaining hash table (insert, search, delete)

Building

A Makefile is included. To compile all programs and place binaries under the `bin/` directory, run:

    make

To build a single program (for example, the infix->postfix converter):

    gcc Week1/infix_to_postfix.c -o bin/Week1/infix_to_postfix

Running

Binaries are placed under `bin/` with the same relative path as source files. Example:

    ./bin/Week1/infix_to_postfix

Each program is interactive and will prompt for input; the README for each file in-line shows simple compile/run examples.

Cleaning

    make clean

License

This repository is licensed under the MIT License (see LICENSE).
