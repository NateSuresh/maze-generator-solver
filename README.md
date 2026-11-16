# Maze Generator and Solver

This project is a maze generator and solver written in C.

The program creates a random maze, shows it in the terminal, and then solves it using depth-first search.

It also uses a linked list to help store the path while building and solving the maze.

## Features

- Generate a random maze
- Show the maze in the terminal
- Solve the maze automatically
- Use depth-first search
- Use a linked list as a stack
- Show the solving process using ncurses
- Generate a new maze after finishing

## Technologies and Concepts

- C
- Depth-First Search
- Linked Lists
- Stacks
- Dynamic Memory
- Pointers
- ncurses
- Makefile

## Project Files

- `maze.c` - Generates, displays, and solves the maze
- `list.c` - Contains the linked list functions
- `list.h` - Contains the linked list function declarations
- `Makefile` - Builds the program

## How It Works

The maze starts as a grid where every cell is closed off.

The program then uses depth-first search to move through the grid and remove walls to create a random maze.

While building the maze, a linked list is used like a stack to keep track of where the program has been.

After the maze is created, the program uses depth-first search again to find a path from the start to the end.

The solving process is shown in the terminal using ncurses.

## Linked List

The linked list can:

- Add items to the front
- Add items to the back
- Remove items from the front
- Remove items from the back
- Get the first item
- Get the last item
- Find an item
- Remove an item

The list is used as a stack while the maze is being created and solved.

## How to Run

Compile the project with:

```bash
make
```

Then run:

```bash
./maze
```

## What I Learned

This project helped me understand:

- Depth-first search
- Maze generation
- Maze solving
- Linked lists
- Stacks
- Dynamic memory
- Pointers
- How data structures can be used in a real program
- How to display something in the terminal using ncurses

The main thing I learned was how a linked list and depth-first search can work together to build and solve a maze.
