# simple_shell
In this repository you will find the entire project where we built our own version of a Shell, when you clone this to your shell . Originally created for learning purposes in the Holberton School, Barranquilla campus - cohort 13.

By learning how the shell works you will be able to understand how some of the CLI works, how do they receive instructions, how do they read the instructions, how do they interpret and create a process according to the instruction given and of course, since this is a project built in C language, we need to handle carefully the memory, so we will have enough memory to run the process we want or if that's the case, print an error among others managements. We hope this to be useful and clear for any who is in this same path on learning and becoming to be a great software developer.

# How to use it
- Clone this repo into your VM or OS with https://github.com/andresgfranco/simple_shell
- Compiler to use: GCC version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04.4)
- Command to compile: gcc -Wall -Werror -Wextra -pedantic *.c header_minishell.h -o hsh
- Run: ./hsh

# Files in this repository
- README.md
- mini_shell.c: main file and function where we will have an infinite loop to receive a command.
- header_minishel.h: unique header for the entire project containing libraries, function prototypes and macro delimitators
- _functions1.c: first set of 4 functions used
- _function2.c: second set of 5 instructions used
- _functions3.c: third set of 5 instructions used
- _functions4.c: fourth set of 5 instructions used
- _error.c: file containing function to handle errors
# Functions used in this repository
- isatty
- write
- getline
- free
- exit
## Our own functions
- _getenv - function to print the environment variable
- tokenize - function to tokenize the command given
- _strlen - returns the lenght of a string
- execution - function that will copy the coincidence in the path to execute it in other function
- _strcpy - copies the string pointed to by src, to the buffer
- free_grid - function to free an array memory
- word_len - function to count number of letters of each word
- count_words - function to count number of words
- _puts - prints a string
- _putchar - writes the character c to stdout
- _strcat - function to concatenate strings
- _strstr - function to find a string within another string
- _strcmp - compares two strings
- execucion2: function that will create a child process and execute the command already found

# Flowchart
- 
# Authors
- Andres Campo Serna - http://twitter.com/campoandres98
- Andres Gonzalez Franco - http://twitter.com/andresgfranco
