/**************************************************************************************
* Course: CS 5343.502 – Spring 2020
* Assignment <5>
* Name: Divya Birla
* E-mail: dxb190021@utdallas.edu
* Submitted: <04/23/20>
	This program performs DFS topological sort on two graphs.
	Graph 1, having 14 vertices and 21 edges, is Directed Acyclic Graph.
	Graph 2, having 8 vertices and 14 edges, is a Directed Cyclic Graph.

/****************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include<stack>

using namespace std;

// Creating the graph 1 using adjacency list
vector< vector<int> > CreateGraphAdjList()
{

	vector< vector<int> > adjList;
	// To create adjacency list size
	const int n = 14;

	for (int i = 0; i < n; i++)
	{
		// intialising list with vertices
		vector<int> list;
		adjList.push_back(list);
	}

	//Adding edges using 2D vector
// adding edges directed out of vertex 0
	adjList[0].push_back(4);
	adjList[0].push_back(5);
	adjList[0].push_back(11);
	
	// adding edges directed out of vertex 1
	adjList[1].push_back(2);
	adjList[1].push_back(4);
	adjList[1].push_back(8);

	// adding edges directed out of vertex 2
	adjList[2].push_back(5);
	adjList[2].push_back(6);
	adjList[2].push_back(9);
	// adding edges directed out of vertex 3
	adjList[3].push_back(2);
	adjList[3].push_back(6);
	adjList[3].push_back(13);
	// adding edges directed out of vertex 4
	adjList[4].push_back(7);
	
	// adding edges directed out of vertex 5
	adjList[5].push_back(8);
	adjList[5].push_back(12);
	// adding edges directed out of vertex 6
	adjList[6].push_back(5);
	// adding edges directed out of vertex 8
	adjList[8].push_back(7);
	// adding edges directed out of vertex 9
	adjList[9].push_back(10);
	adjList[9].push_back(11);
	// adding edges directed out of vertex 10
	adjList[10].push_back(13);
	// adding edges directed out of vertex 12
	adjList[12].push_back(9);

	return adjList;
}
// Creating the graph 2 using adjacency list
vector< vector<int> > CreateGraphAdjList2() {
	vector< vector<int>> adjList2;
	// To create adjacency list size
	const int n = 8;
	// intialising list with vertices
	for (int i = 1; i < n; i++) {
		vector<int> list;
		adjList2.push_back(list);
	}
	// adding edges directed out of vertex 1 of Graph 2
	adjList2[0].push_back(1);
	adjList2[0].push_back(4);
	adjList2[0].push_back(5);
	// adding edges directed out of vertex 2 of Graph 2
	adjList2[1].push_back(2);
	adjList2[1].push_back(4);
	adjList2[1].push_back(6);
	// adding edges directed out of vertex 3 of Graph 2
	adjList2[2].push_back(3);
	// adding edges directed out of vertex 4 of Graph 2
	adjList2[3].push_back(4);
	// adding edges directed out of vertex 5 of Graph 2
	adjList2[4].push_back(6);
	adjList2[4].push_back(7);
	// adding edges directed out of vertex 6 of Graph 2
	adjList2[5].push_back(4);
	adjList2[5].push_back(7);
	// adding edges directed out of vertex 7 of Graph 2
	adjList2[6].push_back(3);
	adjList2[6].push_back(7);
	return adjList2;
}


//To carry out DFS topological sorting on Graphs
void DFSTopoSortUtil(vector<vector<int>> adjList, int vertex, bool visited[],bool cyclic[],stack<int> &s, bool &cycle) {
	visited[vertex] = true;
	cyclic[vertex] = true;
	for (int i = 0; i < adjList[vertex].size(); i++) {
		int adjNode = adjList[vertex][i];
		if (visited[adjNode] == false)
			DFSTopoSortUtil(adjList, adjNode, visited,cyclic,s,cycle);
		else
			if (cyclic[adjNode] == true)
				cycle = true;
	}
	cyclic[vertex] = false;
	s.push(vertex+1);


}
bool DFSTopoSort(vector<vector<int>> &adjList, int n) {
	bool cycle = false;
	stack<int> s;
	bool* visited= new bool[n];
	bool* cyclic = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		cyclic[i] = false;
	}
	
	
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			DFSTopoSortUtil(adjList, i, visited,cyclic,s,cycle);
		}
			
	}
	//To print sorted list if there is no cycle
	if (cycle == false) {
		while (s.empty() == false) {
			if (n == 14) {
			
				cout << (char)(s.top() + 108)<<" ";//To print sorted list as alphabets
				s.pop();

			}
			else {
				cout << s.top() << " ";
				s.pop();
			}
		}
		return true;
	}
	else 
		return false;

}

int main()
{
	cout << "\n--PROGRAM TO PERFORM DFS TOPOLOGICAL SORT--\n";
	vector< vector<int> > adjList = CreateGraphAdjList();
	int n1 = adjList.size();
	cout << "\n Carrying out DFS Topological Sort for the graph 1:" << endl;
	cout << "\n ";
	if(DFSTopoSort(adjList, n1))
	{
		cout << "\n ";
	}
	else {
		cout << "\n\n There is a cycle in the graph 1 " << endl;
	}
	cout << "\n Carrying out DFS Topological Sort for the graph 2:" << endl;
	vector< vector<int> > adjList2 = CreateGraphAdjList2();
	int n2 = adjList2.size();
	if (DFSTopoSort(adjList2, n2))
	{
		cout << "\n";

	}
	else {
		cout << "\n There is a cycle in the graph 2 \n\n";
	}
	system("pause");
	return 0;
}
