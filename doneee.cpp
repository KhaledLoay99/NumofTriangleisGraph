// ConsoleApplication22.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
using namespace std;

#define V 4





struct Node {
	int x, y;

};
struct triangle {
	Node * node1;
	Node *node2;
	Node *node3;
	int area;
	int id;
};

int countTriangle(int graph[V][V],
	bool isDirected,Node a[V],triangle t[V])
{

	int are;
	int count_Triangle = 0;
	int count = 0;
	int id = 1;

	
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{

				if (graph[i][j] && graph[j][k]
					&& graph[k][i]) {
					count_Triangle++;

					are = a[i].x*(a[j].y - a[k].y) + a[j].x*(a[k].y - a[i].y) + a[k].x*(a[i].y - a[j].y) / 2;
					if (are > 0) {
						cout << "the area of triangle is: " << are << endl;
						t[count].node1 = &a[i];
						t[count].node2 = &a[j];
						t[count].node3 = &a[k];
						t[count].id = id;
						t[count].area = are;
						count++;
						id++;
					}

				}
			}
		}
	}


	if (isDirected)
		count_Triangle /= 3;
	else
		count_Triangle /= 6;

	return count_Triangle;
}



int main()
{
	Node *Nodes = new Node[V];
	triangle *tri = new triangle[V];


	for (int i = 0; i < V; i++) {
		cout << "enter x and y for the Node number -> "<<i<< endl;
		cin >> Nodes[i].x >> Nodes[i].y;
	}
	
		
	int graph[V][V];
	int ungraph[V][V];

	cout << "enter you want it directed  press 1 or undirected press 2" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		cout << "enter the  matrix value directed" << endl;

		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cin >> graph[i][j];
			}
		}
		cout << "The Number of triangles in directed graph : "<< countTriangle(graph, true, Nodes, tri);
	}
	else {
		cout << "enter the  matrix value undirected" << endl;

		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V ; j++) {
				cin >> ungraph[i][j];
				
			}

		}
		cout << "The Number of triangles in undirected graph : "<< countTriangle(ungraph, false, Nodes, tri);

	}
	
	
	
	
	cout << endl;
	cout << "search with id enter id:" << endl;
	int searchid;
	cin >> searchid;
	for (int i = 0; i < V; i++) {

		if (searchid = tri[i].id) {
			cout <<"the area is:"<< tri[i].area;
			break;
		}
	}
	




	return 0;
}