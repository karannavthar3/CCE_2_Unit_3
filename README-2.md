# Yes/No Quiz Application Using a Binary Tree

## Project Overview

The Yes/No Quiz Application Using a Binary Tree is a simple C++ project that manages quiz questions and answers using a binary tree data structure.

In a binary tree, each node can have at most two child nodes. In this project, internal nodes represent Yes/No questions, and leaf nodes represent the final answers or results. The application allows users to answer questions and reach a final result by following the appropriate branches of the tree.

## Objectives

- To understand the concept of a binary tree.
- To represent quiz questions and answers using a binary tree.
- To allow users to answer Yes/No questions.
- To implement recursive preorder traversal.
- To implement recursive inorder traversal.
- To implement recursive postorder traversal.
- To calculate the number of leaf nodes.
- To calculate the number of internal nodes.
- To calculate the height of the binary tree.

## Technologies Used

- **Programming Language:** C++
- **Data Structure:** Binary Tree
- **Concepts:** Recursion and Tree Traversal
- **Compiler:** Any standard C++ compiler

## Features

- **Start Quiz:** Allows users to answer a series of Yes/No questions.
- **Binary Tree Representation:** Stores questions and answers in a binary tree.
- **Preorder Traversal:** Displays the nodes in Root-Left-Right order.
- **Inorder Traversal:** Displays the nodes in Left-Root-Right order.
- **Postorder Traversal:** Displays the nodes in Left-Right-Root order.
- **Count Leaf Nodes:** Calculates the total number of leaf nodes in the tree.
- **Count Internal Nodes:** Calculates the total number of internal nodes in the tree.
- **Calculate Tree Height:** Determines the height of the binary tree.
- **Display Results:** Displays the final quiz result and tree statistics.

## Data Structure Used

A **Binary Tree** is a hierarchical data structure in which each node can have at most two children: a left child and a right child.

Each node contains:

- **Question or Answer:** Stores a Yes/No question or a final result.
- **Left Pointer:** Stores the address of the left child node, representing the Yes branch.
- **Right Pointer:** Stores the address of the right child node, representing the No branch.

### Types of Nodes

- **Internal Node:** A node that contains a question and has child nodes.
- **Leaf Node:** A node that contains a final answer or result and has no children.

## How the Program Works

1. The program creates a binary tree containing questions and answers.
2. The program displays a menu containing different operations.
3. The user selects the Start Quiz option.
4. The program displays a Yes/No question.
5. The user enters Yes or No as an answer.
6. The program follows the corresponding branch of the binary tree based on the user's response.
7. The process continues until a leaf node is reached.
8. The program displays the final quiz result.
9. The user can select preorder, inorder, or postorder traversal to display the nodes of the binary tree.
10. The program calculates and displays the total number of leaf nodes.
11. The program calculates and displays the total number of internal nodes.
12. The program calculates and displays the height of the binary tree.
13. The program continues until the user selects the Exit option.

## Conclusion

The Yes/No Quiz Application Using a Binary Tree successfully demonstrates the implementation of a binary tree in C++. It provides a simple way to manage quiz questions and answers using a hierarchical structure. The project allows users to answer Yes/No questions and obtain a final result by following the appropriate branches of the tree.

It also demonstrates recursive tree traversals and the calculation of leaf nodes, internal nodes, and tree height. Through this project, we gain practical knowledge of binary trees, pointers, recursion, and tree traversal techniques. This project helps us understand how binary trees can be used in quiz applications, decision-making systems, and other interactive programs.
