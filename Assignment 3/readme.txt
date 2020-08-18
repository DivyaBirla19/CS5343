PART 1
Build a heap using Floyds method 

Files included:

FloydsHeapsort.cpp 		-conatins the source code
FloydsHeapsort.exe		-executable file for the code
Assignment3.docx		-Word file with question, source code and screenshot of execution


The program intialises an array with 15 integers values. These integers are passed to the FloydsBuildHeap function to identify the last parent to be chosen for percolation down in order to make a min heap.A min heap is made since elements need to be sorted in descending order using heapsort.

PART2

The min heap contains the smallest element at the root node which is replaced with the leaf node and heapify is performed on the tree. The size of the array is decreased so that we dont consider the new replaced leaf node for the following iterations of replacement and heapify.
This helps us make the sorted descending order traversal in the same array.

Please find attached screenshots of the movement in array to obtain heap
1.Min heap creation for Floyd
2.Heapsort using the min heapify.

