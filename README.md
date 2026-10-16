# Music Playlist Using Circular Linked List

## Project Overview
The Music Playlist Using Circular Linked List is a simple C++ project that manages songs using a circular linked list data structure.

In a circular linked list, the last node points back to the first node. This allows songs to be played continuously in a loop.

## Objectives
- To understand the concept of a circular linked list.
- To add songs to a music playlist.
- To display all songs in the playlist.
- To play the next song.
- To understand circular traversal in a linked list.

## Technologies Used
- Programming Language: C++
- Data Structure: Circular Linked List
- Compiler: Any standard C++ compiler

## Features
1. Add Song: Adds a new song to the playlist.
2. Display Playlist: Displays all songs in the playlist.
3. Play Next Song: Moves to the next song.
4. Circular Playback: After the last song, playback returns to the first song.
5. Exit: Closes the program.

## Data Structure Used
A Circular Linked List is a linked list in which the last node points to the first node instead of NULL.

Each node contains:
- Song Name: Stores the name of the song.
- Next Pointer: Stores the address of the next node.

## How the Program Works
1. The program displays a menu.
2. The user selects an operation.
3. The user can add songs to the playlist.
4. The playlist can be displayed.
5. The user can play the next song.
6. After the last song, playback returns to the first song.
7. The program continues until the user selects Exit.

## Sample Output

--- Music Playlist ---
1. Add Song
2. Display Playlist
3. Play Next Song
4. Exit

Enter your choice: 1
Enter song name: Believer
Song added successfully!

Enter your choice: 1
Enter song name: Shape of You
Song added successfully!

Enter your choice: 2

Music Playlist:
Believer
Shape of You

Enter your choice: 3
Now Playing: Shape of You

## Advantages
- Songs can be played continuously in a loop.
- Dynamic memory allocation is used.
- Songs can be added without a fixed-size array.
- It demonstrates circular linked list operations.

## Applications
- Music player applications.
- Playlist management systems.
- Repeating task management.
- Circular navigation systems.

## Conclusion
This project demonstrates how a circular linked list can be used to manage a music playlist. It helps us understand dynamic memory allocation, pointers, node creation, and circular traversal in C++.
