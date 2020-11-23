# **simple shell**

Simple shell is a program that takes input from the user to perform a
series of actions on the data. This shell also contains the built-ins "env" and "exit"

env - prints the environment on which the shell is running.

exit - cant either be entered by itself or with a status # from (0-250) and
exits the shell with the corresponding code.

```
./hsh

prompt$ (user input goes here)

(output is put on new line)

prompt$
```

## *shell.c*

Contains the main function, and runs the main "ifinite" loops
that waits for user input using getline.

The main also check for the builtins env and exit.

```
prompt$ env

XDG_SESSION_ID=3
TERM=xterm-256color
SHELL=/bin/bash
(whole env var not shown here)

prompt$ exit 103

$ echo ?$

$ 103
```

## *_getenv.c*

Creates a copy of the environment variable to search through for the desired section.

## *print_env.c*

Prints out the entire envorionmental variable. the "env" builtin.

## *_getpath.c*

Gets a copy of the PATH from the environment variable to be used to search for executables
enterd into the prompt by the user.

## *command_tok.c*

This takes the input from getline and parses it into tokens using strtok that can be fed
into execve.

## *path_tok.c*

Take the variable, specifically the PATH, from \_getenv and tokenizes
it.

## *search_dir.c*

Searches the directory tokens, created by path\_tok, for the commands
entered by the user. If the command is found to match one found in the path, it is
handed off to excecve to be run. It also sets the filepath using a helper function
set\_filepath that appens the command onto the full path where the command was found.

(the command ls is found is /bin)
```
prompt$ ls
```
When the command is entered search\_dir finds the command (or not)
and then sends "/bin/ls" to execve not just "ls" and then command\_tok
handles any modifiers entered alongside ls.

```
prompt$ ls -1 -a -l
```
-1 = list one entry per line.\
-a = list all contents of directory, including hiddens ones.\
-l = list the long version of each entry

## *add_node.c*

Helper function that takes the tokens of an environment variable (in our case it is
the PATH) and turns it into singly linked list. This is so we can easily search through
the elements of the PATH for executables.

## *free_list.c*

Helper function that frees the memory allocted to the singly linked list
when the shell is terminated by the user.

## *string_helpers.c*

Various functions that act on char strings.

## *_atoi.c*

Takes input after finding exit in getline and turns it into and int. The "exit status" builtin.

## *free_space.c*

This is the last step of the shell when exiting. This function makes sure that all the memory
allocated throughout the shell has been freed.

## *shell.h*

header containing all function prototypes and singly linked list struct.

```
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */

typedef struct list_s
{
        char *str;
        unsigned int len;
        struct list_s *next;
} list_t;
```

