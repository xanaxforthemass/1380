# File I/O Homework

## What does this do?
This project demonstrates basic file operations in C. It covers reading and writing to and from a file, and demonstrates binary read and writes using structs.

## Why should I care?
File I/O allows programs to be saved, to be exported, and to exist beyond a single run of the program.

## How do I use it?
All compiled files can be run from the terminal, and don't require further input.

For example:

`./basic_file_ops`

`./text_copy`

`./binary_records`

Note: text_copy requires `sample.txt` to exist.

## How do I build it?
I used GCC:

`gcc -Wall -Wextra -Wpedantic -std=c23 -g -o basic_file_ops basic_file_ops.c`

`gcc -Wall -Wextra -Wpedantic -std=c23 -g -o text_copy text_copy.c`

`gcc -Wall -Wextra -Wpedantic -std=c23 -g -o binary_records binary_records.c`