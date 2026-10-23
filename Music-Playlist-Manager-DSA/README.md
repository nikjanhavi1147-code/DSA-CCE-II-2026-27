Music Playlist Manager Using Doubly Linked List

DSA CCE-2 Case Study | Academic Year 2026–27

1. Project Information

- Project Title: Music Playlist Manager
- Subject: Data Structures and Algorithms (DSA)
- Course: S.Y. B.Tech – Electronics and Computer Engineering
- Semester: III
- Institute: Amrutvahini College of Engineering, Sangamner
- Programming Language: C++
- Data Structure: Doubly Linked List
- IDE: Visual Studio Code
- Version Control: Git and GitHub

2. Introduction

The Music Playlist Manager is a menu-driven C++ application that manages songs using a Doubly Linked List.

Each node stores the song title, artist name, a pointer to the previous song, and a pointer to the next song.

The application allows users to add and delete songs, display the playlist in forward and reverse order, play the current song, navigate to the next or previous song, play the complete playlist, and repeat all songs.

This project demonstrates the practical use of linked lists and pointer manipulation in a music player application.

3. Objectives

- To understand the concept of a Doubly Linked List.
- To implement insertion and deletion of nodes.
- To perform forward and reverse traversal.
- To implement next and previous song navigation.
- To manage the currently selected song using a pointer.
- To implement complete playlist playback and Repeat All.
- To test the program under different conditions.
- To maintain source code and project documentation using GitHub.

4. Technologies Used

Technology| Purpose
C++| Programming language
Doubly Linked List| Storing and managing songs
Pointers| Connecting and navigating between nodes
Visual Studio Code| Writing and testing the program
Git| Tracking code changes
GitHub| Hosting the project repository


5. Data Structure Used

Doubly Linked List

A Doubly Linked List is a linear data structure in which each node contains data and two pointers.

- "prev": Points to the previous node.
- "next": Points to the next node.

In this project, each node represents one song.

Node Structure

Each node contains:

- Song title
- Artist name
- Pointer to the previous song
- Pointer to the next song

Example Diagram

head
 |
 v
NULL <- [Believer] <-> [Faded] <-> [Perfect] <-> [Shape of You] -> NULL
          prev/next links connect the songs in both directions

Each node can be traversed forward using "next" and backward using "prev".


6. Pointers Used

Pointer| Purpose
"p"| Points to a newly created node or the node to be deleted
"q"| Used to traverse the linked list
"head"| Points to the first song in the playlist
"current"| Points to the currently selected or playing song
"prev"| Points to the previous song
"next"| Points to the next song

Next Song Navigation

current = current->next;

This moves the current pointer to the next song.

Previous Song Navigation

current = current->prev;

This moves the current pointer to the previous song.


7. Features of the Project

The program provides the following menu options:

1. Add Song
2. Delete Song
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit

Description of Features

1. Add Song: Adds a new song at the end of the playlist.

2. Delete Song: Deletes a song by its title and reconnects the remaining nodes.

3. Display Playlist: Displays songs from the first song to the last song.

4. Display Playlist in Reverse: Displays songs from the last song to the first song.

5. Play Current Song: Displays the currently selected song.

6. Play Next Song: Moves the current pointer to the next song.

7. Play Previous Song: Moves the current pointer to the previous song.

8. Play Complete Playlist: Displays all songs in their playlist order.

9. Repeat All: Displays the complete playlist for the specified number of repetitions.

10. Show Current Song: Displays the currently selected song.

11. Exit: Terminates the program.

Note: This is a console-based demonstration. It displays playback messages rather than playing actual audio files.


8. Sample Songs

The program initially contains four sample songs:

No.| Song Title| Artist
1| Believer| Imagine Dragons
2| Faded| Alan Walker
3| Perfect| Ed Sheeran
4| Shape of You| Ed Sheeran

Users can add more songs through the menu.

Initial Playlist

head
 |
 v
[Believer] <-> [Faded] <-> [Perfect] <-> [Shape of You]
     ^
   current

Initially, "head" and "current" point to the first song, Believer.


9. Pointer Operations

A. Insertion

When a new song is added, a new node is created and connected to the last node.

Example: Adding "Levitating".

Before insertion:

[Believer] <-> [Faded] <-> [Perfect]

After insertion:

[Believer] <-> [Faded] <-> [Perfect] <-> [Levitating]

The "next" pointer of the previous last node and the "prev" pointer of the new node are updated.

B. Deletion

When a song is deleted, the previous and next nodes are connected to each other.

Before deletion:

[Believer] <-> [Faded] <-> [Perfect]

After deleting Faded:

[Believer] <----------------> [Perfect]

The node containing Faded is removed from the linked list.

C. Next Navigation

Suppose the current song is Believer.

[Believer] <-> [Faded] <-> [Perfect]
     ^
   current

After executing:

current = current->next;

The current song becomes Faded.

D. Previous Navigation

Suppose the current song is Perfect.

[Believer] <-> [Faded] <-> [Perfect]
                              ^
                            current

After executing:

current = current->prev;

The current song becomes Faded.

E. Reverse Traversal

The program first traverses to the last node and then follows the "prev" pointer.

Shape of You -> Perfect -> Faded -> Believer

F. Boundary Conditions

- If the playlist is empty, song operations display an appropriate message.
- If the current song is the first song, Previous cannot move farther backward.
- If the current song is the last song, Next cannot move farther forward.
- If a song does not exist, deletion displays a message.
- If the only song is deleted, both "head" and "current" become "nullptr".


10. How to Compile and Run

Requirements

- A C++ compiler such as GCC.
- Visual Studio Code.
- The C++ source file "Music_Playlist_Manager.cpp".

Compilation

Open the VS Code terminal in the project folder and execute:

g++ Music_Playlist_Manager.cpp -o Music_Playlist_Manager

Run on Windows

.\Music_Playlist_Manager

Run on Linux

./Music_Playlist_Manager

After running the program, select an option from the menu and press Enter.


11. Testing and Validation

The program should be tested with the following cases.

Test No.| Test Case| Expected Result
1| Display the initial playlist| All four sample songs are displayed
2| Add a new song| Song is added at the end
3| Delete the first song| First song is removed
4| Delete a middle song| Middle song is removed
5| Delete the last song| Last song is removed
6| Delete a nonexistent song| Song not found message is displayed
7| Play current song| Current song is displayed
8| Play next song| Current pointer moves forward
9| Play previous song| Current pointer moves backward
10| Move next from the last song| Boundary message is displayed
11| Move previous from the first song| Boundary message is displayed
12| Display reverse playlist| Songs are displayed in reverse order
13| Repeat the playlist| All songs are displayed for each repetition
14| Delete all songs| Playlist becomes empty
15| Operate on an empty playlist| Appropriate messages are displayed
16| Exit the program| Program terminates

Record the actual results after executing each test case in VS Code.


12. GitHub Repository

The source code and documentation are maintained in a GitHub repository.

Suggested Repository Structure

Music-Playlist-Manager-DSA/
|
|-- Music_Playlist_Manager.cpp
|-- README.md
|
|-- diagrams/
|   |-- initial_playlist.png
|   |-- insertion.png
|   |-- deletion.png
|   |-- next_navigation.png
|   |-- previous_navigation.png
|   |-- reverse_traversal.png
|   |-- boundary_case.png
|
|-- test_cases/
    |-- testing_results.md

The diagram and test files should be added as they are prepared.

Suggested Git Commit Messages

Initial project setup

Implemented song insertion and display

Implemented song deletion

Implemented next and previous navigation

Implemented reverse traversal and Repeat All

Added diagrams and testing documentation

Commit messages should describe the changes actually made in each commit.


13. Advantages

- Supports movement in both directions.
- Makes insertion and deletion possible through pointer manipulation.
- Maintains the order of songs.
- Uses dynamic memory allocation for nodes.
- Demonstrates an important linear data structure.
- Provides a menu-driven interface that is easy to test.

14. Limitations

- The program runs in the console.
- It displays playback messages instead of playing actual audio.
- Songs are stored in memory and are not saved permanently.
- The playlist is lost when the program terminates.

15. Future Enhancements

- Add actual audio playback.
- Save playlist data in a file or database.
- Develop a graphical user interface.
- Add search functionality.
- Add song duration and album information.
- Implement shuffle playback.

16. Conclusion

The Music Playlist Manager demonstrates the implementation of a Doubly Linked List using C++. Each node stores song information and maintains links to the previous and next nodes. The program supports insertion, deletion, forward and reverse traversal, current-song management, and bidirectional navigation. Testing the program helps verify pointer operations and boundary conditions. This project provides practical understanding of Doubly Linked Lists and their applications in music playlist management.