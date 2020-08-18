BFS and DFS Graph Traversal for an undirected, disconnected graph

Files included:

DFSGraphTraversal.cpp		-conatins the source code fro DFS traversal
DFSGraphTraversal.exe		-executable file for DFS traversal code
BFSGraphTraversal.cpp	 	-conatins the source code fro BFS traversal
DFSGraphTraversal.exe		-executable file for BFS traversal code
Assignment4.docx		-Word file with question, source code, screenshot of execution and hand drawn tree 						  traversals


The program intialises a 2D vector as an adjacency list with 15 vertices and 25 edges.Function CreateGraphAdjList initialises the graph edges. The adjacency list is passed to the AdjListBFS function to perform BFS traversal of the graph.
For DFS traversal DFSStartVertexSearch function is used to find the vertex to start traversal. For each unvisited node, traversal is carried out using AdjListDFS function.