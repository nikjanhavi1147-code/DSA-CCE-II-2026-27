Social Network Connectivity Analyzer

1. Project Overview
The Social Network Connectivity Analyzer is a menu-driven application developed using C++. It is based on the concept of Graph Data Structures in Data Structures and Algorithms (DSA).

The project represents a social network in which each person is considered a vertex (node), and friendship between two people is represented by an edge.

It helps analyze relationships between people by providing features such as adding people, creating friendships, searching for people, finding mutual friends, finding the shortest connection path, and checking network connectivity.

The project uses an Adjacency Matrix to represent the graph and Breadth-First Search (BFS) to perform graph traversal and connectivity analysis.

2. Objectives
- To understand and implement graph data structures.
- To represent social relationships using an adjacency matrix.
- To add and remove friendships between people.
- To search for a particular person in the network.
- To identify mutual friends between two people.
- To find the shortest connection path between two people.
- To check whether the entire social network is connected.
- To understand the practical application of BFS.

3. Technologies Used
Technology	Description
Programming Language	C++
Data Structure	Graph
Graph Representation	Adjacency Matrix
Algorithm	Breadth-First Search (BFS)
IDE	Visual Studio Code
Compiler	GCC / MinGW

4. Features of the Project
The project provides the following functionalities:

1. Add Person

Allows users to add a new person to the social network. Duplicate names are not allowed.

2. Add Friendship

Allows users to establish a friendship between two existing people. Since friendship is mutual, connections are stored in both directions.

3. Display Network

Displays all people in the network along with their respective friends.

4. Search Person

Allows users to search for a particular person and display their friendship connections.

5. Find Mutual Friends

Identifies common friends between two selected people.

6. Find Connection Path

Finds the shortest path between two people using the BFS algorithm. It also displays the number of hops required to connect them.

7. Check Network Connectivity

Checks whether all people in the social network are connected directly or indirectly.

8. Remove Friendship

Allows users to remove an existing friendship between two people.

9. Exit

Terminates the program.

5. Data Structures Used
A. Graph
A graph is a non-linear data structure consisting of vertices and edges.

In this project:
- Vertices represent people.
- Edges represent friendships.
- The graph is undirected because friendships are mutual.
B. Adjacency Matrix
An adjacency matrix is a two-dimensional array used to represent connections between vertices.

In this project, the matrix is declared as:
int adj[MAX][MAX];


- 1 indicates that two people are friends.
- 0 indicates that no friendship exists.
For example:
Person	A	B	C
A	0	1	0
B	1	0	1
C	0	1	0

Here, A is friends with B, and B is friends with C.
C. Queue
A queue follows the FIFO (First In, First Out) principle. It is used in BFS to process vertices level by level.
D. Visited Array
The visited array keeps track of already visited people and prevents repeated traversal.
E. Parent Array
The parent array stores the previous vertex during BFS traversal. It is used to reconstruct the shortest connection path.

6. Algorithm Used
Breadth-First Search (BFS)
Breadth-First Search is a graph traversal algorithm that explores vertices level by level.

Steps:
1. Start from the source person.
2. Mark the source as visited.
3. Insert the source into the queue.
4. Remove the front element from the queue.
5. Visit all its unvisited friends.
6. Mark those friends as visited and insert them into the queue.
7. Repeat until the queue becomes empty or the destination is found.
Applications in this project:
- Finding the shortest connection path.
- Checking whether the social network is connected.

7. Working of the Project
The project follows these steps:
1. The program starts by creating an empty social network.
2. The user selects an operation from the menu.
3. New people can be added to the network.
4. Friendships can be established between existing people.
5. The adjacency matrix stores all friendship connections.
6. Users can search for people and find mutual friends.
7. BFS is used to find the shortest connection path.
8. Network connectivity is checked using graph traversal.
9. The program continues until the user selects the Exit option.

8. Project Menu
===== Social Network Connectivity Analyzer =====

1. Add Person
2. Add Friendship
3. Display Network
4. Search Person
5. Find Mutual Friends
6. Find Connection Path
7. Check Network Connectivity
8. Remove Friendship
9. Exit

Enter choice:

9. Sample Output
Example: Adding People
Enter name: Asha
Asha added successfully.

Enter name: Riya
Riya added successfully.

Enter name: Neha
Neha added successfully.

Example: Adding Friendships
Enter two names: Asha Riya
Friendship added between Asha and Riya.

Enter two names: Riya Neha
Friendship added between Riya and Neha.

Example: Display Network
Asha -> Riya
Riya -> Asha Neha
Neha -> Riya


Example: Find Connection Path
Enter source and destination: Asha Neha

Shortest path: Asha -> Riya -> Neha (2 hops)


Example: Check Network Connectivity
Network is fully connected.

10. Advantages
- Simple and easy-to-use menu-driven interface.
- Efficient representation of friendship relationships.
- Helps identify mutual friends.
- Finds the shortest connection path between people.
- Demonstrates practical applications of graph algorithms.
- Helps understand BFS traversal and network connectivity.

11. Limitations
- The network supports a maximum of 50 people.
- Names are limited to 29 characters.
- Names containing spaces are not supported.
- Data is not stored permanently.
- The application uses a fixed-size adjacency matrix.

12. Future Enhancements
- Implement permanent data storage using file handling or a database.
- Allow users to enter names containing spaces.
- Add functionality to delete a person from the network.
- Provide graphical visualization of the social network.
- Add user profiles and profile information.
- Implement additional graph algorithms for advanced network analysis.

13. Conclusion
The Social Network Connectivity Analyzer successfully demonstrates the implementation of graph data structures using C++. The project uses an adjacency matrix to represent friendship relationships and BFS to find the shortest connection path and check network connectivity.

It provides practical understanding of important DSA concepts such as graphs, adjacency matrices, queues, and graph traversal algorithms.

Through this project, we learn how graph algorithms can be applied to real-world applications such as social networking platforms, communication networks, and relationship analysis.