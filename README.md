# Binary-Search-Tree-with-BFS-Traversal
This C program implements a binary search tree and performs a breadth-first search (BFS) traversal of the tree. The program allows the user to insert a set of integers into the tree, and then prints the nodes of the tree in BFS order.

Installation
To compile and run the program, you will need a C compiler such as gcc, as well as the standard C libraries. You can install these on Ubuntu by running:

~~~
Copy code
sudo apt-get update
sudo apt-get install build-essential
~~~
Once you have the necessary dependencies, you can compile the program by running:

~~~
gcc -o bst bst.c
~~~
This will create an executable file called "bst" in the current directory.

# Usage
To run the program, simply execute the "bst" file and provide a list of integers to insert into the tree. For example:


~~~
./bst
5
3
7
2
4
6
8
~~~
This will create a binary search tree with the following structure:
~~~
    5
   / \
  3   7
 / \ / \
2  4 6  8
~~~
The program will then print the nodes of the tree in BFS order:

~~~
5 3 7 2 4 6 8
~~~~
Finally, the program will delete the tree and exit.

# Contributing
If you find a bug or want to suggest an improvement, feel free to open an issue or submit a pull request. We welcome contributions from the community!
