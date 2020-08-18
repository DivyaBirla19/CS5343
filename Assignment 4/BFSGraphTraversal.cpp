/**************************************************************************************
* Course: CS 5343.502 – Spring 2020
* Assignment <4>
* Name: Divya Birla
* E-mail: dxb190021@utdallas.edu
* Submitted: <03/31/20>
	This program performs BFS traversal on an undirected, disconnected graph having 15 vertices and 25 edges.

/****************************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// Creating the graph using adjacency list
vector< vector<int> > CreateGraphAdjList()
{

	vector< vector<int> > adjList;
	// To create adjacency list size
	const int n = 15;

	for (int i = 0; i < n; i++)
	{
		// intialising list with vertices
		vector<int> list;
		adjList.push_back(list);
	}
	//Adding edges using 2D vector
	// adding edges incident on vertex 0
	adjList[0].push_back(1);
	adjList[0].push_back(3);
	// adding edges incident on vertex 1
	adjList[1].push_back(0);
	adjList[1].push_back(2);
	adjList[1].push_back(4);
	// adding edges incident on vertex 2
	adjList[2].push_back(1);
	adjList[2].push_back(4);
	adjList[2].push_back(5);
	// adding edges incident on vertex 3
	adjList[3].push_back(0);
	adjList[3].push_back(4);
	adjList[3].push_back(5);
	// adding edges incident on vertex 4
	adjList[4].push_back(1);
	adjList[4].push_back(2);
	adjList[4].push_back(3);
	adjList[4].push_back(5);
	// adding edges incident on vertex 5
	adjList[5].push_back(2);
	adjList[5].push_back(3);
	adjList[5].push_back(4);
	// adding edges incident on vertex 6
	adjList[6].push_back(7);
	adjList[6].push_back(9);
	adjList[6].push_back(11);
	// adding edges incident on vertex 7
	adjList[7].push_back(6);
	adjList[7].push_back(8);
	adjList[7].push_back(9);
	// adding edges incident on vertex 8
	adjList[8].push_back(7);
	adjList[8].push_back(11);
	adjList[8].push_back(12);
	// adding edges incident on vertex 9
	adjList[9].push_back(6);
	adjList[9].push_back(7);
	adjList[9].push_back(10);
	adjList[9].push_back(11);
	// adding edges incident on vertex 10
	adjList[10].push_back(9);
	adjList[10].push_back(11);
	adjList[10].push_back(14);
	// adding edges incident on vertex 11
	adjList[11].push_back(6);
	adjList[11].push_back(8);
	adjList[11].push_back(9);
	adjList[11].push_back(10);
	adjList[11].push_back(12);
	// adding edges incident on vertex 12
	adjList[12].push_back(8);
	adjList[12].push_back(11);
	adjList[12].push_back(13);
	adjList[12].push_back(14);
	// adding edges incident on vertex 13
	adjList[13].push_back(12);
	adjList[13].push_back(14);
	// adding edges incident on vertex 14
	adjList[14].push_back(10);
	adjList[14].push_back(11);
	adjList[14].push_back(12);
	adjList[14].push_back(13);
	return adjList;
}

//Function for BFS traversal
void AdjListBFS(vector< vector<int> > adjList)
{
	int n = adjList.size();
	//Array to keep track of visited nodes	
	bool visited[15] = { false };
	//Queue to push and pop elements visited and processed  in BFS traversal
	queue<int> q;
	for (int j = 0; j < n; j++) {
		//To check if vertex has been visited
		if (visited[j] == false) {
			q.push(j);
			visited[j] = true;
			while (q.empty() == false)
			{
				int vertex = q.front();
				q.pop();
				cout << vertex << " ";

				for (int i = 0; i < adjList[vertex].size(); i++)
				{
					int adjNode = adjList[vertex][i];
					if (visited[adjNode] == false)
					{
						q.push(adjNode);
						visited[adjNode] = true;
					}
				}
			}

		}
	}
	cout << endl << endl;
}

int main()
{
	cout << "\n--PROGRAM TO PERFORM BFS TRAVERSAL FOR UNIDRECTED DISCONNECTED GRAPH--\n";
	vector< vector<int> > adjList = CreateGraphAdjList();
	cout << "\n BFS for the graph is as follows:" << endl;
	cout << "\n ";
	AdjListBFS(adjList);
	system("pause");
	return 0;
}
