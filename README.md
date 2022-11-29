Simple Shell Project
====================

This project seeks to create a simple shell that mimics the functions of ths Bourne shell. It peforms basic operations such as the change directory and other builtin commands with minimal arguments. The shell does not perform advanced functions such as pipes.

## SHELL (shell.c)

This file contains the main function that starts up the shell.
The shell can be invoked iteratively or non-iteratively.
There are two separate function that run in each mode.

## GETLINE (getline_args.c)

This file contains funtions that read information from standard input and extracts command tokens from the line read.
The functions include;
- readline - retrieves the line string with delimiter
- getline_args - breaks a string into sub args with delimiter
- free_args - frees memory in a double pointer

## EXIT ERROR (exit_error.c)

This file contains functions that perform exit cleanup before program exits.
- exit_call - closes a program
- error_print - prints string to standard error
- free_env - frees memory of current and old directory
- exit_feof - check for end of file and exit program

## SHELL ROUTINE (shell_routine.c)

This file contains the shell loop function that runs infinitely acceptings commands from the standard input and breaks upon receiving EOF or entering exit command.
The functions include;
- cpy_path - copies the argument passed
- run_cd - checks if command is cd and executes it
- shell_routine - runs a loop that calls shell functions

## PATH SEEK(path_seek.c)

To be continued..

-----

