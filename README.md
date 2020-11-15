# **simple shell**

Simple shell is a program that takes input from the user to perform a
series of actions on the data.

```
./hsh

prompt$ (user input goes here)

```

## *shell.c*

Contains the main function, and runs the main "ifinite" loops
that waits for user input using getline.

## *_getenv.c*

Retrievs the desired environmental variable from the system.

## *path_tok.c*

Take the variable, specifically the PATH, from \_getenv and tokenizes
it.

## *search_dir.c*

Searches the directory tokens, created by path\_tok, for the commands
entered by the user.

## *add_node.c*

Helper function that takes the tokens of an environment variable and
turns them into singly linked list.

## *print_list.c*

Function that won't stay, but helps us see that the env variable is
correclty parsed and turned into a linked list.

## *free_list.c*

Helper function that frees the memory allocted to the singly linked list
when the shell is terminated by the user.

## *string_helpers.c*

Various functions that act on char strings.
